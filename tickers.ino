void wifiTicker(){
  if(apn_status == 1){
        Serial.println("try wifi ");
        setupWifi(0);  
  }
}
