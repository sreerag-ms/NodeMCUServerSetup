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
<p>Hi Raven.</p>
</body>
</html>
)rawliteral";

const char resetPage[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">

<head>
    <title></title>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style>
        body {
            font-family: monospace;
        }
        
        .card {
            margin: auto;
            width: 80vw;
            height: fit-content;
            border-radius: 2px;
            box-shadow: 0px 0px 3px 0px rgba(0, 0, 0, 0.75);
            padding: 20px;
            margin-top: 20px;
            display: flex;
            flex-flow: column wrap;
            justify-content: center;
            align-content: center;
        }
        
        .card_row {
            width: 100%;
            display: flex;
            flex-flow: row wrap;
            align-content: space-between;
            justify-content: center;
            margin-top: 20px;
        }
        
        .card_item {
            width: 32vw;
            text-align: left;
        }
        
        .card_item2 {
            width: 32vw;
            text-align: right;
        }
        
        .pagehead {
            text-align: center;
            margin: auto;
            color: #757575;
            font-size: 50px;
            font-family: monospace;
            margin-bottom: 20px;
        }
        
        .textbox {
            width: 32vw;
            border: none;
            outline: none;
            text-align: center;
            border-bottom: solid 1px black;
        }
        
        .textbox:focus {
            border-bottom: black solid 2px;
        }
        
        .set {
            width: 100px;
            height: 30px;
            background-color: white;
            border: solid 1px black;
            border-radius: 4px;
            margin-top: 2vh;
            font-family: monospace;
            box-shadow: 0px 0px 2px 0px rgba(0, 0, 0, 0.75);
        }
    </style>
</head>

<body>
    <div class="card">
        <span class="pagehead">Setup Wifi</span>
        <form>
            <div class="card_row">
                <div class="card_item">Enter SSID </div>
                <div class="card_item2"><input class="textbox" type="text" name="ssid" id="ssid"></div>
            </div>
            <div class="card_row">
                <div class="card_item"> Password </div>
                <div class="card_item2"><input type="password" class="textbox" name="pass" id="pass"></div>
            </div>
            <div class="card_row"><button id="setBtn" onclick="inputCheck()" type="button" class="set">SET</button></div>
        </form>
        <div class="card_row">
                <div class="card_item"><input id="response" class="textbox"></div>              
        </div>
    </div>

    <script>
        console.log("Asdasdads");


        const Http = new XMLHttpRequest();
        var res = document.getElementById("response");
        var btn = document.getElementById("setBtn")

        function inputCheck() {

            var ssid = document.getElementById("ssid");
            var pass = document.getElementById("pass");
            console.log("inside");
            if ((ssid.value.length != 0)) {
                if ((pass.value).length != 0) {
                    console.log("sdf");

                    sendValues(ssid.value, pass.value);
                } else {
                    pass.style.borderColor = "red";
                }
            } else {
                ssid.style.borderColor = "red";
            }
            return false
        }

        function sendValues(ss_id, pa_ss) {
            Http.open("POST", "/setSSID", true)
            btn.style.innerHTML = "resetting.."
            btn.disabled = true
            var data = new FormData();
            data.append("ssid", ss_id)
            data.append("pass", pa_ss)
            Http.send(data);
        }
        Http.onreadystatechange = (e) => {
            btn.disabled = false
            console.log(Http.responseText)
            res.style.value = Http.responseText;
        }
    </script>
</body>

</html>)rawliteral";
