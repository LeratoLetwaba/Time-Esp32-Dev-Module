#include <WiFi.h>
#include "time.h"



const char* ssid = "i-G3N";
const char* password = "";

const char* ntpServer = "za.pool.ntp.org";
const long  gmtOffset_sec =  2 * 60 * 60;
const int   daylightOffset_sec = 9200;//GMT+5:30

//WiFiUDP ntpUDP;
//NTPClient timeClient(ntpUDP, "pool.ntp.org");

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);

  // Connect to Wi-Fi (optional)
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");

    // Init and get the time
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

}

void loop() {
 
  printLocalTime();


  delay(5000); // Delay for 5 seconds before scanning again

}

void printLocalTime(){
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return;
  }
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");

}
