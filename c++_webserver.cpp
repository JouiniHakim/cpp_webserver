#include<WiFi.h>
#include<WebServer.h>


const char* ssid ="TOPNET_5218";
const char* password ="bz7jr189bp";

WebServer server(80);
int ledPin = 2;

void handleRoot(){
server.send(200, "text/html", "<h1>ESP32 LED Control</h1>"
                              "<p><a href=\"/on\">Turn On LED</a></p>"
                                   "<p><a href=\"/off\">Turn Off LED</a></p>"
    
                                   );
}

//void handleOn() {
    //digitalWrite(ledPin, HIGH); // Turn on the LED
  // server.send(200, "text/plain", "LED is ON");
//}

//void handleOff() {
  //  digitalWrite(ledPin, LOW); // Turn off the LED
   //server.send(200, "text/plain", "LED is OFF");
//}



void setup(){
Serial.begin(115200);
//pinMode(ledPin, OUTPUT);
//digitalWrite(ledPin, LOW);

WiFi.begin(ssid, password);

while(WiFi.status()!= WL_CONNECTED){
delay(1000);
Serial.println("Connecting to WiFi...");
}
Serial.println("Connected to Wifi \n");
Serial.println(WiFi.localIP());

//server.on("/",handleRoot);
//server.on("/on", handleOn);
//server.on("/off", handleOff);

server.begin();

}

void loop() {
    
 server.handleClient();

}


