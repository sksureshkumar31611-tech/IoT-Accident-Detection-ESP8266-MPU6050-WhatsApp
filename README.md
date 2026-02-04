# 🚨 IoT Based Accident Detection System

An IoT based accident detection system using ESP8266, MPU6050 and WhatsApp API to send emergency alerts.
## 📌 Features
- Accident detection using MPU6050
- ESP8266 WiFi communication
- Automatic WhatsApp alert
- Node.js server with Twilio API
## 🛠️ Components Used
- ESP8266 (NodeMCU)
- MPU6050 Accelerometer
- WiFi Network
- Node.js Server
- Twilio WhatsApp API
## ⚙️ Working Principle
1. MPU6050 monitors acceleration continuously
2. Sudden acceleration change indicates accident
3. ESP8266 detects the accident
4. ESP8266 sends HTTP request to Node.js server
5. Node.js triggers WhatsApp alert using Twilio
## 📂 Project Structure
Arduino_Code/      → ESP8266 + MPU6050 code  
NodeJS_Server/     → WhatsApp server code  
Circuit_Diagram/   → Hardware connections  
Screenshots/       → Output screenshots  
## 🚀 How to Run

### Arduino Side
- Install required libraries
- Upload code to ESP8266

### Server Side
```bash
npm install
node index.js

---

###

```markdown
## 📲 Output
- Accident detected in Serial Monitor
- WhatsApp alert received instantly
## 👤 Author
SureshKumar
