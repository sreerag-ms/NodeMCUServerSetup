
void setupWifi(String ssid,String pass,bool edit_mode){

    WiFi.begin(ssid,pass);
    Serial.println("Attempting connection");
    looper=0;
    while(WiFi.status() != WL_CONNECTED) {
        delay(500);
        looper++;


//        if(looper == 14 && edit_mode!=1)
//            setupAPN();
        if(looper>10){
            break;
        }
        Serial.print(".");
    }
    if(edit_mode){
      processing_setup_request=0;
    }
    looper=0;
    Serial.print("IP address:\t");
    Serial.println(WiFi.localIP());
    publicServer.begin();
}
void setupAPN(){
    WiFi.softAP(ssid,password);
    WiFi.softAPConfig(local_ip, gateway, subnet);
    delay(100);
    IPAddress ap_ip = WiFi.softAPIP();
    Serial.print("Accesspoint ON - IP address: ");
    Serial.println(ap_ip);
//    settingsServer.begin();
    Serial.print("settings server on at PORT - ");
    apn_status = 1;
    Serial.println(ssid);
    Serial.println(password);
    Serial.println(settings_port);
    Serial.println(apn_status);

}
