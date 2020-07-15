#include<Ticker.h>
#include<EEPROM.h>
#include<ESPAsyncWebServer.h>
#ifdef ESP32
  #include <WiFi.h>
  #include <AsyncTCP.h>
#else
  #include <ESP8266WiFi.h>
  #include <ESPAsyncTCP.h>
#endif
#include "index.h"

IPAddress local_ip(192,168,2,2);
IPAddress gateway(192,168,2,2);
IPAddress subnet(255,255,255,0);
IPAddress ip(192, 168, 0, 177);

IPAddress sta_ip_static(192,168,43,100);
IPAddress sta_gateway(192,168,43,1);
IPAddress sta_subnet(255,255,255,0);
IPAddress sta_dns(8,8,8,8);
const char * test = "TEST";
String ssid = "ravenClow";
String password = "ba ba ba";
String sta_ssid = "hraven";
String sta_password = "ba ba ba";  
const int settings_port = 80;

bool apn_status =0;
int looper =0 ;
bool edit_key=1;
bool processing_setup_request = 0;
char html[5000];
char home_page[5000];
char reset_page[5000];
///ESP8266WebServer settingsServer(local_ip,settings_port);
AsyncWebServer publicServer(80);




void setup() {
  snprintf_P(html, sizeof(html), testPage);
  snprintf_P(home_page, sizeof(home_page), homePage);
  snprintf_P(reset_page, sizeof(reset_page), resetPage);

    Serial.begin(115200);
    WiFi.mode(WIFI_AP_STA);
//    WiFi.config(sta_ip_static, sta_sub/net, sta_gateway, sta_dns);    
//    publicServer.on("/test", testConnect);
  serverSetup();
    publicServer.begin();
}



void loop() {
    if(WiFi.status() != WL_CONNECTED && apn_status ==0){
      
        setupWifi(sta_ssid,sta_password,0);

        if(WiFi.status() != WL_CONNECTED && apn_status == 0){ 
            Serial.println("Wifi not available turning on APN, wifistatus = ");
            Serial.println(WiFi.status());
            setupAPN();
        }
    
    }
    else if(WiFi.status() == WL_CONNECTED){
        if(apn_status == 1)
        {
            looper=0;
            WiFi.softAPdisconnect(true);
            apn_status=0;
            Serial.println("APN OFF wifi connected"); 
            Serial.println(WiFi.localIP()); 

        }
    }
//    if(apn_status==1)
//      settingsServer.handleClient();

    
}
