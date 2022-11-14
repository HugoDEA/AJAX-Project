const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>Chariot</title><!--Titre du site sur le navigateur-->
	<link rel="stylesheet" href="./style.css">
	<link rel="stylesheet" href="https://fonts.googleapis.com/icon?family=Material+Icons">
</head>
<body>
<h1>Système de surveillance pour chariot élévateur</h1> <!--Titre du site-->

<br>
<!--Début tableau-->
<h2>Cabine du chariot</h2>
<table>
    <tr>
            <tr>
                <th>Utilisateur</th>
                <th>2900940</th>
            </tr>
            <tr>
                <th>Nom</th>
                <th>Hugo</th>
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
<br>

<h2>Fourche</h2>

<table>
    <tr>
        <tr>
        <th>Couleur</th>
        <th>Bleu</th>
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

<!--Fin tableau-->


<div id="demo">
        La valeur de l'ADC est :  <span id="ADCValue">0</span><br>
      </div>

<script>
    setInterval(function() {
      // Appelle une fonctionne a repetition avec deux seconde d'intervalle
      getData();
    }, 2000); 
    
    function getData() { //Stock l'ADC
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
    background-color: midnightblue;
}


th {/*Modifie le tracage du tableau*/
    border: 1px solid black;
    width: 50%;
    padding: 9px;
    text-align: center;
}
body {/* Modifie le body*/
    font-family: 'Roboto', sans-serif;
    color: white;
    background: #2596be;
  }
h1, h2{/*Met le texte au centre*/
  text-align: center;
}
#demo{
  position: absolute;
  bottom: 40px;
}
</style>
</html>
)=====";
