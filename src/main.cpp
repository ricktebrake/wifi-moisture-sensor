#include <CloudIoTCore.h>
#include <Arduino.h>
#include "esp8266_mqtt.h"

#ifndef LED_BUILTIN
#define LED_BUILTIN 13
#endif



int motionSensorValue;
int moistureValue;
int moisturePin = A0;
unsigned long lastMillis = 0;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  setupCloudIoT(); // Creates globals for MQTT
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(A0, INPUT);
}


void loop()
{
  mqttClient->loop();
  delay(10); // <- fixes some issues with WiFi stability

  if (!mqttClient->connected())
  {
    ESP.wdtDisable();
    connect();
    ESP.wdtEnable(0);
  }

  // TODO: Replace with your code here
  if (millis() - lastMillis > telemetrySendInterval)
  {
    moistureValue = map(analogRead(moisturePin), 1023, 165, 0, 100);
    Serial.println(moistureValue);
    lastMillis = millis();
    publishTelemetry(String(moistureValue));
  }
}


// void setup() {
//   Serial.begin(115200);

//   pinMode(D1, OUTPUT);
//   pinMode(D2, INPUT);

//   WiFi.begin(ssid, password);

//   Serial.println("Connecting");
//   while (WiFi.status() != WL_CONNECTED)
//   {
//     digitalWrite(D1, HIGH);
//     delay(250);
//     Serial.print(".");
//     digitalWrite(D1, LOW);
//     delay(250);
//   }
//   Serial.println();

//   Serial.print("Connected, IP address: ");
//   Serial.println(WiFi.localIP());



// }

// void loop() {
//   int moistureValue = analogRead(A0);
//   int motionSensorValue = digitalRead(D2);
//   String init = "";
//   String message = init + "{\n" +
//   "\"motion-sensor\":\"" + motionSensorValue + "\",\n" +
//   "\"soil-sensor\": \"" + moistureValue + "\"\n" +
//   "}";

  //
  // WiFiClientSecure secureClient;
  // secureClient.setFingerprint("F5:7E:50:0A:29:CF:2D:08:34:E2:51:F2:9A:C8:AE:9D:DA:42:5F:A2");
  // Serial.println("Connectiong to ");
  // Serial.println(host);
  // if(secureClient.connect(host, 443)) {
    //
    // Serial.println("Connected!");

    // secureClient.print(String("POST ") + url + " HTTP/1.1\r\n" +
    //              "Host: " + host + "\r\n" +
    //              "Content-Type: application/json\r\n" +
    //              "Content-Length: "+message.length()+"\r\n" +
    //              "Connection: close\r\n" +
    //              "\r\n" +
    //              message);

    // Serial.println("Request sent");
    // unsigned long timeout = millis();
    // bool printNext = false;
    // while(secureClient.connected()) {
    //   if(secureClient.available()) {
    //     String line = secureClient.readStringUntil('\n');
    //     if(line == "\r") {
    //       printNext = true;
    //     }
    //     if(printNext && line != "\r" || line != "\n") {
    //       Serial.println(line);
    //       Serial.println();
    //     }
    //   }
    // }
    // secureClient.stop();

    // Serial.println("Connection closed");
    //  if(motionSensorValue == 0) {
    //     digitalWrite(D1, LOW);
    // } else if(motionSensorValue == 1) {
    //     digitalWrite(D1, HIGH);
    // }

  // } else {
  //   Serial.println("Connection failed");
  //   secureClient.stop();
  //   return;
  // }
// }
