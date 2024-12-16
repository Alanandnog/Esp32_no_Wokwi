/*
NTC:

GND ligado no GND1
VCC ligado no 3.3V
Saida ligado no 35

LCD:
GND ligado no GND
VCC ligado no 5V
SDA ligado no 21
SLC(clock) no 22(´pino de clock do esp32)

pegar a biblioteca do liquidi2c

*/
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4); 

const float BETA = 3950; // Deve corresponder ao coeficiente beta do termistor


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
   lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  
}

void loop() {
  
int analogValue = analogRead(35);

//esp vai até 4095 bits
float celsius = 1 / (log(1 / (4095. / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15;
String mensagem = ("Temperatura" +  String(celsius) + (char)223 + "C");
Serial.println(celsius);
lcd.setCursor(3,0);
lcd.print(mensagem);
}
