/*
  Capitulo 38 de Arduino desde cero en Español.
  Programa que establece una alarma para escribir en monitor serie el texto Alarma
  exactamente a las 14:30 hs. todos los dias.

  Autor: bitwiseAr  

*/

#include <Wire.h>   // incluye libreria para interfaz I2C
#include <RTClib.h>   // incluye libreria para el manejo del modulo RTC
int ledverde_pin=13;

RTC_DS3231 rtc;     // crea objeto del tipo RTC_DS3231

bool alarma = true;   // variable de control con valor verdadero

void setup () {
 Serial.begin(9600);    // inicializa comunicacion serie a 9600 bps
 pinMode(ledverde_pin, OUTPUT);

 if (! rtc.begin()) {       // si falla la inicializacion del modulo
 Serial.println("Modulo RTC no encontrado !");  // muestra mensaje de error
 while (1);         // bucle infinito que detiene ejecucion del programa
 }

 rtc.adjust(DateTime(2022, 4, 3, 19, 25, 55));
 //rtc.adjust(DateTime(__DATE__, __TIME__));
}

void loop () {
 DateTime fecha = rtc.now();        // funcion que devuelve fecha y horario en formato
              // DateTime y asigna a variable fecha
 if ( fecha.hour() == 19 && fecha.minute() == 26 && fecha.second() == 0){ // si hora = 14 y minutos = 30
   // if ( alarma == true ){        // si alarma tiene un valor verdadero
      Serial.println( "Alarma" );// imprime en monitor serie texto Alarma
      digitalWrite(13,HIGH);
      
   //   alarma = false;         // carga valor falso en variable de control
  //  }             // para evitar ingresar mas de una vez
  }
   if ( fecha.hour() == 19 && fecha.minute() == 26 && fecha.second() == 5){ // si hora = 14 y minutos = 30
   // if ( alarma == true ){        // si alarma tiene un valor verdadero
      Serial.println( "Alarma desactivada" );// imprime en monitor serie texto Alarma
      digitalWrite(13,LOW);
      
   //   alarma = false;         // carga valor falso en variable de control
  //  }             // para evitar ingresar mas de una vez
  }
 Serial.print(fecha.day());       // funcion que obtiene el dia de la fecha completa
 Serial.print("/");         // caracter barra como separador
 Serial.print(fecha.month());       // funcion que obtiene el mes de la fecha completa
 Serial.print("/");         // caracter barra como separador
 Serial.print(fecha.year());        // funcion que obtiene el año de la fecha completa
 Serial.print(" ");         // caracter espacio en blanco como separador
 Serial.print(fecha.hour());        // funcion que obtiene la hora de la fecha completa
 Serial.print(":");         // caracter dos puntos como separador
 Serial.print(fecha.minute());        // funcion que obtiene los minutos de la fecha completa
 Serial.print(":");         // caracter dos puntos como separador
 Serial.println(fecha.second());      // funcion que obtiene los segundos de la fecha completa
 
 delay(1000);           // demora de 1 segundo

  //if ( fecha.hour() == 19 && fecha.minute() == 25 ) {  // si hora = 2 y minutos = 0 restablece valor de
    
  //}
 //   alarma = true;          // variable de control en verdadero 

}
