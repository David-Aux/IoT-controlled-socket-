6.3 Arduino Code
// ====== Blynk identifiers (from blynk.cloud -> Device Info) ======
#define BLYNK_TEMPLATE_ID "TMPL2Nbo4rIQB"
#define BLYNK_TEMPLATE_NAME "ESP32 Relay"
#define BLYNK_AUTH_TOKEN "_QqvDeCapy42RD4Dzns7rWpU7nQy_Tc_"

// ====== Includes ======
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// ====== Your Wi-Fi ======
const char* ssid = "your hotspot device name";
const char* pass = "your hotspot password"; // your hotspot password

// ====== Hardware ======
#define RELAY_PIN 25 // your relay control pin (active LOW)
#define VPIN_RELAY V1 // matches the datastream you created

// When V1 changes in the app, this runs:
BLYNK_WRITE(VPIN_RELAY) {
  int v = param.asInt(); // 0 or 1
  digitalWrite(RELAY_PIN, v ? LOW : HIGH); // active-LOW relay module
}

// Sync last known state from cloud on connect
BLYNK_CONNECTED() {
  Blynk.syncVirtual(VPIN_RELAY);
}

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // OFF at boot (active LOW)
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass); // connects to blynk.cloud
}

void loop() {
  Blynk.run();
}
