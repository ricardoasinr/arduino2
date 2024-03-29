/*
  Capitulo 19 de Arduino desde cero en Español.
  Programa que utiliza el modulo controlador de motor L298N para controlar el giro
        de un motor de corriente continua con caja reductora y rueda.

  Autor: bitwiseAr  

*/


int IN1 = 2;      // IN1 de L298N a pin digital 2
int IN2 = 3;      // IN2 de L298N a pin digital 3
int ENA = 5;      // ENA de L298N a pin digital 5

void setup(){
  pinMode(IN1, OUTPUT);   // pin 2 como salida
  pinMode(IN2, OUTPUT);   // pin 3 como salida  
  pinMode(ENA, OUTPUT);   // pin 5 como salida
}

void loop(){
  digitalWrite(ENA, HIGH);  // habilita motor A (giro en un sentido)
  digitalWrite(IN1, LOW); // IN1 a 0
  digitalWrite(IN2, HIGH);  // IN2 a 1
  delay(3000);      // demora de 3 seg.

  digitalWrite(ENA, LOW); // ENA en 0 para deshabilitar motor

  
  delay(2000);      // demora de 2 seg.

  digitalWrite(ENA, HIGH);  // habilita motor A (giro en sentido contrario)
  digitalWrite(IN1, HIGH);  // IN1 a 1
  digitalWrite(IN2, LOW); // IN2 a 0
  delay(3000);      // demora de 3 seg

  digitalWrite(ENA, LOW); // ENA en 0 para deshabilitar motor
  delay(2000);      // demora de 2 seg.
}
