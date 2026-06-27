#define BLYNK_TEMPLATE_ID "ENTER_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "ENTER_TEMPLATE_NAME"
#define BLYNK_AUTH_TOKEN "ENTER_AUTH_TOKEN"
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

char scaled = 0;
char sent = 0;
int i = 0;
const char letters[21] = {
  'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
  'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u'
};
void setup() {
  Serial.begin(9600);
  Serial2.begin(9600, SERIAL_8N1, 16, 17);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

BLYNK_WRITE(V0) {
  int value = param.asInt();
  scaled = (value * 20) / 1023;
  Serial.println(letters[scaled]);
  Serial2.write(letters[scaled]);
  sent = letters[scaled];
}

void loop() {
  Blynk.run();
}