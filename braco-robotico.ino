#include "VarSpeedServo.h"
/*
 * Definição dos servos do braco robotico
 * 
 * servo1 - Servo da base -             Porta digital 11
 * servo2 - Servo de extensao do braco  Porta digital 10
 * servo3 - Servo da altura do braço    Porta digital 9
 * servo4 - Servo da garra              Porta Digital 6
 */
VarSpeedServo servo1;
VarSpeedServo servo2;
VarSpeedServo servo3;
VarSpeedServo servo4;

/*
 * Definicao das entradas analogicas do Joytick
 * 
 * Joystick Esquerdo        Joystick Direito
 * VRy -> A0                VRy -> A3
 * VRx -> A1                VRx -> A2
 */
int potpin1 = A0;
int potpin2 = A1;
int potpin3 = A2;
int potpin4 = A3;

int val1;
int val2;
int val3;
int val4;

/*
 * Define os valores iniciais de posição de cada servo
 */
static int s1 = 70;
static int s2 = 110;
static int s3 = 100;
static int s4 = 80;

void setup()
{
  Serial.begin(9600);

  // configura os servos de acordo com a definicao acima
  servo1.attach(11); // base, pino digital 11
  servo2.attach(10); // extensao, pino digital 10
  servo3.attach(9); // altura, pino digital 9
  servo4.attach(6); // garra, pino digital 6

  // move todo o braco para posicao inicial
  servo1.write(70);// base
  servo2.write(110);// extensao
  servo3.write(100);// altura
  servo4.write(80);// garra
}
void loop()
{
  // Controle da base do braço
  val1 = analogRead(potpin1);
  if (val1 < 100)
  {
    s1 = s1 - 2;
    if (s1 <= 10)
    {
      s1 = 10;
    }
    servo1.write(s1);
    delay(50);
  }
  if (val1 > 900)
  {
    s1 = s1 + 2;
    if (s1 >= 170)
    {
      s1 = 170;
    }
    servo1.write(s1);
    delay(50);
  }

  // Controle da extensao do braço
  val2 = analogRead(potpin2);
  if (val2 > 900)
  {
    s2 = s2 - 2;
    if (s2 <= 10)
    {
      s2 = 10;
    }
    servo2.write(s2);
    delay(50);
  }
  if (val2 < 100)
  {
    s2 = s2 + 2;
    if (s2 >= 170)
    {
      s2 = 170;
    }
    servo2.write(s2);
    delay(50);
  }

  // Controle da altura do braço
  val3 = analogRead(potpin3);
  if (val3 < 100)
  {
    s3 = s3 - 2;
    if (s3 <= 10)
    {
      s3 = 10;
    }
    servo3.write(s3);
    delay(50);
  }
  if (val3 > 900)
  {
    s3 = s3 + 2;
    if (s3 >= 170)
    {
      s3 = 170;
    }
    servo3.write(s3); 
    delay(50);
  }

  // Controle da garra do braço
  val4 = analogRead(potpin4);
  if (val4 < 100)
  {
    s4 = s4 - 2;
    if (s4 <= 80)
    {
      s4 = 80;
    }
    servo4.write(s4);
    delay(50);
  }
  if (val4 > 900)
  {
    s4 = s4 + 2;
    if (s4 >= 130)
    {
      s4 = 130;
    }
    servo4.write(s4);
    delay(50);
  }

  // exibe os valores analogicos na tela
  Serial.print(val1);
  Serial.print("  :  ");
  Serial.print(val2);
  Serial.print("  :  ");
  Serial.print(val3);
  Serial.print("  :  ");
  Serial.print(val4);
  Serial.println();
}
