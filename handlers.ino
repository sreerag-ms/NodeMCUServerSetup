
void handle_OnConnect() {
    publicServer.send(200,"text/html",home_page); 
    Serial.println("client connected");
}
void handle_settings_OnConnect() {
    publicServer.send(200, "text/html", sendSettings(true,"192312312312313")); 
    Serial.println("client connected");
}
void handleSSIDForm(){

    sta_ssid = publicServer.arg("ssid");
    sta_password = publicServer.arg("pass");
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

      publicServer.send(200, "text/html", sendSettings(true,WiFi.localIP().toString())); 



}
void testConnect(){
      publicServer.send(200, "text/html", html);

}
void handle_NotFound(){
    Serial.println(" Press F");
    publicServer.send(404, "text/plain", "Not found");
}
//void handle_settings_NotFound(){
//    Serial.println(" Press Fa ");
//    oubli.send(404, "text/plain", "Not found");
//}
