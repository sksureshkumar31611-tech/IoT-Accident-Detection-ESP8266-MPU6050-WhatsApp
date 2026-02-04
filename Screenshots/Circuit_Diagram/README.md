<🔌 Circuit Diagram – IoT Accident Detection System

This folder contains the circuit connection details for the IoT based Accident Detection System using ESP8266 and MPU6050.

---

## 🧩 Hardware Connections

### 📍 MPU6050 ↔ ESP8266 (NodeMCU)

| MPU6050 Pin | ESP8266 Pin |
|------------|------------|
| VCC        | 3.3V       |
| GND        | GND        |
| SDA        | D2 (GPIO4) |
| SCL        | D1 (GPIO5) |

---

## ⚠️ Important Notes
- Do **NOT** connect MPU6050 to 5V (may damage sensor)
- Use common GND for all components
- I2C communication is used between ESP8266 and MPU6050
- Short jumper wires recommended for stable I2C communication

---

## 📌 Description
The MPU6050 accelerometer continuously monitors acceleration values.  
ESP8266 reads this data using I2C protocol and detects sudden changes indicating an accident.

Once an accident is detected:
1. ESP8266 connects to WiFi
2. Sends HTTP request to Node.js server
3. Node.js server triggers WhatsApp alert using Twilio API

---

## 🖼️ Circuit Diagram Image<img width="1600" height="1016" alt="NodeMCU_MPU6050" src="https://github.com/user-attachments/assets/e72d1.		a)	Explain the Introduction and Design aspects of MEMS
	b)	Describe the Design and Introduction of NEMS
2.		a)	Explain the LIGA process and its role in high-aspect-ratio MEMS fabrication.
	b)	Discuss how sputtering and etching techniques contribute to micromachining processes in MEMS.


Important big question721c-da50-4316-8e6d-a5dc63caa69f" />

Add the circuit diagram image file in this folder with the name: NodeMCU_MPU6050

