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

char oper='8';
int menu=0;

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
char teclaM1;
char teclaM2;
///////////////////////////////////////////////////////


void setup() { 
  //////////////////////////////////////
  Serial.begin(9600);
  Wire.begin();         // inicializa bus I2C
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C); // inicializa pantalla con direccion 0x3C
  oled.clearDisplay();
  oled.display();
  //////////////////////////////////////
 
  pinMode(ledrojo_pin, OUTPUT);
  pinMode(ledamarillo_pin, OUTPUT);
  pinMode(ledverde_pin, OUTPUT);
  pinMode(buzzer_pin, OUTPUT);
  pinMode(IN1_pin, OUTPUT);
  pinMode(IN2_pin, OUTPUT);
  pinMode(ENA_pin, OUTPUT);
  pinMode(sw1_pin, INPUT);
  
}
 
void loop() {

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
 
  
// TECLADO MATRICIAL Y BUZZER
 tecla= teclado.getKey(); // obtiene tecla presionada y asigna el valor a TECLA  
 sw1=digitalRead(sw1_pin);
switch(tecla)
      {
        case '1': 
          oper='1';
          tone(buzzer_pin, 2700);
          delay(200);
          noTone(buzzer_pin);
         break;
        
        case '2':
         oper='2';
         tone(buzzer_pin, 1000);
         delay(200);
         noTone(buzzer_pin);
        break;

        case '4':
         oper='4';
          tone(buzzer_pin, 1700);
          delay(200);
          noTone(buzzer_pin);
        break;

        case '8': 
          oper='8';
          tone(buzzer_pin, 1200);
          delay(200);
          noTone(buzzer_pin);
         break;
      }


//ESTADO DEL SISTEMA
  if (sw1==0)
  {  
        estadosistema = 0;  
        estadomotor=0;
        estadosentidogiro=0;
        oled.clearDisplay();
        oled.setTextColor(WHITE);   // establece color al unico disponible (pantalla monocromo)
        oled.setCursor(0, 30);     // ubica cursor en inicio de coordenadas 0,0
        oled.setTextSize(1);      // establece tamano de texto en 1
        oled.print("Sistema Apagado");
        oled.display();
  }
  
  else
    {
        estadosistema = 1;
        

//NAVEGACION DE MENU

if (menu==0){
      switch (oper)
     {
      case '8':
      if (estadosistema==1)
        {
        oled.clearDisplay();
        oled.setTextColor(WHITE);   // establece color al unico disponible (pantalla monocromo)
        oled.setCursor(0, 0);     // ubica cursor en inicio de coordenadas 0,0
        oled.setTextSize(1);      // establece tamano de texto en 1
        oled.print("Menu Principal");
        oled.println();
        oled.print("1.Estado");
        oled.println();
        oled.print("2.Velocidad");
        oled.println();
        oled.print("3.Sentido de giro");
        oled.display();
        }
        break;
        
      case '1':
        if (estadosistema==1)
        {
          oled.clearDisplay();
          oled.setTextColor(WHITE);   // establece color al unico disponible (pantalla monocromo)
          oled.setCursor(0, 0);     // ubica cursor en inicio de coordenadas 0,0
          oled.setTextSize(1);      // establece tamano de texto en 1
          oled.print("Menu Estado");
          oled.println();
          oled.print("1.Marcha");
          oled.println();
          oled.print("2.Parada");
          oled.println();
          oled.print("A.Atras");
          oled.display();  
          menu=1;  
        }
        break;

      case '2':
        if (estadosistema==1)
        {
          oled.clearDisplay();
          oled.setTextColor(WHITE);   // establece color al unico disponible (pantalla monocromo)
          oled.setCursor(0, 0);     // ubica cursor en inicio de coordenadas 0,0
          oled.setTextSize(1);      // establece tamano de texto en 1
          oled.print("Menu Velocidad");
          oled.println();
          oled.print("1.30%");
          oled.println();
          oled.print("2.60%");
          oled.println();
          oled.print("3.100%");
          oled.println();
          oled.print("A.Atras");
          oled.display();
          menu=2; 
        }
        break;
      
      case '4':
        if (estadosistema==1)
        {
          oled.clearDisplay();
          oled.setTextColor(WHITE);   // establece color al unico disponible (pantalla monocromo)
          oled.setCursor(0, 0);     // ubica cursor en inicio de coordenadas 0,0
          oled.setTextSize(1);      // establece tamano de texto en 1
          oled.print("Menu Sentido de giro");
          oled.println();
          oled.print("1.Izquierda");
          oled.println();
          oled.print("2.Derecha");
          oled.println();
          oled.print("A.Atras");
          oled.display(); 
          menu=3;
        }
        break;
  
      default: 
        break;      
    }
}

if (menu==1){
   switch(oper)
    {
      case '1':
        estadomotor=1;
      break;
      case '2':
        estadomotor=0;
      break;
      case '8':
        menu=0;
      break;
      default: 
        break;  
    }
    }

if (menu==2){
   switch(oper)
    {
      case '1':
        velocidad=80;
      break;
      case '2':
        velocidad=110;
      break;
      case '4':
        velocidad=160;
      break;
      case '8':
        menu=0;
      break;
      default: 
        break;  
    }
    }

if (menu==3){
   switch(oper)
    {
      case '1':
        estadosentidogiro=0;
      break;
      case '2':
        estadosentidogiro=1;
      break;
      case '8':
        menu=0;
      break;
      default: 
        break;  
    }
    }
    }
    } 
    

 
