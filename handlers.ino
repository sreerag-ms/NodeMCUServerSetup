

void serverSetup(){
    publicServer.on("/",HTTP_GET, [](AsyncWebServerRequest *request){    
        request->send(200,"text/html",home_page); 
        Serial.println("client connected");
        });

    publicServer.on("/setSSID",HTTP_POST, [](AsyncWebServerRequest *request){    
        if (request->hasParam("ssid",true)){
            Serial.println("fallen");
            sta_ssid = request->getParam("ssid",true)->value();
            sta_password = request->getParam("pass",true)->value();
    }

    Serial.println(sta_ssid);  
    Serial.println();
    WiFi.disconnect(true);
    if(!processing_setup_request){
         Serial.println(sta_password);
        processing_setup_request = 1;
        request->send(200, "text/html", home_page); 
        setupWifi(sta_ssid,sta_password,1);
        request->send(200, "text/plain", "sdfsdf");
        Serial.println(sta_password);

    }
    Serial.println(sta_password);

      });
//   publicServer.on("/test","text/html",[](Asy/ncWebserverRequest *request){
    

    publicServer.on("/editConnections",HTTP_GET, [](AsyncWebServerRequest *request){
          request->send(200, "text/html", reset_page); 
          Serial.println("client connected");
      });
    publicServer.onNotFound([](AsyncWebServerRequest *request){
      request->send(404);
});
//    publicServer.onNotFound(/handle_NotFound);


    
}
