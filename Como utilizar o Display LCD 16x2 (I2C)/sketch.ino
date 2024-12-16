/*GND ligado no GND
   VCC ligado no 5V
SDA  ligado no pino 21
SCL ligado no pino 22

pegar a biblioteca do LCD : liquid crytal

Potenciomentro:
Sig(valor maximo que não pode chegar) no pino 34
VCC no 3v3
GND NO GND


*/
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  // inicializa o lcd
  lcd.init();                      
  // inicializa o backlight
  lcd.backlight();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //lcd.setCursor(3,0);
  // lê o valor no pino 34
  int Valor = analogRead(34);
  Serial.println(Valor);
  
  // 100 dividido por 4095
  float Nivel = Valor * 0.0244200244200244;
  lcd.print(Nivel);
  lcd.setCursor(5,0);
  //lcd.clear();
  delay(1); // this speeds up the simulation
}
