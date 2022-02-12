const int zvukovySenzor = 8;

int hluk = HIGH;
boolean Alarm = false;

long casSepnuti;
int pauzaPoSepnuti = 500;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(zvukovySenzor, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  hluk = digitalRead(zvukovySenzor);

  if(hluk == LOW)
  {
    casSepnuti = millis();
    if(!Alarm) 
    {
      Serial.println("Detekce hluku!");
      Alarm = true;
    }
  }
  else 
  {
    // pokud je rozdíl mezi časem sepnutí a aktuálním časem
    // vetší než nastavená pauzaPoSepnuti a zároveň byl sepnuty Alarm,
    // vytiskni informaci o klidovém režimu a nastav Alarm pro nové použití
    if( (millis()-casSepnuti) > pauzaPoSepnuti  &&  Alarm){
      Serial.println("Klidovy rezim.");
      Alarm = false;
    }
  }
}
