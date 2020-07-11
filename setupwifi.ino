
void setupWifi(String ssid,String pass,bool edit_mode){

    WiFi.disconnect(true);
    WiFi.begin(ssid,pass);
    Serial.println("Attempting connection");
    looper=0;
    while(WiFi.status() != WL_CONNECTED) {
        delay(500);
        looper++;
//        if(looper == 14 && edit_mode!=1)
//            setupAPN();
        if(looper>16){
            break;
        }
        Serial.print(".");
    }
    looper=0;
    Serial.print("IP address:\t");
    Serial.println(WiFi.localIP());
    publicServer.begin();
}
void setupAPN(){
    WiFi.softAP(ssid, password);
    WiFi.softAPConfig(local_ip, gateway, subnet);
    delay(100);
    IPAddress ap_ip = WiFi.softAPIP();
    Serial.print("Accesspoint ON - IP address: ");
    Serial.println(ap_ip);
    settingsServer.begin();
    Serial.print("settings server on");
    apn_status = 1;
}
