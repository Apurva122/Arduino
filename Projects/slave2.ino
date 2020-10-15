#include<Wire.h>
#include <Keypad.h>

const byte ROWS = 4;//no. of rows on keypad 
const byte COLS = 4;//no. of columns on the keypad
char value;
bool firstNumState = true;
String firstNum="";


char keymap[ROWS][COLS] = 
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

//Keypad connections to the arduino
byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

//initializes an instance of the keypad class
Keypad customKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, ROWS, COLS); 

void setup(){
  Wire.begin(2);
  Wire.onRequest(requestEvent);
  Serial.begin(9600);
}
  
void loop(){
  
  char keypressed = customKeypad.getKey();
  value = keypressed;
  if (keypressed != NO_KEY && (keypressed=='1'||keypressed=='2'||keypressed=='3'||keypressed=='4'||keypressed=='5'||keypressed=='6'||keypressed=='7'||keypressed=='8'||keypressed=='9'||keypressed=='0')){
    /*do{
      firstNum = firstNum+keypressed;
      Serial.println(firstNum);
    }while(keypressed=='A');*/
    
    
     if (firstNumState == true) {
      firstNum = firstNum + keypressed;
       Serial.println(firstNum);
    }
    /*else {
      secondNum = secondNum + keypressed;
      Serial.print(keypressed);
    }*/
  }
  if(keypressed=='C'){
    firstNum="";
  }
  //Serial.println(value);
  //delay(500);
  //firstNum.toInt();
}

//request event
void requestEvent()
{
  Wire.write(firstNum.toInt());
}

