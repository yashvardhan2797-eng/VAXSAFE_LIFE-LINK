# VAXSAFE_LIFE-LINK
This is an AI based smart IOT vaccine monitoring system ,which sends alarm when the temperature fluctuates from the optimum ranger of the vaccine.
Vaxsafe:AI and Blockchain-Powered Vaccine cold chain Vaxsafe is end to end IOT solution design and monitor the safety and potency of vaccine during transport. it use esp32 edge Device for real time sensing. A Python backend AI to calculate shelf life decay,and a SHA-256 blockchain link to pervent data tempering.



HOW IT WORK :
             
             Sensing:- The esp32 monitor via DTH22 sensor.
             EDGE ALERT:- IF the temperature leave safe range,local led and buzzer trigger immediately.
             AI ANALYSIS:- DATA is sent to a FLASK SERVER Where AI logic calculate % potency of vaccine potency on base of thermal stress.
             BLOCKCHAIN LOGGING :- Every succefull updated hashed with pervious record hash, creating an immutable chain of custody.


HARDWARE SETUP : MICROCONTROLLER:- ESP32 SENSOR:- DHT22 INDICTORS:- 1* RED LED,1ACTIVE BUZZER,1GREEN LED PLATFORM:- BLYNK IOT CLOUD :                 

              | Component    | ESP32 Pin | Purpose                    
              | ------------ | --------- | -------------------------- |
              | DHT22 Sensor | GPIO 15   | Temperature/Humidity Input | 
              | Red LED      | GPIO 12   | Critical Alert Indicator   |
              | Green LED    | GPIO 14   | System Operations Normal   |
              | Buzzer       | GPIO 13   | Audible Alarm Trigger      |



SOFTWARE ARCHITECTURE:

  Potency Estimation Logic
          The backend includes a simple predictive model to estimate vaccine potency based on temperature exposure.
          Heat exposure: when the temperature rises above 8°C, potency decreases by 0.1% for every additional 1°C.
          Freezing exposure: if the temperature falls below 2°C, the system applies a 0.5% potency reduction.
          
          Heat Loss = (Temperature - 8) × 0.1%, when Temperature > 8°C
          Freeze Loss = 0.5%, when Temperature < 2°C


BLOCKCHAIN INTEGRITY

To make record tampering more difficult, the system links each log entry to the previous one using SHA-256 hash chaining.
                 
                 New Hash = SHA256(Temperature + Health Status + Timestamp + Previous Hash)
                 
This approach creates a connected sequence of records, so changing one entry would also affect the hashes that follow it.


PROJECT LAYOUT:

/backend/server.py: Handles the Flask-based server, AI-driven decay calculations, and blockchain hashing.

/firmware/vaxsafe_esp32.ino: ESP32 firmware in C++ for capturing sensor data and syncing with Blynk.

requirements.txt: Lists all Python dependencies.

Planned Enhancements

Smart Contracts: Shift hashing from local Python code to Solidity-based on-chain logic (on Ethereum or Polygon).

Deep Learning: Deploy LSTM models to forecast vaccine spoilage risks ahead of time.

GPS Tracking: Add real-time location monitoring for shipments during temperature violations.



*for the app to connect to the iot device


by default, this app reads from a local backend endpoint: /api/temperature. Your Flask server should return JSON like {"temperature": 4.7}. The alert changes automatically when the reading moves below -2°C or above 8°C.

              @app.route('/api/temperature')
              def get_temperature():
                  return jsonify({"temperature": current_temperature})



Author {YASHVARDHAN SINGH RAHOTRE} First year student , IOT $ smart monitoring 

