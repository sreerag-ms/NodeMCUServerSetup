
void handle_OnConnect() {
    publicServer.send(200, "text/html", SendHTML(false)); 
    Serial.println("client connected");
}
void handle_settings_OnConnect() {
    settingsServer.send(200, "text/html", sendSettings(true,"192312312312313")); 
    Serial.println("client connected");
}
void handleSSIDForm(){

    sta_ssid = settingsServer.arg("ssid");
    sta_password = settingsServer.arg("pass");
    Serial.println(sta_ssid);  
    Serial.println(sta_password);
    Serial.println();
    WiFi.disconnect(true);
//    WiFi.softAPdisconnect(true);
//    apn_status=0;
    if(!processing_setup_request){
        processing_setup_request = 1;
        setupWifi(sta_ssid,sta_password,1);
        

    }
    if(WiFi.status() == WL_CONNECTED){
      settingsServer.send(200, "text/html", sendSettings(true,WiFi.localIP().toString())); 
      processing_setup_request = 0;
    }
    else
      settingsServer.send(200, "text/html", sendSettings(true,"No wifi")); 

}
void handle_NotFound(){
    Serial.println(" Press F");
    publicServer.send(404, "text/plain", "Not found");
}
void handle_settings_NotFound(){
    Serial.println(" Press Fa ");
    settingsServer.send(404, "text/plain", "Not found");
}
