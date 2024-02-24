/*
 * https://classroom.google.com/c/MTQzMjE3MTg1NTk5
 */

#include <ESP8266WiFi.h>
const char* ssid = ;
const char* pass = ;

const char* server = "api.thingspeak.com";

WiFiClient client;

void setup() {
  Serial.begin(115200);
  delay(10);

  //Conexion WiFi
  Serial.println();
  Serial.println("Conectando a la red ");
  Serial.println(ssid);

  WiFi.begin(ssid,pass); // Inicia la conexion
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.println(".");
  }
  Serial.println();
  Serial.println("WiFi conectado");
}

void loop() {
  int lecturaLluvia = analogRead(A0);
  Serial.print("Lluvia: ");
  Serial.print(lecturaLluvia);

  if(client.connect(server,80){
    String postStr = apiKey;
    postStr += "&field1=";
    postStr += String(lecturaLluvia);
    postStr += "\r\n";

    client.print("POST /uptade HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection:close\n");
    client.print("X-THINGSPEAKAPIKEY: " apiKey + "\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(postStr.lenghth());
    client.print("\n\n");
    client.print(postStr);
    client.stop();
    client.print("Waiting...");
  }
  delay(20000);
}
