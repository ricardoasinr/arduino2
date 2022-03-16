
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


void setup() { 
  //////////////////////////////////////
  Wire.begin();         // inicializa bus I2C
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C); // inicializa pantalla con direccion 0x3C
  oled.clearDisplay();
  oled.display();
  //////////////////////////////////////
  Serial.begin(9600);    // inicializa comunicacion serie a 9600 bps
 
  ///////////////////////////////////////////////////////
  pinMode(buzzer_pin, OUTPUT);
  ///////////////////////////////////////////////////////

}
 
void loop() {
 
// PRUEBA DE BUZZER PASIVO
//tone(buzzer_pin, 1523);
//  delay(200);
//  noTone(buzzer_pin);
//  delay(2000); 

// PRUEBA DE TECLADO MATRICIAL Y PANTALLA OLED
 tecla= teclado.getKey(); // obtiene tecla presionada y asigna el valor a TECLA  
  if (tecla)
  {
    Serial.println(tecla);
    delay(10);
    switch (tecla)
    {
      case '*':       
        oled.clearDisplay();      
        oled.setTextColor(WHITE);   
        oled.setCursor(50, 25);     
        oled.setTextSize(2);
        oled.print("DO");
        tone(buzzer_pin, 523.25);
        delay(200);
        noTone(buzzer_pin);
        delay(200); 
        oled.display();
        //delay(200);
        break;
       
      case '0':
        oled.clearDisplay();      
        oled.setTextColor(WHITE);   
        oled.setCursor(25, 25);    
        oled.setTextSize(2);      
        oled.print("Melodia");
        oled.display();
        tone(buzzer_pin, 523.25);
        delay(200);
        noTone(buzzer_pin);
        delay(200); 
        tone(buzzer_pin, 523.25);
        delay(200);
        noTone(buzzer_pin);
        delay(200); 
        tone(buzzer_pin, 587.33);
        delay(200);
        noTone(buzzer_pin);
        delay(200);
        tone(buzzer_pin, 587.33);
        delay(200);
        noTone(buzzer_pin);
        delay(200);
        tone(buzzer_pin, 659.26);
        delay(200);
        noTone(buzzer_pin);
        delay(200); 
        tone(buzzer_pin, 659.26);
        delay(200);
        noTone(buzzer_pin);
        delay(200); 
        tone(buzzer_pin, 698.46);
        delay(200);
        noTone(buzzer_pin);
        delay(200); 
        tone(buzzer_pin, 698.46);
        delay(200);
        noTone(buzzer_pin);
        delay(200);
        tone(buzzer_pin, 783.99);
        delay(200);
        noTone(buzzer_pin);
        delay(200);
          tone(buzzer_pin, 783.99);
        delay(200);
        noTone(buzzer_pin);
        delay(200);
        tone(buzzer_pin, 698.46);
        delay(200);
        noTone(buzzer_pin);
        delay(200); 
        tone(buzzer_pin, 698.46);
        delay(200);
        noTone(buzzer_pin);
          delay(200);
        tone(buzzer_pin, 659.26);
        delay(200);
        noTone(buzzer_pin);
        delay(200); 
        tone(buzzer_pin, 659.26);
        delay(200);
        noTone(buzzer_pin);
        delay(200); 
           delay(200); 
        tone(buzzer_pin, 587.33);
        delay(200);
        noTone(buzzer_pin);
        delay(200);
        tone(buzzer_pin, 587.33);
        delay(200);
        noTone(buzzer_pin);
        delay(200);
         tone(buzzer_pin, 523.25);
        delay(200);
        noTone(buzzer_pin);
        delay(200); 
        tone(buzzer_pin, 523.25);
        delay(400);
        noTone(buzzer_pin);
        delay(200); 
        
        //delay(200);
        break;
        
      case '#':
        oled.clearDisplay();      
        oled.setTextColor(WHITE);   
        oled.setCursor(50, 25);     
        oled.setTextSize(2);      
        
        oled.print("RE");
        
        tone(buzzer_pin, 587.33);
        delay(200);
        noTone(buzzer_pin);
        delay(200);

         
        oled.display();


        
        //delay(200);
        break;

      case 'D':
        oled.clearDisplay();      
        oled.setTextColor(WHITE);   
        oled.setCursor(50, 25);     
        oled.setTextSize(2);      
        oled.print("MI");
        tone(buzzer_pin, 659.26);
        delay(200);
        noTone(buzzer_pin);
        delay(200); 
        oled.display();
        //delay(200);
        break;
      default: 
        break;      
    }
   } 



}
