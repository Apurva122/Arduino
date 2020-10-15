#include <Wire.h>

int btn1=8;
int btn2=9;
int btn3=10;
int btn4=11;
int btn5=12;


void setup() {
  // Start the I2C Bus communication
  Wire.begin();
  pinMode(btn1,INPUT_PULLUP);
  pinMode(btn2,INPUT_PULLUP);
  pinMode(btn3,INPUT_PULLUP);
  pinMode(btn4,INPUT_PULLUP);
  pinMode(btn5,INPUT_PULLUP);
  Serial.begin(9600);
}
void loop() {
  
 int btnValue1 = digitalRead(btn1);
 int btnValue2 = digitalRead(btn2);
 int btnValue3 = digitalRead(btn3);
 int btnValue4 = digitalRead(btn4);
 int btnValue5 = digitalRead(btn5);

     int x,y;
  Wire.requestFrom(1,1);
  int c=Wire.read();
  //Serial.print(c);

  if(c!=0)
  {
    x=c;
  }
  delay(200);
  Wire.requestFrom(2,1);
  int d=Wire.read();
 // Serial.print(d);
  if(d!=0)
  {
    y=d;
  }
  if(btnValue1==LOW){
  	int sum=0;
  	sum=x+y;
  Serial.print("sum: ");
  Serial.println(sum);
  }
  else if(btnValue2==LOW){
    int sub=0;
    sub=x-y;
  Serial.print("sub: ");
  Serial.println(sub);
  }
  else if(btnValue3==LOW){
    int mult=0;
    mult=x*y;
  Serial.print("mult: ");
  Serial.println(mult);
  }
  else if(btnValue4==LOW){
    float div=0;
    div=(float)x/(float)y;
  Serial.print("div: ");
  Serial.println(div);
  }
  else if(btnValue5==LOW){
    int mod=0;
    mod=x%y;
  Serial.print("mod: ");
  Serial.println(mod);
  }
  
}
