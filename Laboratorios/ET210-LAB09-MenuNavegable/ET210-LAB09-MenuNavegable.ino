#include <Adafruit_GFX.h>   // libreria para pantallas graficas
#include <Adafruit_SSD1306.h>   // libreria para controlador SSD1306 
#define ANCHO 128     // reemplaza ocurrencia de ANCHO por 128
#define ALTO 64       // reemplaza ocurrencia de ALTO por 64
#define OLED_RESET 4      // necesario por la libreria pero no usado
#define sw1_pin 14
Adafruit_SSD1306 oled(ANCHO, ALTO, &Wire, OLED_RESET);  // crea objeto



/////////////////////////////////////////////////2//////
   // select the input pin for the potentiometer
int ledrojo_pin = 8;
int ledamarillo_pin = 7;
int ledverde_pin = 6;
int buzzer_pin= 2;
int IN1_pin = 4;      // IN1_pin de L298N a pin digital 2
int IN2_pin = 3;      // IN2_pin de L298N a pin digital 3
int ENA_pin = 5;      // ENA_pin de L298N a pin digital 5
int velocidad = 0;  // variable to store the value coming from the sensor
int estadomotor = 0; // 0 apagado, 1 encendido
int estadosentidogiro = 0; // 0 izquierda, 1 derecha
int estadosistema = 0; // 0 apagado, 1 encendido
int estadoMenu = 0;
int cant_7 = 0;
int cant_4 = 0;
int sw1;
int estadoSw;

int menu1 = 0;
int menu2 = 0;
int menu3 = 0;
int contador1 = 0;
int op =0;

///////////////////////////////////////////////////////
#include <Keypad.h> // importa o incluye la libreria Keypad
const byte FILAS=3;
const byte COLUMNAS=2;
char keys[FILAS][COLUMNAS]= {    // define la distribucion de teclas
  {'1','2'},
  {'4','5'}, 
  {'7','8'},
};
byte pinesFilas[FILAS]= {13,12,11};
byte pinesColumnas[COLUMNAS]= {10,9};
Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS);
char tecla;
//char teclaMENU1;
///////////////////////////////////////////////////////


void setup() { 
  //////////////////////////////////////
  Serial.begin(9600);
  Wire.begin();         // inicializa bus I2C
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C); // inicializa pantalla con direccion 0x3C
  oled.clearDisplay();
  oled.display();
  pinMode(sw1_pin, INPUT);

  
}
 
