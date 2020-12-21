void loadEeprom(){
  EEPROM.begin(512);

}
void writeWifiData(String ssid,String pass){
    char i = ssid[0];
    int addr = 0;
    do{
        EEPROM.write(addr,i);
        addr++;
        i = ssid[addr];
    }while(i!='\0');
    EEPROM.write(addr,i);
    i = pass[0] ;
    addr = 33;
    do{
        EEPROM.write(addr,i);
        addr++;
        i = pass[addr-33];    
    }while(i!='\0');
    EEPROM.write(addr,i);
    Serial.println(ssid + "written to eeprom  !!! "+ readSsid());
}
String readSsid(){
    String ssid="";
    int addr = 0;
    char c;
    while(true)
    {
        c=EEPROM.read(addr);
        ssid+=c;
        addr++;
        if(c =='\0' || addr > 31)
            break;
    }
    return ssid;
}
String readPassword(){
    String pass="";
    int addr = 33;
    char c;
    while(true)
    {
        c=EEPROM.read(addr);
        pass+=c;
        addr++;
        if(c =='\0' || addr > 60)
            break;
    }
    Serial.println(pass);
    return pass;
}
