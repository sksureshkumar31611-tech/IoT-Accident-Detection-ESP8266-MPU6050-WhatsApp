const express = require("express");
const twilio = require("twilio");

const app = express();
app.use(express.json());

// Twilio credentials
const accountSid = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";//your accountSid
const authToken  = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"; // your authToken

const client = twilio(accountSid, authToken);

// Test route
app.get("/", (req, res) => {
  res.send("Twilio WhatsApp Server Running");
});

// Send WhatsApp message
app.get("/send", (req, res) => {
  client.messages
    .create({
      from: "whatsapp:+14xxxxxxxxxx",   // Twilio Sandbox
      to:   "whatsapp:+91xxxxxxxxxx",   // Your number
      body: "🚨 Accident Detected!\nVehicle stopped suddenly.\nPlease respond ASAP."
    })
    .then(message => {
      console.log("Message SID:", message.sid);
      res.send("WhatsApp message sent");
    })
    .catch(err => {
      console.log(err);
      res.status(500).send("Error sending message");
    });
});

// Start server
app.listen(3000, () => {
  console.log("Server running on http://localhost:3000");
});
