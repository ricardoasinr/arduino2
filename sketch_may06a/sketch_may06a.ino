#include <Servo.h>
Servo servo1;

int PULSOMIN = 80;
int PULSOMAX = 1009;

int VALORPOT;
int ANGULO;
int angulo;

int LDR =1;
int luz;

void setup() {
  servo1.attach(5, PULSOMIN, PULSOMAX);
  Serial.begin(9600);
}

void loop() {

  luz = analogRead(LDR);

  VALORPOT = analogRead(A0);
  //Serial.println(VALORPOT); //min 5, max 1017
  Serial.println(ANGULO);
  ANGULO= map(VALORPOT, 50, 900, 0, 180);
  servo1.write(ANGULO);
  delay(100);

  if(luz<230)
  {
    angulo = map(luz, 230, 350, 0, 180);
    servo1.write(angulo);
    Serial.println(luz);
    delay(200);
  }
  
  
}
