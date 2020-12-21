


String sendSettings(uint8_t led,String ip){
    String ptr = "<!DOCTYPE html><html lang=\"en\"><head><title></title><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"></head><body>";
    ptr+="<h1>Setup Wifi</h1><form action=\"/setSSID\">Enter SSID <input type=\"text\" name=\"ssid\"> <br> Enter Password <input type=\"text\" name=\"pass\"><br><input type=\"submit\" value=\"submit  \">";
    ptr+="<p>Your profile =";
    ptr+=ip;
    ptr+="</p></form></body></html>";
    return ptr;
}
