
class control{

  // define variables 
  const int analogMin = 420;// both used for determining "dead zone"
  const int analogMax = 530;
  const int CLICKDELAY = 200;
  int xPin;
  int yPin;
  int cPin;
  //Private Methods
  int MoveDirection(int val, int move);
  int MoveDirection(int val);

public:
   control(int xPin,int yPin,int cPin);
  bool GetClick();

  int PinMove(int pin,int move);
  int PinMove(int pin);

  bool AnalogMove(int* xDir, int* yDir,int  move);

};
