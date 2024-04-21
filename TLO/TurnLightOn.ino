#include <WiFi.h>
#include <Picoalexa.h>

#define DEVICE_NAME ""
#define SSID        ""
#define PASSWORD    ""
#define LED         2
#define LIGHT       22
#define BUTTON      8

const char *ssid = SSID;
const char *pass = PASSWORD;

WiFiMulti wifi;
Picoalexa Picoalexa;

void TurnLightOn(uint8_t blightness) {
  if (blightness>0) {
    digitalWrite(LIGHT, HIGH);
  } else {
    digitalWrite(LIGHT, LOW);
  }
}

void setup() {
  pinMode(LED,   OUTPUT);
  pinMode(LIGHT, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  digitalWrite(LED, LOW);
  digitalWrite(LIGHT, LOW);
  
  wifi.addAP(ssid, pass);
  if (wifi.run() != WL_CONNECTED) {

    delay(5000);
    rp2040.reboot();
  }
  digitalWrite(LED, HIGH);

  Picoalexa.addDevice(DEVICE_NAME, TurnLightOn);
  Picoalexa.begin();
  // put your setup code here, to run onc
}

void loop() {
  Picoalexa.loop();
  if (digitalRead(BUTTON) == LOW) {
    digitalWrite(LIGHT, LOW);
  }
  delay(1);
  // put your main code here, to run repeatedly:

}