void loop() {
  tecla= teclado.getKey();
  //teclaMENU1 = teclado.getKey();
  sw1 = digitalRead(sw1_pin);
    if(sw1==1)
  {
   
    
    estadosistema = 1;

  }
  else 
  {
    
    estadosistema = 0;
    estadomotor = 0;
    estadosentidogiro = 0;
    estadoMenu = 0;
    
  }

  
if(estadosistema ==1){
   if (tecla)
            {
              Serial.println(tecla);
              delay(10);
              switch (tecla)
                {
                  case '1': 
                    
                    menu1=1;
                    menu2=0;
                    menu3=0;
                    tone(buzzer_pin, 2000);
                    delay(200);
                    noTone(buzzer_pin);
                   
            
                  break;
                  
                  case '2': 
                    menu2=1;
                     menu1=0;
                     menu3=0;
                  
                    tone(buzzer_pin, 2000);
                     delay(200);
                     noTone(buzzer_pin);
                     break;
                     
                   case '4': 
                    menu3=1;
                    menu1=0;
                    menu2=0;
                    tone(buzzer_pin, 2000);
                     delay(200);
                     noTone(buzzer_pin);
                  break;
                  
                  case '8': 
                    estadoMenu=0;
                    menu1=0;
                    menu2=0;
                    menu3=0;
                    estadomotor=0;
                    tone(buzzer_pin, 5000);
                     delay(200);
                     noTone(buzzer_pin);
                  break;
                  
                }
            }
}

  // INFORMACION EN PANTALLA

  if (estadosistema==0)
  { 
    oled.clearDisplay();
    oled.setTextColor(WHITE);   // establece color al unico disponible (pantalla monocromo)
    oled.setCursor(10, 30);     // ubica cursor en inicio de coordenadas 0,0
    oled.setTextSize(1);      // establece tamano de texto en 1
    oled.print("Sistema: Apagado");
    oled.display(); 

    
  }
  else if(estadosistema==1 && estadoMenu == 0 )
  {
   
    oled.clearDisplay();
    oled.setTextColor(WHITE);   // establece color al unico disponible (pantalla monocromo)
    oled.setCursor(0, 0);     // ubica cursor en inicio de coordenadas 0,0
    oled.setTextSize(1);      // establece tamano de texto en 1
    oled.print("Menu principal");
    oled.setCursor(0, 15);
    oled.print("1. Estado");
    oled.setCursor(0, 25);
    oled.print("2. Velocidad");
    oled.setCursor(0, 35);
    oled.print("3. Sentido de giro");
    oled.setCursor(0, 45);
    oled.display(); 
  
      

  }


if(menu1 == 1 && estadoMenu == 0)
       {
              if(estadosistema==1){
              Serial.println("Menu 1");
             
              oled.clearDisplay();
              oled.setCursor(0, 0);
              oled.print("Menu estado");
              oled.setCursor(0, 15);
              oled.print("1. Marcha");
              oled.setCursor(0, 25);
              oled.print("2. Parada");
              oled.setCursor(0, 35);
              oled.print("8. Atras");
              oled.display();
              estadoMenu=1;

              op =1;
              //estadomotor =1;
              //Serial.println(tecla);
              delay(10);
              
              switch (tecla)
                {
                  case '1': 
                      estadomotor = 1;
                     Serial.println("Encendido");
                    tone(buzzer_pin, 300);
                     delay(200);
                     noTone(buzzer_pin);
                  break;
                   case '2': 
                      estadomotor = 0;
                      Serial.println("Apagado");
                    tone(buzzer_pin, 300);
                     delay(200);
                     noTone(buzzer_pin);
                  break;
                }

             


              }
        
       }
  
      


if(menu2== 1 && estadoMenu == 0)
       {

              if(estadosistema==1){
              oled.clearDisplay();
              oled.setCursor(0, 0);
              oled.print("Menu velocidad");
              oled.setCursor(0, 15);
              oled.print("1. 30%");
              oled.setCursor(0, 25);
              oled.print("2. 60%");
              oled.setCursor(0, 35);
              oled.print("3. 100%");
              oled.setCursor(0, 45);
              oled.print("8. Atras");
              oled.display();
              estadoMenu=1;
              estadomotor =1;
//              
//              switch (tecla)
//                {
//                  case '1': 
//                      velocidad = 75;
//                     Serial.println("Velocidad 30%");
//                    tone(buzzer_pin, 300);
//                     delay(200);
//                     noTone(buzzer_pin);
//                  break;
//
//                  
//                   case '2': 
//                      velocidad = 150;
//                     Serial.println("Velocidad 60%");
//                    tone(buzzer_pin, 300);
//                     delay(200);
//                     noTone(buzzer_pin);
//                  break;
//
//
//                  case '4': 
//                      velocidad = 255;
//                     Serial.println("Velocidad 100%");
//                    tone(buzzer_pin, 300);
//                     delay(200);
//                     noTone(buzzer_pin);
//                  break;
//


        
      //          }
             
       }
    
       }


//if(menu3== 1 && estadoMenu == 0)
//       {
//              
//              oled.clearDisplay();
//              oled.setCursor(0, 0);
//              oled.print("Menu sentido de giro");
//              oled.setCursor(0, 15);
//              oled.print("1. Izquierda");
//              oled.setCursor(0, 25);
//              oled.print("2. Derecha");
//              oled.setCursor(0, 35);
//              oled.print("3. Atras");
//              oled.display();
//              estadoMenu=1;
//       }
//       






    // LECTURAS Y ESCRITURAS DE PUERTOS

  if (estadosentidogiro==0)
  { digitalWrite(ledamarillo_pin, LOW); }
  else { digitalWrite(ledamarillo_pin, HIGH); }

  if (estadomotor==0)
  { digitalWrite(ledrojo_pin, LOW); }
  else { digitalWrite(ledrojo_pin, HIGH); }

  if (estadosistema==0)
  { digitalWrite(ledverde_pin, LOW); }
  else { digitalWrite(ledverde_pin, HIGH); }
 
  velocidad = 255; 
  //velocidad = map(velocidad,0,1024,0,256);


  // CONTROL DE MOTOR

  if (estadomotor==0)
  { digitalWrite(ENA_pin, LOW); }
  else
  {
     analogWrite(ENA_pin, velocidad);
  }
  if (estadosentidogiro==0)
    {
              
        digitalWrite(IN1_pin, HIGH);        
        digitalWrite(IN2_pin, LOW);       
    }
  else
    {
              
        digitalWrite(IN1_pin, LOW);        
        digitalWrite(IN2_pin, HIGH);       
    }

//if(op == 1)
//{
//  
//}

    

}
