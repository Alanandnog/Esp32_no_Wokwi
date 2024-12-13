/* LCD 
GND ligado no GND2
vcc ligado no 5V
SDA no pino 21
SCL no pino 22

Celula de carga(HX711):
GND ligado no GND1
VCC ligando no 3v3
Dt(pino de dados) ligado no pino 13
clock ligado no 14

pegar a biblioteca do LCD =  liquicrystal i2c
pegar a biblioteca do hx710 =  hx710
*/
#include <LiquidCrystal_I2C.h>
#include "HX711.h"

HX711 scale;


LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

int valor;

int peso;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  // ascende a luz de fundo
  lcd.init();                      
  // initialize the lcd 
  lcd.backlight();
  // inicializa o hx711 nos pinos 13 e 14
  scale.begin(13, 14);
  lcd.setCursor(0,0);
  //printa o hello world no lcd
  lcd.print("Inicializando");
  delay(1000);
  Serial.println("celula de carga");
}

void loop() {
  valor = scale.get_units(), 1;
  peso = map(valor,0,2100,0,5000);
  // printa o valor da celula de carga no lcd
  Serial.println(peso);
  // limpa o lcd
  lcd.clear();
  lcd.setCursor(0,0);
  //printa o hello world no lcd
  lcd.print("celula de carga");
  // coluna, linha
  lcd.setCursor(0,1);
  lcd.print("Peso :");
  lcd.print(peso);
  delay(1000); // this speeds up the simulation
}
