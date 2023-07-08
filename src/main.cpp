#include <Arduino.h>
#include <SPIFFS.h>
#include <WiFi.h>
// #include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <wifi_creds.h>   // include for wifi creds, src/wifi_creds.h

// SPIFFS setup
void initSPIFFS() {
  if (!SPIFFS.begin()) {
    Serial.println("Error mounting SPIFFS volume.");
  }else{
    Serial.println("Mounted SPIFFS volume successfully.");
  }
}


// WiFI setup
void initWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  Serial.printf("Trying to connect [%s] ", WiFi.macAddress().c_str());
  while (WiFi.status() != WL_CONNECTED) {
      Serial.print(".");
      delay(500);
  }
  Serial.printf(" %s\n", WiFi.localIP().toString().c_str());
}

// Web Server setup
AsyncWebServer server(80);

String processor(const String &var) {
    return String("testing");
}

void onRootRequest(AsyncWebServerRequest *request) {
  Serial.println("/index requested.");
  request->send(SPIFFS, "/index.html", "text/html", false, processor);
}

void initWebServer() {
    server.on("/", onRootRequest);

//     server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
//         Serial.println("TESTING.");
//         request->send(200, "text/plain", "Hello World");
//     });

    server.serveStatic("/", SPIFFS, "/");
    server.begin();
}


// Sketch Functions
void setup() {
  pinMode(32, OUTPUT);
  
  Serial.begin(115200); delay(500);
  Serial.println("Started.");

  initSPIFFS();
  initWiFi();
  delay(1000);
  initWebServer();
}
void loop() {
  digitalWrite(32, HIGH);
  delay(1000);
  digitalWrite(32, LOW);
  delay(500);
}
