
//////////////////////////////////////////////////////
#include <Adafruit_GFX.h>   // libreria para pantallas graficas
#include <Adafruit_SSD1306.h>   // libreria para controlador SSD1306 
#define ANCHO 128     // reemplaza ocurrencia de ANCHO por 128
#define ALTO 64       // reemplaza ocurrencia de ALTO por 64
#define OLED_RESET 4      // necesario por la libreria pero no usado
Adafruit_SSD1306 oled(ANCHO, ALTO, &Wire, OLED_RESET);  // crea objeto
//////////////////////////////////////////////////////

///////////////////////////////////////////////////////
int sw1;
#define sw1_pin 9


///////////////////////////////////////////////////////



void setup() { 
  //////////////////////////////////////
  Wire.begin();         // inicializa bus I2C
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C); // inicializa pantalla con direccion 0x3C
  oled.clearDisplay();
  oled.display();
 
  ///////////////////////////////////////////////////////
  pinMode(sw1_pin, INPUT);
 
}
 
void loop() {
  


// PRUEBA DE DIPSWITCH Y PANTALLA OLED
  sw1=digitalRead(sw1_pin);
  
  oled.clearDisplay();      // limpia pantalla
  oled.setTextColor(WHITE);   // establece color al unico disponible (pantalla monocromo)
  
  oled.setCursor(0, 0);     // ubica cursor en inicio de coordenadas 0,0
  oled.setTextSize(2);      // establece tamano de texto en 1
  oled.print("SW1: ");  // escribe en pantalla el texto
  oled.print(sw1);
  oled.display();     // muestra en pantalla todo lo establecido



}
