#include "control.h"
#include "Arduino.h"
using namespace std;


//*********************************************************** 
//Function  Move Direction(int val, int move);
//purpose: Return a single axis dimention and retrun it's direcction* speed
//Perameters: int val --> this is the analog read value of a pin
//	      int move --> speed of movemnet for the computer to return
//Returns: the direction of movemet(+ or -) * the move speed value
//**************************************************************
int control::MoveDirection(int val, int move){
  
  if (val < analogMin){                 
    move *= -1;
    }
  else if (val > analogMax){
    move *= 1; 
    }
  else{
  move *= 0;    
  }
  return move;

}
/// this is a version of move direciton that just outputs 1 or -1 
int control::MoveDirection(int val){
 int move = 1; 
  if (val < analogMin){                 
    move *= -1;
    }
  else if (val > analogMax){
                    
    move *= 1; 
    }
  else{
  move *= 0;    
  }
  return move;

}

control::control(int x,int y,int c){
  xPin = x;
  yPin = y;
  cPin = c;
 
}

bool control::GetClick(){
int yval = analogRead(yPin);
int push = analogRead(cPin);
if(yval >= 20){
 if (push == 0) {
      return true;
      delay(CLICKDELAY);
    }
}
return false;
}


int control::PinMove(int pin,int move){
  int val = analogRead(pin);
  return MoveDirection(val, move);
}

int control::PinMove(int pin){
  int val = analogRead(pin);
  return MoveDirection(val);
}
//*********************************************************** 
//Function  AnologMove(int xPin,int yPin, int* xDir, int* yDir,int  move);
//purpose: turn a alogo stick into a gestures
//Perameters: int xPin - x anologe pin for joystick
//		int yPin - y anologe pin for joystick
//		int cPin - this is where click pin is stored
//		int* xDir - This value is where xDir will be stored
//		int* yDir - this is where yDir will be stored
//		int move - this is where move value will be stored
//	      int move --> speed of movemnet for the computer to return
//Returns: the direction of movemet(+ or -) * the move speed value
//**************************************************************
bool control::AnalogMove(int* xDir, int* yDir,int  move){

  *xDir = PinMove(xPin,move);
  *yDir = PinMove(yPin, move);
  
  return GetClick();

}
