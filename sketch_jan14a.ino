
#define LEFTFORWARD 5
#define LEFTBACKWARD 4
#define RIGHTFORWARD 3
#define RIGHTBACKWARDS 2
#define SPEEDA 9
#define SPEEDB 10
#define PHOTOL A1
#define PHOTOR A0

void GoForward(){
  analogWrite(SPEEDA, 50);
  analogWrite(SPEEDB, 50);
  digitalWrite(LEFTBACKWARD, HIGH);
  digitalWrite(RIGHTBACKWARDS, HIGH);
  digitalWrite(LEFTFORWARD, LOW);
  digitalWrite(RIGHTFORWARD, LOW);
}

void GoLeft(){
  analogWrite(SPEEDA, 50);
  analogWrite(SPEEDB, 0 );
  digitalWrite(LEFTFORWARD, LOW);
  digitalWrite(RIGHTFORWARD, HIGH);
  digitalWrite(LEFTBACKWARD, HIGH);
  digitalWrite(RIGHTBACKWARDS, LOW);
  }
void GoRight(){
  analogWrite(SPEEDA, 0);
  analogWrite(SPEEDB, 50);
  digitalWrite(LEFTFORWARD, HIGH);
  digitalWrite(RIGHTFORWARD, LOW);
  digitalWrite(LEFTBACKWARD, LOW);
  digitalWrite(RIGHTBACKWARDS, HIGH);
  }

void Stop(){
  digitalWrite(LEFTFORWARD, LOW);
  digitalWrite(RIGHTFORWARD, LOW);
  digitalWrite(LEFTBACKWARD, LOW);
  digitalWrite(RIGHTBACKWARDS, LOW);
}
 int checkEdge(){
 int value1 = analogRead(PHOTOL);
 int value2 = analogRead(PHOTOR);
 int LRSignal;
 if(value1>=300){
  return LRSignal = 1;
 }
 else if (value2>=300){
  return LRSignal = 2;
 }
else return LRSignal = 0;
}
void setup() {
  pinMode(LEFTFORWARD, OUTPUT);
  pinMode(LEFTBACKWARD, OUTPUT);
  pinMode(RIGHTFORWARD, OUTPUT);
  pinMode(RIGHTBACKWARDS, OUTPUT);
  digitalWrite(LEFTFORWARD, LOW); // digital write can be low or high depending on       digitalWrite(LEFTBACKWARD, LOW); // digiital low is off high is on 
  digitalWrite(RIGHTFORWARD, LOW);
  digitalWrite(RIGHTBACKWARDS, LOW);
  pinMode(PHOTOL, INPUT);
  pinMode(PHOTOR, INPUT);
  delay(500); //LOW.5 Seconds
}
void loop() {
  if ((checkEdge())== 1){
    GoRight();
  }
  else if ((checkEdge()) == 2){
    GoLeft();
    }
    else GoForward();
 
}
