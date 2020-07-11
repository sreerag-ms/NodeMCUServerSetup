#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

IPAddress local_ip(192,168,2,2);
IPAddress gateway(192,168,2,2);
IPAddress subnet(255,255,255,0);
IPAddress ip(192, 168, 0, 177);

String ssid = "ravenClow";
String password = "ba ba ba";
String sta_ssid = "raven";
String sta_password = "ba ba ba";  


ESP8266WebServer settingsServer(local_ip,82);
ESP8266WebServer publicServer(80);


bool apn_status = 0;
int looper =0 ;
bool edit_key=1;
    bool processing_setup_request = 0;


void setup() {
    
    Serial.begin(115200);
    WiFi.mode(WIFI_AP_STA);
    settingsServer.on("/", handle_settings_OnConnect); 
    settingsServer.on("/setSSID", handleSSIDForm); 
    settingsServer.onNotFound(handle_settings_NotFound);
    publicServer.on("/", handle_OnConnect);
    publicServer.onNotFound(handle_NotFound);

}


void loop() {
    if(WiFi.status() != WL_CONNECTED && apn_status==0){
            setupWifi(sta_ssid,sta_password,0);
            Serial.println("Wifi not available turning on APN status = ");
            Serial.println(WiFi.status());

            if(WiFi.status() != WL_CONNECTED) 
             setupAPN();
    
    }
    else if(WiFi.status() == WL_CONNECTED){
        if(apn_status)
        {
            looper=0;
            WiFi.softAPdisconnect(true);
            apn_status=0;
            Serial.println("APN OFF wifi connected"); 
            Serial.println(WiFi.localIP()); 
        }
    }
    if(apn_status==1)
      settingsServer.handleClient();
    publicServer.handleClient();
    
}
