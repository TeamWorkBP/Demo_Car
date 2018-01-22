#include <SoftwareSerial.h>
#include "Motor.h"

Motor Left(5, 6);
Motor Right(9, 10);

int aux = 0;
char cmd = '\n';
bool isNegative = false;

int Vc = 0;
int Wc = 0;

int W1 = 0;
int W2 = 0;

SoftwareSerial BT(2,3);

void setup()
{
  BT.begin(9600);
  Serial.begin(9600);
}

void loop()
{
  if(cmd_check())
  {
  	proccess();
  	if(W2 < 0){
  		Left.reverse(-W2);
  	}
  	else{
  		Left.forward(W2);
  	}

  	if(W1 < 0){
  		Right.reverse(-W1);
  	}
  	else{
  		Right.forward(W1);
  	}
  }
}

bool cmd_check()
{
  while(BT.available())
  {
  	if (isAlpha(BT.peek()) && cmd == '\n')
    {
      char c = BT.read();
      isNegative = isLowerCase(c);
      cmd = isNegative ? c - 'a' + 'A' : c;
    }
    else if (cmd != '\n')
    {
    	int num = BT.read();
      switch (cmd)
      {
        case 'V':
        	if(aux == 0){
        		aux++;
        		Vc = isNegative ? -num : num;
        	}
        	break;
        case 'W':
        	if(aux == 1){
        		aux++;
        		Wc = isNegative ? -num : num;
        	}
        	break;
        default:
        	aux = 0;
      }
      cmd = '\n';
    }
  }
  return(aux == 2);
}

void proccess(){
	if(aux == 2){
  	    aux = 0;
  }
	W1 = constrain(Vc+Wc, -255, 255);
	W2 = constrain(Vc-Wc, -255, 255);
}
