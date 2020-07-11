
String SendHTML(uint8_t led){
    String ptr = "<!DOCTYPE html>\n";
    ptr +="<html>\n";
    ptr +="<head>\n";
    ptr +="<title>client</title>\n";
    ptr +="</head>\n";
    ptr +="<body>\n";
    ptr +="<h1>Client Web page</h1>\n";
    ptr +="<p>Hai Raven.</p>\n";
    ptr +="</body>\n";
    ptr +="</html>\n";
    return ptr;
}

String sendSettings(uint8_t led,String ip){
    String ptr = "<!DOCTYPE html><html lang=\"en\"><head><title></title><meta charset=\"UTF-8\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"></head><body>";
    ptr+="<h1>Setup Wifi</h1><form action=\"/setSSID\">Enter SSID <input type=\"text\" name=\"ssid\"> <br> Enter Password <input type=\"text\" name=\"pass\"><br><input type=\"submit\" value=\"submit  \">";
    ptr+="<p>Your profile =";
    ptr+=ip;
    ptr+="</p></form></body></html>";
    return ptr;
}
