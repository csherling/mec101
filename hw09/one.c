//1

int rpin = 10; //red
int gpin = 11; //green
int bpin = 12; //blue

void setup(){
  pinMode(rpin, OUTPUT);
  pinMode(gpin, OUTPUT);
  pinMode(bpin, OUTPUT);
}

void loop(){
  digitalWrite(rpin, HIGH); //red on
  digitalWrite(gpin, HIGH); //green on
  delay(500);

  digitalWrite(rpin, LOW); //red off
  digitalWrite(gpin, LOW); //green off
  digitalWrite(bpin, HIGH); //blue on
  delay(500);

  digitalWrite(gpin, HIGH); //green on
  digitalWrite(bpin, LOW); //green off
  delay(500);
}

//2

int ledpin = 10;
int pcell = A0; //photocell
int pval; //photocell value
int ppercent; //pohotcell percent

void setup(){
  Serial.begin(9600); //start serial communication
  pinMode(ledpin, OUTPUT);
}

void loop(){
  pval = analogRead(pcell); //read the photocell
  ppercent = map(pval,0,1023,0,100); //map the value to a percentage
  Serial.print("Resistance Value: "); 
  Serial.println(pval);
  Serial.print("Percent: ");
  Serial.println(ppercent);
  if(ppercent < 50) digitalWrite(ledpin, HIGH); //on if < %50
  else digitalWrite(ledpin, LOW); //off if !< %50
  delay(100);  
}


//3
int motor1Pin = 3; //1A
int motor2Pin = 4; //2A
int motor3Pin = 5; //3A
int motor4Pin = 6; //4A
int speed1Pin = 9; //1,2EN
int speed2Pin = 10; //3,4EN
int speed;

//function declarations
void forward();
void turnLeft();
void reverse();
void turnRight();
void accelerate();
void decelerate();

void setup(){
  //output for motor 1, "left"
  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);
  pinMode(speed1Pin, OUTPUT);
  //output for motor 2 "right"
  pinMode(motor3Pin, OUTPUT);
  pinMode(motor4Pin, OUTPUT);
  pinMode(speed2Pin, OUTPUT);
  //enable motors
  digitalWrite(speed1Pin, HIGH);
  digitalWrite(speed2Pin, HIGH);
}

void loop(){
  forward();
  turnLeft();
  reverse();
  turnRight();
}

void forward(){
  digitalWrite(motor1Pin, HIGH); //left forward
  digitalWrite(motor2Pin, LOW);
  digitalWrite(motor3Pin, LOW); //right forward
  digitalWrite(motor4Pin, HIGH);
  accelerate();
  decelerate();
}
void turnLeft(){
  digitalWrite(motor1Pin, HIGH); //left back
  digitalWrite(motor2Pin, LOW);
  digitalWrite(motor3Pin, HIGH); //right forward
  digitalWrite(motor4Pin, LOW);
  accelerate();
  decelerate();
}
void reverse(){
  digitalWrite(motor1Pin, LOW); //left back
  digitalWrite(motor2Pin, HIGH);
  digitalWrite(motor3Pin, HIGH); //right back
  digitalWrite(motor4Pin, LOW);
  accelerate();
  decelerate();
}
void turnRight(){
  digitalWrite(motor1Pin, LOW); //left forward
  digitalWrite(motor2Pin, HIGH);
  digitalWrite(motor3Pin, LOW); //right back
  digitalWrite(motor4Pin, HIGH);
  accelerate();
  decelerate();
}

void accelerate(){
  for(speed=100;speed<=255;speed++){
    analogWrite(speed1Pin, speed);
    analogWrite(speed2Pin, speed);
    delay(25);
  } //speed up
}
void decelerate(){
  for(speed=255;speed>=100;speed--){
    analogWrite(speed1Pin, speed);
    analogWrite(speed2Pin, speed);
    delay(25);
  } //speed down
}

//4

#include <Servo.h>

Servo myServo; 

int spin = 9; //spin pin to servo
int rpin = 10; //red pin
int gpin = 11; //green pin
int bpin = 12; //blue pun
int tres = A0; //thermoresister
int tval; //thermo val
int tpercent; //thermo percent
int angle; //angle of servo

void setup(){
  Serial.begin(9600); //begin serial communication
  pinMode(spin, OUTPUT);
  pinMode(rpin, OUTPUT);
  pinMode(gpin, OUTPUT);
  pinMode(bpin, OUTPUT);
  myServo.attach(spin);
  if(myServo.attached()) Serial.println("Servo is attached");
  else Serial.println("Servo is not attached");
}

void loop(){
  digitalWrite(rpin, LOW);
  digitalWrite(gpin, LOW);
  digitalWrite(bpin, LOW);

  tval = analogRead(tres); //get thermoresister value
  tpercent = map(tval,0,1023,0,100); //turn it into a percent
  Serial.print("Resistance Value: ");
  Serial.println(tval);
  Serial.print("Percent: ");
  Serial.println(tpercent);
  angle = map(tval,0,1023,0,179); //map tval into an angle in degrees
  myServo.write(angle); //*.write(int) sets degree position of servo
  Serial.print("Servo is at position: ");
  Serial.println(myServo.read());
  if(tpercent > 90){
    digitalWrite(rpin, HIGH);
  }
  else if(tpercent > 60){
    digitalWrite(rpin, HIGH);
    digitalWrite(gpin, HIGH);
  }
  else if(tpercent > 40){
    digitalWrite(gpin, HIGH);
  }
  else if(tpercent > 10){
    digitalWrite(bpin, HIGH);
    digitalWrite(gpin, HIGH);
  }
  else{
    digitalWrite(bpin, HIGH);
  }
  
  delay(100);  
}
