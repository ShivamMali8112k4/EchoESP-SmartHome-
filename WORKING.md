# ⚙️ How This Project Works  

## 🎯 Overview  
This project connects an **ESP8266** to Alexa via **Sinric Pro**, allowing voice control of **5 devices** (LEDs/Relays).  

## 🔗 How Sinric Pro Works  
1️⃣ ESP8266 **connects** to WiFi 🌍  
2️⃣ It **links** with Sinric Pro's cloud API ☁️  
3️⃣ Alexa sends **ON/OFF commands** 🎤  
4️⃣ ESP8266 **controls GPIO pins** accordingly 💡  

## ⚡ Circuit Connections  
| ESP8266 Pin | Device |
|------------|--------|
| D1 (GPIO5) | LED/Relay 1 |
| D2 (GPIO4) | LED/Relay 2 |
| D3 (GPIO0) | LED/Relay 3 |
| D4 (GPIO2) | LED/Relay 4 |
| D5 (GPIO14) | LED/Relay 5 |

## 🔥 Alexa Commands  
🗣️ **"Alexa, turn on Light 1"** → Turns on device 1  
🗣️ **"Alexa, turn off Fan 2"** → Turns off device 2  
🗣️ **"Alexa, turn on Relay 3"** → Turns on device 3  

💡 **You can rename devices in the Alexa app for easier commands!**  
