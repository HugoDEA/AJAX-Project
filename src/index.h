const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>Chariot</title>
	<link rel="stylesheet" href="./style.css">
	<link rel="stylesheet" href="https://fonts.googleapis.com/icon?family=Material+Icons">
</head>
<body>
<h1>Système de surveillance pour chariot élévateur</h1>

<br>

<h2>Cabine du chariot</h2>
<table>
    <tr>
            <tr>
                <th>Utilisateur</th>
                <th>2900940</th>
            </tr>
            <tr><th>Vitesse</th>
                <th>20 km/h</th>
            </tr>
            <tr>
                <th>Message diffusé</th>
                <th>Vous roulez trop vite !</th>
    </tr>
</table>

<br>

<h2>Fourche</h2>

<table>
    <tr>
        <tr>
        <th>Couleur</th>
        <th><span id="couleur">0</span></th>
    </tr>

    <tr>
        <th>Identification </th>
        <th>Ok !</th>
    </tr>
    <tr>
        <th>Poids</th>
        <th>25 kg</th>
    </tr>
</table>


<div id="demo">
    <h1>The ESP8266 NodeMCU Update web page without refresh</h1>
        <button type="button" onclick="sendData(1)">LED ON</button>
        <button type="button" onclick="sendData(0)">LED OFF</button><BR>
    </div>
    
    <div>
        ADC Value is : <span id="ADCValue">0</span><br>
        LED State is : <span id="LEDState">NA</span>
    </div>
    
<script>
    function sendData(led) {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          document.getElementById("LEDState").innerHTML =
          this.responseText;
        }
      };
      xhttp.open("GET", "setLED?LEDstate="+led, true);
      xhttp.send();
    }
    
    setInterval(function() {
      // Call a function repetatively with 2 Second interval
      getData();
    }, 2000); //2000mSeconds update rate
    
    function getData() {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
          document.getElementById("ADCValue").innerHTML =
          this.responseText;
        }
      };
      xhttp.open("GET", "readADC", true);
      xhttp.send();
    }
    </script>

</body>

<style>
table{/* Modifie le tableau*/
    border-collapse: collapse;
    margin: auto;
    width: 80vh;
}

th {/*Modifie le tracage du tableau*/
    border: 1px solid black;
    width: 50%;
    padding: 9px;
    text-align: center;
}
body {/* Modifie le body*/
    font-family: 'Roboto', sans-serif;
}
h1, h2{/*Met le texte au centre*/
  text-align: center;
}
</style>
</html>

)=====";
