const char testPage[] PROGMEM = R"rawliteral(

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
)rawliteral";


const char homePage[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<title>Home</title>
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
<h1>Client Web page</h1>
<p>Hai Raven.</p>
</body>
</html>
)rawliteral";
