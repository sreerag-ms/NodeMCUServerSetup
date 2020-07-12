#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include<Ticker.h>
#include<EEPROM.h>
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
IPAddress sta_gateway(192,168,42,1);
IPAddress sta_subnet(255,255,255,0);
IPAddress sta_dns(8,8,8,8);

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
///ESP8266WebServer settingsServer(local_ip,settings_port);
ESP8266WebServer publicServer(80);




void setup() {
  snprintf_P(html, sizeof(html), testPage);
  snprintf_P(home_page, sizeof(home_page), homePage);

//    html = Time_page2;/
    Serial.begin(115200);
    WiFi.mode(WIFI_AP_STA);
    WiFi.config(sta_ip_static, sta_subnet, sta_gateway, sta_dns);
    publicServer.begin();
//    settingsServer.on("/", handle_settings_OnConnect); 
//    settingsServer.on("/setSSID", handleSSIDForm); 
//    settingsServer.onNotFound(handle_settings_NotFound);
    publicServer.on("/", handle_OnConnect);
    publicServer.on("/setSSID", handleSSIDForm);
    publicServer.on("/editConnections", handle_settings_OnConnect);
    publicServer.on("/test", testConnect);
    publicServer.onNotFound(handle_NotFound);

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
    publicServer.handleClient();
    
}
