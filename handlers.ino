

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
            setupWifi(sta_ssid,sta_password,1);
            request->send(200, "text/plain",WiFi.localIP().toString());
            Serial.println(sta_password);
         }
        Serial.println(sta_password);

      });
    publicServer.on("/checkSSID",HTTP_GET, [](AsyncWebServerRequest *request){    
        Serial.println(" in checkSSID");
        request->send(200, "text/plain",sta_ssid + " ~" +WiFi.status()+ "~ " + WiFi.localIP().toString());

        
        });

 

    publicServer.on("/editConnections",HTTP_GET, [](AsyncWebServerRequest *request){
          request->send(200, "text/html", reset_page); 
          Serial.println("client connected");
      });
    publicServer.on("/get", HTTP_GET, [] (AsyncWebServerRequest *request) {
        String eventTime,eventNo1,eventNo2,eventNo3;
        // GET input1 value on <ESP_IP>/get?input1=<inputMessage>
        if (request->hasParam(PARAM_INPUT_1)) {
            eventTime = request->getParam(PARAM_INPUT_1)->value();
            eventNo1 = request->getParam(PARAM_INPUT_2)->value();
            eventNo2 = request->getParam(PARAM_INPUT_3)->value();
            eventNo3 = request->getParam(PARAM_INPUT_4)->value();

            add_event(eventTime,eventNo1,eventNo2,eventNo3);
            pack_events();
        }
        else {
     
        }
        request->send(200, "text/html", html);
  });
    publicServer.on("/alarms", HTTP_GET, [](AsyncWebServerRequest *request){
          request->send_P(200, "text/html", html);
    });
    publicServer.onNotFound([](AsyncWebServerRequest *request){
      request->send(404);
});
//    publicServer.onNotFound(/handle_NotFound);


    
}
