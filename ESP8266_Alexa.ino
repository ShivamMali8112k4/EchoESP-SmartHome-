#include <ESP8266WiFi.h>
#include <WebSocketsClient.h>
#include <SinricPro.h>
#include <SinricProSwitch.h>

#define WIFI_SSID "your_wifi_ssid"
#define WIFI_PASS "your_wifi_password"
#define APP_KEY "your_sinricpro_app_key"

#define DEVICE_1_ID "device_id_1"
#define DEVICE_2_ID "device_id_2"
#define DEVICE_3_ID "device_id_3"
#define DEVICE_4_ID "device_id_4"
#define DEVICE_5_ID "device_id_5"

#define RELAY_1 D1
#define RELAY_2 D2
#define RELAY_3 D3
#define RELAY_4 D4
#define RELAY_5 D5

bool onPowerState(const String &deviceId, bool state) {
  if (deviceId == DEVICE_1_ID) digitalWrite(RELAY_1, state ? HIGH : LOW);
  if (deviceId == DEVICE_2_ID) digitalWrite(RELAY_2, state ? HIGH : LOW);
  if (deviceId == DEVICE_3_ID) digitalWrite(RELAY_3, state ? HIGH : LOW);
  if (deviceId == DEVICE_4_ID) digitalWrite(RELAY_4, state ? HIGH : LOW);
  if (deviceId == DEVICE_5_ID) digitalWrite(RELAY_5, state ? HIGH : LOW);
  return true;
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  pinMode(RELAY_1, OUTPUT);
  pinMode(RELAY_2, OUTPUT);
  pinMode(RELAY_3, OUTPUT);
  pinMode(RELAY_4, OUTPUT);
  pinMode(RELAY_5, OUTPUT);

  SinricProSwitch &switch1 = SinricPro[DEVICE_1_ID];
  SinricProSwitch &switch2 = SinricPro[DEVICE_2_ID];
  SinricProSwitch &switch3 = SinricPro[DEVICE_3_ID];
  SinricProSwitch &switch4 = SinricPro[DEVICE_4_ID];
  SinricProSwitch &switch5 = SinricPro[DEVICE_5_ID];

  switch1.onPowerState(onPowerState);
  switch2.onPowerState(onPowerState);
  switch3.onPowerState(onPowerState);
  switch4.onPowerState(onPowerState);
  switch5.onPowerState(onPowerState);

  SinricPro.begin(APP_KEY);
}

void loop() {
  SinricPro.handle();
}
