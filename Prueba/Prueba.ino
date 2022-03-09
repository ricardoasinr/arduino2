//////////////////////////////////////////////////////
#include <Adafruit_GFX.h>   // libreria para pantallas graficas
#include <Adafruit_SSD1306.h>   // libreria para controlador SSD1306 
#define ANCHO 128     // reemplaza ocurrencia de ANCHO por 128
#define ALTO 64       // reemplaza ocurrencia de ALTO por 64
#define OLED_RESET 4      // necesario por la libreria pero no usado
Adafruit_SSD1306 oled(ANCHO, ALTO, &Wire, OLED_RESET);  // crea objeto
//////////////////////////////////////////////////////
#define buzzer_pin 2
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



void setup() { 
  //////////////////////////////////////
  Wire.begin();         // inicializa bus I2C
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  
  
  
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

  
  VALOR = analogRead(LDR); 
  //PWM = map(VALOR, 0, 1023, 255, 0);
  

    oled.clearDisplay();      
        oled.setTextColor(WHITE);   
        oled.setCursor(30, 25);     
        oled.setTextSize(2);
        oled.print(VALOR);
        noTone(buzzer_pin);
        delay(200); 
        oled.display();

}
