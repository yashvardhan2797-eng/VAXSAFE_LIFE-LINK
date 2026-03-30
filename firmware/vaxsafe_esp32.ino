#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

// DHT22 Settings
#define DHTPIN 4       // DHT22 data pin
#define DHTTYPE DHT22  // DHT Type
DHT dht(DHTPIN, DHTTYPE);

// Blynk Settings
char auth[] = "Your-Blynk-Auth-Token";
const char* ssid = "Your-SSID";
const char* password = "Your-PASSWORD";

// GPIO Pins
#define GREEN_LED 32
#define RED_LED 33
#define BUZZER 25

void setup() {
    Serial.begin(115200);
    Blynk.begin(auth, ssid, password);
    dht.begin();
    pinMode(GREEN_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT);
    pinMode(BUZZER, OUTPUT);
}

void loop() {
    Blynk.run();
    // Read temperature and humidity
    float h = dht.readHumidity();
    float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

    // Check if any reads failed
    if (isnan(h) || isnan(t)) {
        Serial.println("Failed to read from DHT sensor!");
        return;
    }

    // Send the values to Blynk
    Blynk.virtualWrite(V0, h);
    Blynk.virtualWrite(V1, t);

    // GPIO Control Example
    if (t > 30) { // If temperature is above 30 degrees Celsius
        digitalWrite(RED_LED, HIGH);
        digitalWrite(GREEN_LED, LOW);
        digitalWrite(BUZZER, HIGH);
    } else {
        digitalWrite(RED_LED, LOW);
        digitalWrite(GREEN_LED, HIGH);
        digitalWrite(BUZZER, LOW);
    }

    delay(2000); // Wait before the next loop
}