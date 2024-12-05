/* 
Display ILI9341
VCC(1pino) conectado com os 5 volts
GND(2) conectado ao GND mais perto
CS(select Chip(3) conectado no pino 5)
RST(reset(4)) conectado no pino 4
D/C(5(pino de daodos) colocado no pino 2)
MOSI no 23
SLK(CLOCK) NO 18
não ligamos o led
MISO para o 19

instale a biblioteca do adafruit ILI9341
*/
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

//pino de dados está no 2
#define TFT_DC 2
// pino de seleção do chip está no 5
#define TFT_CS 5

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

void setup() {
  //inicializa o lcd
  tft.begin();
  //rotaciona do texto
  tft.setRotation(1);
  // aonde o cursor vai aparecer, o primeiro é a linha e o segundo é a coluna
  tft.setCursor(0, 20);
  // cor do texto do cursor
  tft.setTextColor(ILI9341_RED);
  //tamanho da letra do cursor
  tft.setTextSize(3);
  tft.println("experimento 1");

  tft.setCursor(0, 60);
  tft.setTextColor(ILI9341_GREEN);
  tft.setTextSize(2);
  tft.println("isso é tudo pessoal");
}

void loop()
{ 
// le uma variavel analogica
int Dados = analogRead(34);


  tft.setCursor(0, 120);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(4);
 
  tft.println(Dados);
// VCC do potenciomentro ligando o 3V3
// GND do potenciometro ligando no GND1
// SIG está no 34

//delay de 1 segundo para atualizar a informação
delay(1000);
//preenche um retângulo que fica atualizando nas cordenadas que eu quero, (x,y,altura, largura,cor)
tft.fillRect(0,120,140,70,ILI9341_BLACK);
//os dados vão vir de acordo com o potenciomentro
}