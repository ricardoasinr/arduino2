#include <EEPROM.h>
int address; //direccion en la eeprom
int val;
int limite=151; //Cantidad de direcciones a utilizar
int pot = A0; 
void setup () {
  Serial.begin(9600);
  Serial.print ("Tamano EEPROM:");
  Serial.println(EEPROM.length());//ArduinoUno: 1kb EEPROM storage
  delay (2000);
}

void loop ()
{
  Serial.println ("La escritura inicia en 5 segundos");
  delay (5000) ;
  for (address=0; address< limite; address++)
  {
    val=analogRead(pot)/4; 
    EEPROM.update(address,val); //Guarda val en la direccion address
    Serial.print(address);
    Serial.print("\t");
    Serial.println(val);
    delay(100);
    
  }
  Serial.println("Escritura terminada");
  Serial.println("-------------------");
  
  //////////////////////////////////////////
  Serial.println("Inicio de lectura");
  delay(5000);
  for (address=0; address< limite; address++)
  {
    val=EEPROM.read(address); //Lectura del valor en la direccion address
    Serial.print(address);
    Serial.print("\t");
    Serial.print(val);
    Serial.println();
    delay(120);
  }
  Serial.println("Lectura terminada");
  Serial.println("-------------------");
  
  //////////////////////////////////////////
   Serial.println("Inicio de borrado");
  delay(5000);
  for (address=0; address< limite; address++)
  {
    EEPROM.write(address,0); //ESCRIBE EL VALOR DE 0 EN LA DIRECCION ADDRESS
    Serial.print(address);
    Serial.print("\t");
    Serial.println(0);
  }
  Serial.println("Borrado terminado");
  Serial.println("-------------------");
  //////////////////////////////////////////

  Serial.println("Inicio de lectura");
  delay(5000);
  for (address=0; address< limite; address++)
  {
    val=EEPROM.read(address); //lectura del valor en la direccion address
    Serial.print(address);
    Serial.print("\t");
    Serial.print(val);
    Serial.println();
    delay(50);
  }
  Serial.println("Lectura terminada");
  Serial.println("-------------------");
  Serial.println("FIN");
  delay(20000);
}
