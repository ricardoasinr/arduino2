
//////////////////////////////////////////////////////
#include <Adafruit_GFX.h>   // libreria para pantallas graficas
#include <Adafruit_SSD1306.h>   // libreria para controlador SSD1306 
#define ANCHO 128     // reemplaza ocurrencia de ANCHO por 128
#define ALTO 64       // reemplaza ocurrencia de ALTO por 64
#define OLED_RESET 4      // necesario por la libreria pero no usado
#define sw1_pin 9
Adafruit_SSD1306 oled(ANCHO, ALTO, &Wire, OLED_RESET);  // crea objeto



/////////////////////////////////////////////////2//////

int potenciometro_pin = A0;    // select the input pin for the potentiometer
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

int cant_7 = 0;
int cant_4 = 0;
int sw1;
int estadoSw;


///////////////////////////////////////////////////////
#include <Keypad.h> // importa o incluye la libreria Keypad
const byte FILAS=3;
const byte COLUMNAS=1;
char keys[FILAS][COLUMNAS]= {    // define la distribucion de teclas
  {'1'},
  {'4'}, 
  {'7'},
};
byte pinesFilas[FILAS]= {13,12,11};
byte pinesColumnas[COLUMNAS]= {10};
Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS);
char tecla;
///////////////////////////////////////////////////////


void setup() { 
  //////////////////////////////////////
  Serial.begin(9600);
  Wire.begin();         // inicializa bus I2C
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C); // inicializa pantalla con direccion 0x3C
  oled.clearDisplay();
  oled.display();
  //////////////////////////////////////

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
 
  velocidad = analogRead(potenciometro_pin); 
  velocidad = map(velocidad,0,1024,0,256);


// INFORMACION EN PANTALLA

  if (estadosistema==0)
  { 
    oled.clearDisplay();
    oled.setTextColor(WHITE);   // establece color al unico disponible (pantalla monocromo)
    oled.setCursor(0, 30);     // ubica cursor en inicio de coordenadas 0,0
    oled.setTextSize(1);      // establece tamano de texto en 1
    oled.print("Sistema: Apagado");
    oled.display(); 
  }
  else
  {
    oled.clearDisplay();
    oled.setTextColor(WHITE);   // establece color al unico disponible (pantalla monocromo)
    oled.setCursor(0, 0);     // ubica cursor en inicio de coordenadas 0,0
    oled.setTextSize(1);      // establece tamano de texto en 1
    oled.print("Sistema: Encendido");
    oled.setCursor(0, 15);
    if (estadomotor==0)
    { oled.print("Motor: Apagado"); }
    else { oled.print("Motor: Encendido"); }
    oled.setCursor(0, 30);
    if (estadosentidogiro==0)
    { oled.print("Sentido: Izquierda"); }
    else { oled.print("Sentido: Derecha"); }
    oled.setCursor(0, 45);
    oled.print("Velocidad: ");
    oled.print(velocidad);

    oled.display(); 
  }

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
  sw1 = digitalRead(sw1_pin);
  int aux = 0;
  Serial.println(sw1);
  if(sw1==0)
  {
    aux = 0;
    
        
    
  }
  else
  {
    aux = 1;
 
  }

  if(aux==1)
  {
   // Serial.println("system");
    estadosistema=1 ;
     estadosistema = 1;
        tone(buzzer_pin, 1500);
        delay(200);
        noTone(buzzer_pin);
    
  }
  else {
      // Serial.println("No system");
    estadosistema = 0;
        estadomotor = 0;
        estadosentidogiro = 0;
    
  }

  if (tecla)
  {
    Serial.println(tecla);
    delay(10);
    switch (tecla)
    {
      case '1': 
          if (estadosistema==1)
        {     
          Serial.println("Derecha"); 
          estadosentidogiro = 1;
          tone(buzzer_pin, 2000);
          delay(200);
          noTone(buzzer_pin);
          delay(200);
          tone(buzzer_pin, 2000);
          delay(200);
          noTone(buzzer_pin);}



          
        break;
        /*
      case '2':
      Serial.println("2"); 
        estadosistema = 0;
        estadomotor = 0;
        estadosentidogiro = 0;
        tone(buzzer_pin, 1500);
        delay(200);
        noTone(buzzer_pin);
        break;
        */
        
      case '4':
            cant_4++;
          if(cant_4>=2)
          {
            if (estadosistema==1)
            {
          Serial.println("Apagado"); 
          estadomotor = 0;
          tone(buzzer_pin, 1700);
          delay(200);
          noTone(buzzer_pin);
          cant_4 = 0;
            }
            
          }
          else{
              if (estadosistema==1)
        {
          Serial.println("Encendido"); 
          estadomotor = 1;
          tone(buzzer_pin, 1700);
          delay(200);
          noTone(buzzer_pin);
        }
            
          }
      
        break;


      
      case '7':
         
            if (estadosistema==1)
        {
          Serial.println("Izquierda"); 
          estadosentidogiro = 0;
          tone(buzzer_pin, 2000);
          delay(200);
          noTone(buzzer_pin);
          delay(200);
          tone(buzzer_pin, 2000);
          delay(200);
          noTone(buzzer_pin);
        }
            
          
        
        break;
      
    
  
      default: 
        break;      
    }
   } 
    // muestra en pantalla todo lo establecido

}
