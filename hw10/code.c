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
