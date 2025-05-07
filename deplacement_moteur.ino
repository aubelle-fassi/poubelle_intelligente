#include <Ultrasonic.h>
Ultrasonic ultrasonic(12, 13);//echo pin 13, Trig pin 12
int distance;
const int fin_droite=7; //pin 7 FIN de course ouverture
const int fin_gauche=8; //pin 7 FIN de course ouverture
int droite;
int gauche;
int IN3 = 2;
int IN4 = 4;
int ENB = 5;
void setup() 
{
   Serial.begin(9600);
    pinMode(7, INPUT);
    pinMode(8, INPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(ENB, OUTPUT);
}

void loop() 
{
  gauche=digitalRead(7);
  droite=digitalRead(8);
  distance = ultrasonic.read();
  Serial.print("Distance en CM = ");
  Serial.println(distance);
  Serial.println(gauche);
  Serial.println(droite);
  
    if((distance < 40)  && (gauche == LOW))
  {

    //faire tourner le moteur vers l'arriere
  analogWrite(ENB, 85);
  digitalWrite(IN3, HIGH); 
  digitalWrite(IN4, LOW);
  delay(1000);
  digitalWrite(ENB, LOW);
  delay(2000);
  }  
 else if((distance < 40) && (gauche== HIGH))
 {
     analogWrite(ENB, LOW); 
 }
 
    if((distance  >= 40) && (droite == LOW)) 
  {
      // faire tourner le moteur vers l'avant
   analogWrite(ENB, 90);
   digitalWrite(IN3, LOW); 
   digitalWrite(IN4, HIGH);
   delay(430);
   digitalWrite(ENB, LOW);
   delay(2000);
  }
   else if((distance  >= 40) && (droite== HIGH))
 {
     analogWrite(ENB, LOW); 
     delay(1000);
 }
 


 delay(300);
}
