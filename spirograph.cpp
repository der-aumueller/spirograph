int buttonon = 2; //On Button an Pin 2
int buttonoff = 4; // Off Button an Pin 4
int buttonoffState = 0; //Off Taster Ruhestatus
int buttononState = 0; //On Taster Ruhestatus
int potteller = A0; //Drehteller Poti an pin A0
int pottellerValue = 0; //Drehteller Poti Wert
int motortellerValue = 0; //Wert Motor Drehteller
int potarm = A1; //Arm Poti an Pin A1
int potarmValue = 0; //Wert Arm Poti
int motorarmValue = 0; // Wert Motor Arm
int richtungA           =12; //Richtung Motor A an Pin 12
int pwmA                =3; //Geschwindigkeit Motor A an Pin 3
int bremseA             =9; //Bremse Motor A an Pin 9
int geschwindigkeitA     =255; //Maximalgeschwindigkeit festlegen
int richtungB         =13;  //Pin 13 für die Richtung Motor B
int pwmB              =11;  //Pin 11 für die Geschwindigkeit Motor B
int bremseB           =8;   //Pin 8 für die Bremse Motor b
int geschwindigkeitB   =255; //Maximalgeschwindigkeit festlegen

void setup() {
  pinMode(buttonon, INPUT); //On Taster als Input deklarieren
  pinMode(buttonoff, INPUT); //On Taster als Input deklarieren
  pinMode(richtungA, OUTPUT); //richtung A als Output deklarieren
  pinMode(bremseA, OUTPUT); //bremse A als Output deklarieren
  analogWrite(pwmA, geschwindigkeitA); //Wert Geschwindigkeit auf Pin 3 
  pinMode(richtungB, OUTPUT); //richtung A als Output deklarieren
  pinMode(bremseB, OUTPUT); //bremse A als Output deklarieren
  analogWrite(pwmB, geschwindigkeitB); //Wert Geschwindigkeit auf Pin 3 
  digitalWrite(bremseA, HIGH); //Bremse an 
  digitalWrite(bremseB, HIGH); //Bremse an 
}

void loop() {
 buttononState = digitalRead(buttonon);//Pin 2 auslesen
 buttonoffState = digitalRead(buttonoff);//Pin 4 auslesen
pottellerValue = analogRead(potteller); //Pin A0 auslesen
potarmValue = analogRead(potarm); //Pin A1 auslesen
 motortellerValue = map(pottellerValue, 0, 1023, 110, 255); //Poti Werte von 0 bis 1023 
 motorarmValue = map(potarmValue, 0, 1023, 110, 255);//wird in PWM Wert 110 bis 255 umgewandelt
 analogWrite(pwmA, motortellerValue); //Geschwindigkeit Drehteller schreiben
 analogWrite(pwmB, motorarmValue);  //Geschwindigkeit Arm schreiben
 if (buttononState == HIGH) { //Wenn On Taster gedrückt
  digitalWrite(bremseA, LOW); //Bremse aus
  digitalWrite(richtungA, HIGH); //Motor vorwärts
  digitalWrite(bremseB, LOW); //Bremse aus 
  digitalWrite(richtungB, HIGH); //Motor vorwärts
 }
 if (buttonoffState == HIGH) { //Wenn Off Taster gedrückt
  digitalWrite(bremseA, HIGH); //Bremse an 
  digitalWrite(bremseB, HIGH); //Bremse an 
 }

}
