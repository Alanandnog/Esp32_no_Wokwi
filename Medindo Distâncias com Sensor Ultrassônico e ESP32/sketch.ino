/*
LCD:
GND tá ligado no GND da ESP32
VCC está no 5V
SDA ESTÁ NO PINO 21
SCL ESTÁ NO 22

SENSOR ULTRASOM:
VCC ESTÁ NO 5V
GND ESTÁ NO GND1
TRIGGER NO PINO 32
ECO NO PINO 35

RESISTORES:
TODOS OS ANODOS NO:
1 - PINO19
2 -  PINO18
3 - PINO4
4 - PINO16
5 - PINO 17
TODOS OS CATODOS NO GND1.

depois adiciona a biblioteca do lcd -> liquidcystal i2c

*/

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

//TRIGGER ESTÁ NO PINO 32
#define TRIG 32
// TRIGGER ESTÁ NO PINO 35
#define ECHO 35

void setup()
{
  // initialize the lcd 
  lcd.init(); 
  // ascende a luz de fundo
  lcd.backlight();
  // TRIGGER VAI SER A SAIDA
  pinMode(TRIG, OUTPUT);
  //ECHO VAI SER A ENTRADA
  pinMode(ECHO, INPUT);
  
  pinMode(19, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(16, OUTPUT);
  
}

void loop()
{
  // FAZENDO O PISCA LED
  delayMicroseconds(10);
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG,LOW);

// calculando a distância
  float duracao = pulseIn(ECHO,HIGH);
  // mutiplica pela velocidade do som e divide por 2 por causa  distância 
  float distancia = duracao* 0.034/2;

 
  lcd.setCursor(0,0);
  
  lcd.print("sensor");

  lcd.setCursor(0,1);
  
  lcd.print(distancia);
  delay(100);

  if(distancia < 20){
  digitalWrite(19, HIGH);
  digitalWrite(18, LOW);
  digitalWrite(5, LOW);
  digitalWrite(17, LOW);
  digitalWrite(16, LOW);
  }
  if((distancia > 20)&&(distancia <40)){
  digitalWrite(19, HIGH);
  digitalWrite(18, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(17, LOW);
  digitalWrite(16, LOW);
  }
  if((distancia > 40)&&(distancia <60)){
  digitalWrite(19, HIGH);
  digitalWrite(18, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(17, LOW);
  digitalWrite(16, LOW);
  }
  if((distancia > 60)&&(distancia <80)){
  digitalWrite(19, HIGH);
  digitalWrite(18, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(17, HIGH);
  digitalWrite(16, LOW);
  }
  if((distancia > 80)&&(distancia <100)){
  digitalWrite(19, HIGH);
  digitalWrite(18, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(17, HIGH);
  digitalWrite(16, HIGH);
  }


}