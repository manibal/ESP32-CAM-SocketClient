/*

*/

#include <WebSocketsClient.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include "camera_wrap.h"

#define DEBUG


const char* ssid = "SSID"; //replace with your wifi ssid
const char* password = "PASS"; //replace with your wifi password


//holds the current upload
int cameraInitState = -1;
uint8_t* jpgBuff = new uint8_t[68123];
size_t   jpgLength = 0;


// Use WiFiClient class to create TCP connections
WiFiClient tcpClient;
bool clientConnected = false;


WebSocketsClient webSocket;
int ledState = LOW;

void webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {
  switch(type) {
      case WStype_DISCONNECTED:
          Serial.printf("Disconnected!\n");
          clientConnected = false;
          break;
      case WStype_CONNECTED:
          Serial.printf("Connected!\n");
          clientConnected = true;
          break;
      case WStype_TEXT:
      case WStype_BIN:
      case WStype_ERROR:
      case WStype_FRAGMENT_TEXT_START:
      case WStype_FRAGMENT_BIN_START:
      case WStype_FRAGMENT:
      case WStype_FRAGMENT_FIN:
          Serial.println(type);
          break;
  }
}

void setup(void) {
  Serial.begin(115200);
  Serial.print("\n");
  #ifdef DEBUG
  Serial.setDebugOutput(true);
  #endif

  cameraInitState = initCamera();

  Serial.printf("camera init state %d\n", cameraInitState);



 

  //WIFI INIT
  Serial.printf("Connecting to %s\n", ssid);
  if (String(WiFi.SSID()) != String(ssid)) {
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
  }

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    // digitalWrite(LED_BUILTIN, ledState);
    Serial.print(".");
  }
  // digitalWrite(LED_BUILTIN, LOW);
  Serial.println("");
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());

  // server address, port and URL
  webSocket.begin("192.168.0.115", 8765, "/");
  webSocket.onEvent(webSocketEvent);
  // try ever 5000 again if connection has failed
  webSocket.setReconnectInterval(5000);

}

void loop(void) {
  webSocket.loop();
  if(clientConnected == true){
    grabImage(jpgLength, jpgBuff);
    webSocket.sendBIN(jpgBuff, jpgLength);
    // Serial.print("send img: ");
    // Serial.println(jpgLength);
  }
  
}
