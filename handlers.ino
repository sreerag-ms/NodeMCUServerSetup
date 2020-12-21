

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
            writeWifiData(sta_ssid,sta_password);
            Serial.println(sta_password);
            processing_setup_request = 1;
            writeWifiData(sta_ssid,sta_password);
            setupWifi(1);
            request->send(200, "text/plain",WiFi.localIP().toString());
            Serial.println(sta_password);
         }
        Serial.println(sta_password);

      });
      publicServer.on("/check_events", HTTP_GET, [](AsyncWebServerRequest *request){
            Serial.println("fallen for check_events");
            String response="";
            for(int i =0;i<eventCount;i++){
              response+=(eventList[i].name+"`"+eventList[i].time+"`");
              response+=(String(eventList[i].num1)+"`"+String(eventList[i].num2)+"`"+String(eventList[i].num3)+"~");
            }
            response+="\^";
            request->send(201, "text/plain",response);

  });
        publicServer.on("/add_event", HTTP_POST, [](AsyncWebServerRequest *request){
           if (request->hasParam("time",true)){
            Serial.println("fallen");
            eventList[eventCount].name = request->getParam("name",true)->value();
            eventList[eventCount].time = request->getParam("time",true)->value();
            eventList[eventCount].num1 = request->getParam("ev1",true)->value().toInt();
            eventList[eventCount].num2 = request->getParam("ev2",true)->value().toInt();
            eventList[eventCount].num3 = request->getParam("ev3",true)->value().toInt();
            Serial.println(eventList[eventCount].name);
            Serial.println(eventList[eventCount].time);
            Serial.println(eventList[eventCount].num1);

            eventCount++;
            request->send(200, "text/plain","success");
            Serial.println("count = " + String(eventCount));
        }
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
