#include <Wire.h>

const int MPU = 0x68;   // I2C address
int16_t AcX, AcY, AcZ;

void setup() {
  Wire.begin();
  Serial.begin(9600);

  Wire.beginTransmission(MPU);
  Wire.write(0x6B);     // Power management register
  Wire.write(0);       // Wake up MPU6050
  
  Wire.endTransmission(true);

  Serial.println("Accelerometer Test Started");
}

void loop() {
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);     // Starting register for Accel data
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 6, true);

  AcX = Wire.read() << 8 | Wire.read();
  AcY = Wire.read() << 8 | Wire.read();
  AcZ = Wire.read() << 8 | Wire.read();

  Serial.print("X = "); Serial.print(AcX);
  Serial.print(" | Y = "); Serial.print(AcY);
  Serial.print(" | Z = "); Serial.println(AcZ);

  delay(500);
}
