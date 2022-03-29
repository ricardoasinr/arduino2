//////////////////////////////////////////////////////
#include <Adafruit_GFX.h>   // libreria para pantallas graficas
#include <Adafruit_SSD1306.h>   // libreria para controlador SSD1306 
#define ANCHO 128     // reemplaza ocurrencia de ANCHO por 128
#define ALTO 64       // reemplaza ocurrencia de ALTO por 64
#define OLED_RESET 4      // necesario por la libreria pero no usado
Adafruit_SSD1306 oled(ANCHO, ALTO, &Wire, OLED_RESET);  // crea objeto
//////////////////////////////////////////////////////
#define buzzer_pin 2

#include <Servo.h>
Servo servo1;
///////////////////////////////////////////////////////
int sw1;
#define sw1_pin 3
#include <Keypad.h> // importa o incluye la libreria Keypad
const byte FILAS=4;
const byte COLUMNAS=4;
char keys[FILAS][COLUMNAS]= {    // define la distribucion de teclas
  {'1','2','3','A'},
  {'4','5','6','B'}, 
  {'7','8','9','C'}, 
  {'*','0','#','D'} 
};
byte pinesFilas[FILAS]= {13,12,11,10};
byte pinesColumnas[COLUMNAS]= {9,8,7,6};
Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS);
char tecla;
///////////////////////////////////////////////////////
int sensor_pin = A0;  
int sensorValue = 0; 

int LDR = 1; // variable para almacenar el valor del sensor LDR
//int LED = 1; // variable para almacenar el valor del LED
int VALOR; // variable de estado para almacenar el valor de la entrada analógica
int PWM; //
char t;
int ANGULO = 0;
int valorLuz = 0;
int pmin = 30;
int pmax = 1009;
void setup() { 
  //////////////////////////////////////
  Wire.begin();         // inicializa bus I2C
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  
  servo1.attach(5,pmin,pmax);
  
  pinMode(sw1_pin, INPUT);


  
  oled.clearDisplay();
  oled.display();
  //////////////////////////////////////
  Serial.begin(9600);    // inicializa comunicacion serie a 9600 bps
 
  ///////////////////////////////////////////////////////
  pinMode(buzzer_pin, OUTPUT);
  ///////////////////////////////////////////////////////

  

}
 
void loop() {

// PRUEBA DE TECLADO MATRICIAL Y PANTALLA OLED

 tecla= teclado.getKey(); // obtiene tecla presionada y asigna el valor a TECLA  
sensorValue = analogRead(sensor_pin);
  sw1=digitalRead(sw1_pin);
    

      if(tecla){
        tone(buzzer_pin,1500);
        delay(200);
        noTone(buzzer_pin);
        t = tecla;
        
      }

  
  VALOR = analogRead(LDR); 

  ANGULO= map(sensorValue, 27, 1013, 0, 180);
  valorLuz = map(VALOR,300,100,0,100);
  //PWM = map(VALOR, 0, 1023, 255, 0);
  servo1.write(ANGULO);

        oled.clearDisplay();      
        oled.setTextColor(WHITE);   
        oled.setCursor(0, 0);     
        oled.setTextSize(1);

         oled.print("Potenciometro: ");
         oled.println(sensorValue);
         oled.println(" ");
        
        
        oled.print("Luz: ");
         oled.println(valorLuz);
         oled.println(" ");

         
         oled.print("Switch: ");
         oled.println(sw1);
         oled.println(" ");


         
         oled.print("Angulo: ");
         oled.println(ANGULO);
         
       
         
         oled.print("Teclado: ");
         oled.println(t);
         oled.println(" ");

           
        noTone(buzzer_pin);
        delay(200); 
        oled.display();

}
