#include <ESP8266WiFi.h>
#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

// ---------- WiFi ----------
const char* ssid = "IGL";
const char* password = "999555999";

// ---------- PC IP (Node.js running) ----------
const char* host = "192.168.222.34";
const int port = 3000;

// ---------- MPU6050 ----------
Adafruit_MPU6050 mpu;

// ---------- Accident settings ----------
float ACC_THRESHOLD = 18.0;   // adjust if needed
bool accidentSent = false;

void setup() {
  Serial.begin(9600);
  delay(1000);

  // I2C start
  Wire.begin(D2, D1);

  Serial.println("Initializing MPU6050...");
  if (!mpu.begin()) {
    Serial.println("❌ MPU6050 not found");
    while (1);
  }
  Serial.println("✅ MPU6050 connected");

  // WiFi connect
  Serial.println("Connecting WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\n✅ WiFi Connected");
  Serial.print("ESP IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  float ax = a.acceleration.x;
  float ay = a.acceleration.y;
  float az = a.acceleration.z;

  Serial.print("AX: "); Serial.print(ax);
  Serial.print(" AY: "); Serial.print(ay);
  Serial.print(" AZ: "); Serial.println(az);

  // Accident detection
  if ((abs(ax) > ACC_THRESHOLD ||
       abs(ay) > ACC_THRESHOLD ||
       abs(az) > ACC_THRESHOLD) && !accidentSent) {

    Serial.println("🚨 ACCIDENT DETECTED!");
    sendWhatsApp();
    accidentSent = true;   // send only once
  }

  delay(500);
}

void sendWhatsApp() {
  WiFiClient client;

  Serial.println("Connecting to Node server...");
  if (!client.connect(host, port)) {
    Serial.println("❌ Node connection failed");
    return;
  }

  client.print(String("GET /send HTTP/1.1\r\n") +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");

  Serial.println("📤 WhatsApp trigger sent");
}
