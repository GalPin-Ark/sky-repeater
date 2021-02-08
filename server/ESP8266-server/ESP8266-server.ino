#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>

const char* ssid = "ESP8266-Access-Point";
const char* password = "123456789";

AsyncWebServer server(80);

String readSignal(){
  return "Some code";
}

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
Serial.println();

Serial.print("Setting Access Point...");

WiFi.SoftAP(ssid, password);

IPAdddress IP = WiFi.SoftAPIP();
Serial.print("AP IP address: ");
Serial.println(IP);

server.on("/send",[](AsyncWebServerRequest *request){
  request -> send_P(200, "text/plain", readSignal());
  });

  server.begin();

}

void loop() {
  // put your main code here, to run repeatedly:

}
