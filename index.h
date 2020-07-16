const char homePage[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">

<head>

    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Home</title>
    <style>
        body {
            font-family: monospace;
        }
        
        .card {
            margin: auto;
            width: 80vw;
            height: fit-content;
            /* border: solid 1px black; */
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
            width: 80vw;
            display: flex;
            flex-flow: row wrap;
            align-content: space-between;
            justify-content: center;
            margin: 5px;
        }
        
        .textbox {
            width: 39vw;
            border: none;
            outline: none;
            text-align: center;
            text-align: right;
        }
        
        .card_item {
            padding-left: 20dp;
            width: 40vw;
            text-align: left;
        }
        
        .card_item2 {
            padding-left: 20dp;
            width: 40vw;
            text-align: right;
        }
        
        .pagehead {
            text-align: center;
            margin: auto;
            color: #757575;
            font-size: 50px;
            font-family: monospace;
        }
        
        .resultText {
            border: none !important;
        }
    </style>
</head>

<body>
    <div class="pagehead">Info</div>
    <div class="card">
        <div class="card_row">
            <div class="card_item">SSID</div>
            <div name="ssid" class="card_item2">
                <input type="text" class="resultText textbox" id="ssid">
            </div>
        </div>
        <div class="card_row">
            <div class="card_item">Status</div>
            <div name="ssid" class="card_item2">
                <input type="text" class="resultText textbox" id="wifiStatus">
            </div>
        </div>
        <div class="card_row">
            <div class="card_item">IP</div>
            <div name="ssid" class="card_item2">
                <input type="text" class="resultText textbox" id="ip">
            </div>
        </div>

    </div>
    <div class="card">
        <div class="card_row">
            <div class="card_item">SSID</div>
            <div name="ssid" class="card_item2">as</div>
        </div>
        <div class="card_row">
            <div class="card_item">SSID</div>
            <div name="ssid" class="card_item2">as</div>
        </div>
        <div class="card_row">
            <div class="card_item">SSID</div>
            <div name="ssid" class="card_item2">as</div>
        </div>

    </div>


    <script>
        const Http = new XMLHttpRequest();

        var ssidField = document.getElementById("ssid")
        var ipField = document.getElementById("ip")
        var statusField = document.getElementById("wifiStatus")

        setInterval(verifyIp(), 10000);

        function verifyIp() {
            Http.open("GET", "/checkSSID", true)
            Http.send();
        }
        Http.onreadystatechange = (e) => {
            console.log(Http.responseText.toString())
            var str = Http.responseText.toString()
            var credentials = str.split("~")
            var wifistatus;
            if (credentials[1] == "3")
                wifistatus = "Connected"
            else if (credentials[1] == "2")
                wifistatus = "ssid unavailable"
            else
                wifistatus = "Connection Failed"
            statusField.value = wifistatus
            ssidField.value = credentials[0]
            ipField.value = credentials[2]
        }
    </script>
</body>

</html>
)rawliteral";
const char Time_page3[] PROGMEM = R"rawliteral(
<html>
<head>
  <title></title>
  <script type = "text/javascript">
  function myFunction() {
    var select = document.getElementById("Time_List");
    var evTime = document.getElementById("evTime");
    var evNo1 = document.getElementById("evNo1");
    var evNo2 = document.getElementById("evNo2");
    var evNo3 = document.getElementById("evNo3");
    //alert(select.options[select.selectedIndex].value);  
  
    var spanresult = document.getElementById("demo");
    spanresult.value =select.options[select.selectedIndex].value;

    var str = spanresult.value;
    var res = str.split(" ");
    evTime.value = res[0];
    evNo1.value = res[1];
    evNo2.value = res[2];
    evNo3.value = res[3];
    //document.getElementById("evTime").innerHTML = evTime;
    //document.getElementById("evNo1").innerHTML = evNo1;
    //document.getElementById("evNo2").innerHTML = evNo2;
    //document.getElementById("evNo3").innerHTML = evNo3;
    
    //alert(evTime);
    //document.getElementById("demo").innerHTML = evTime;  
  
  
  }
</script>
</head>
<body>
<table border="1" cellpadding="1" cellspacing="1" style="width:700px;">
  <tbody>
    <tr>
      <td colspan="2" style="text-align: center;"><span style="font-size:30px;"><strong>inQbe Innovations</strong></span></td>
    </tr>
    <tr>
      <td>
      <p>Events Available</p>
      <select id="Time_List" size="7" style="width:140px;" onclick="myFunction()">
        %S
      </select>
      
      </td>
      <td>
        <form action="/get">
          <label for="Event_Time">Event Time:</label> <input id="evTime" name="evTime" type="time"/><br />
          <label for="Event1_value">Event 1   1:</label> <input id="evNo1" name="evNo1" type="number" /> Time in min<br />
          <label for="Event2_value">Event 2   :</label> <input id="evNo2" name="evNo2" type="number" /> Water in Ltr<br />
          <label for="Event3_value">Event 3   :</label> <input id="evNo3" name="evNo3" type="number" /> Nutri in Ltr<br />
          <input type="submit" value="Add Event" />&nbsp;
        </form>
      </td>
    </tr>
    <tr>
      <td colspan="2">&nbsp;</td>
    </tr>
  </tbody>
</table>

<p id="demo">Sinto</p>


</body>
</html>
)rawliteral";
//
//const char homePage[] PROGMEM = R"rawliteral(
//<!DOCTYPE html>
//<html>
//<head>
//<title>Home</title>
//    <style>
//        body{
//            font-family: monospace;
//        }
//        .card{
//            margin:auto;
//            width: 80vw;
//            height:fit-content;
//            /* border: solid 1px black; */
//            border-radius: 2px;
//            box-shadow:  0px 0px 3px 0px rgba(0,0,0,0.75);
//            padding: 20px;
//            margin-top: 20px;
//            display:flex;
//            flex-flow: column wrap;
//            justify-content: center;
//            align-content: center;
//        }  
//        .card_row{
//            border: solid 1px black;
//            width:100%;
//            display:flex;
//            flex-flow: row wrap;
//            align-content: space-between;
//            justify-content: center;
//            margin: 5px;
//        } 
//        .card_item{
//            padding-left: 20dp;
//            border: solid 1px black;
//            width: 40%;
//            text-align: left;
//        }
//        .card_item2{
//            padding-left: 20dp;
//            border: solid 1px black;
//            width: 40%;
//            text-align: right;
//        }
//        .pagehead{
//            text-align: center;
//            margin: auto;
//            color: #757575;
//            font-size:50px;
//            font-family: monospace;
//        }
//    </style>
//</head>
//<body>
//<h1>Client Web page</h1>
//<p>Hi Raven.</p>
//</body>
//</html>
//)rawliteral";

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
        .resultText{
            border: none !important;
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
            <div class="card_item "><input id="response" class="textbox resultText"></div>
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
            console.log(Http.responseText.toString())
            res.value = Http.responseText.toString();
        }
    </script>
</body>

</html>)rawliteral";
