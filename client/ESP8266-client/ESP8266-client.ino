#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

#include <ESP8266WiFiMulti.h>

ESP8266WiFiMulti WiFiMulti;

const char* ssid = "ESP8266-Access-Point";
const char* password = "123456789";

const char* ServerNameSend = "http://192.168.4.1/send";

String signal;


void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
Serial.println();

WiFi.mode(WIFI_STA);
WiFIMulti.addAP(ssid, password);
while(WiFiMulti.run() == WL_CONNECTED){
  delay(500);

  Serial.print(".");
}
Serial.println("");
Serial.println("Connected to WiFi");


}

void loop() {
  // put your main code here, to run repeatedly:

   if ((WiFiMulti.run() == WL_CONNECTED)) {
      signal = httpGETRequest(serverNameSend);
      Serial.println("code: " + signal );
      }
    else {
      Serial.println("WiFi Disconnected");
    }

}
String httpGETRequest(const char* serverName) {
  WiFiClient client;
  HTTPClient http;
    
  // Your IP address with path or Domain name with URL path 
  http.begin(client, serverName);
  
  // Send HTTP POST request
  int httpResponseCode = http.POST("sending some data");
  
  String payload = "--"; 
  
  if (httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();

  return payload;
}
