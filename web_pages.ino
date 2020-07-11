
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

const char client_home[] PROGMEM = R"=====(


<!DOCTYPE html>
<html lang="en">
<head>

    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <style>
        body{
            font-family: monospace;
        }
        .card{
            margin:auto;
            width: 80vw;
            height:fit-content;
            /* border: solid 1px black; */
            border-radius: 2px;
            box-shadow:  0px 0px 3px 0px rgba(0,0,0,0.75);
            padding: 20px;
            margin-top: 20px;
            display:flex;
            flex-flow: column wrap;
            justify-content: center;
            align-content: center;
        }  
        .card_row{
            border: solid 1px black;
            width:100%;
            display:flex;
            flex-flow: row wrap;
            align-content: space-between;
            justify-content: center;
            margin: 5px;
        } 
        .card_item{
            padding-left: 20dp;
            border: solid 1px black;
            width: 40%;
            text-align: left;
        }
        .card_item2{
            padding-left: 20dp;
            border: solid 1px black;
            width: 40%;
            text-align: right;
        }
        .pagehead{
            text-align: center;
            margin: auto;
            color: #757575;
            font-size:50px;
            font-family: monospace;
        }
    </style>
</head>
<body>
    <div class="pagehead">Info</div>
    <div class = "card">
    <div class="card_row"><div class = "card_item">SSID</div><div name="ssid" class = "card_item2">as</div></div>
    <div class="card_row"><div class = "card_item">SSID</div><div name="ssid" class = "card_item2">as</div></div>
    <div class="card_row"><div class = "card_item">SSID</div><div name="ssid" class = "card_item2">as</div></div>
    </div>
    <div class = "card">
        <div class="card_row"><div class = "card_item">SSID</div><div name="ssid" class = "card_item2">as</div></div>
        <div class="card_row"><div class = "card_item">SSID</div><div name="ssid" class = "card_item2">as</div></div>
        <div class="card_row"><div class = "card_item">SSID</div><div name="ssid" class = "card_item2">as</div></div>
    
        </div>



</body>
</html>
)=====";
