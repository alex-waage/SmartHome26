/*********
  Alexandr Waage
  Chytrá schránka © 2021
*********/

// pripojeni wifi knihovny
#include <WiFi.h>
#include <WebServer.h>

// pripojeni k siti
const char* ssid = "ssid"; //nazev site
const char* password = "heslo"; //heslo site

// komunikační port - přes "server" zadavam prikazy
WebServer server(80);

int pTrig = 16;
int pEcho = 17;

long odezva, vzdalenost;

void setup() {
  pinMode(pTrig, OUTPUT);
  pinMode(pEcho, INPUT);
  
  Serial.begin(115200);
  // Pripojeni k wifi siti
  Serial.print("Připojování k ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  // Zobrazeni IP adresy a start serveru
  Serial.println("");
  Serial.println("WiFi připojena.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("odkaz na nastaveni");
  server.begin();
}

void loop(){
  server.handleClient();
  delay(10);
  String prazdna = "Schranka je prazdna";
  String plna = "Ve schrance neco je";
    digitalWrite(pTrig, LOW);
  delay(3000); //Jednou za pul minuty cidlo sepne
  digitalWrite(pTrig, HIGH);
  delayMicroseconds(5);
  digitalWrite(pTrig, LOW);
  // pomocí funkce pulseIn získáme následně
  // délku pulzu v mikrosekundách (us)
  odezva = pulseIn(pEcho, HIGH);
  // přepočet získaného času na vzdálenost v cm
  vzdalenost = odezva / 58.31;
  if(vzdalenost < 30){
    Serial.println(plna);
    server.send(200, "text/plain", plna);
    delay(5000);
  }
  else{
    Serial.println(prazdna);
    server.send(200, "text/plain", prazdna);
    delay(5000);
  }
}
