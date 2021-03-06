//3
int motor1Pin = 2; //1A
int motor2Pin = 3; //2A
int motor3Pin = 4; //3A
int motor4Pin = 5; //4A
int speed1Pin = 10; //1,2EN
int speed2Pin = 11; //3,4EN
int rls = 12;
int lls = 13;
int buz = 9;
int led = 8;
boolean risw;
boolean lesw;
int speed;

//function declarations
void forward();
void turnLeft();
void reverse();
void turnRight();
void accelerate();
void decelerate();

void setup(){
  Serial.begin(9600);
  //output for motor 1, "left"
  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);
  pinMode(speed1Pin, OUTPUT);
  //output for motor 2 "right"
  pinMode(motor3Pin, OUTPUT);
  pinMode(motor4Pin, OUTPUT);
  pinMode(speed2Pin, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(buz, OUTPUT);
  pinMode(rls, INPUT);
  pinMode(lls, INPUT);
  //enable motors
  digitalWrite(speed1Pin, HIGH);
  digitalWrite(speed2Pin, HIGH);
}

void loop(){
  Serial.println("outwhile");
  risw = digitalRead(rls);
  lesw = digitalRead(lls);
  forward();
  while(!risw && !lesw){
    risw = digitalRead(rls);
    lesw = digitalRead(lls);
    if(risw || lesw) {
      Serial.println("detect");
      break;  
    }
    Serial.println("inwhile");
  }
  if(risw){
    Serial.println("right");
    reverse();
    analogWrite(buz, 128);
    for(int i = 0; i<5;i++){
      digitalWrite(led, HIGH);
      delay(500);
      digitalWrite(led, LOW);
      delay(500);
    }
    analogWrite(buz, 0);

    turnLeft();
    delay(5000);
  }
  else if(lesw){
    Serial.println("left");
    reverse();
    analogWrite(buz, 128);
    for(int i = 0; i<5;i++){
      digitalWrite(led, HIGH);
      delay(500);
      digitalWrite(led, LOW);
      delay(500);
    }
    analogWrite(buz, 0);

    turnRight();
    delay(5000);
  }
  digitalWrite(buz, LOW);
}

void stop(){
  analogWrite(speed1Pin, 0);
  analogWrite(speed2Pin, 0);

}

void forward(){
  digitalWrite(motor1Pin, HIGH); //left forward
  digitalWrite(motor2Pin, LOW);
  digitalWrite(motor3Pin, LOW); //right forward
  digitalWrite(motor4Pin, HIGH);
  analogWrite(speed1Pin, 255);
  analogWrite(speed2Pin, 255);
}
void turnLeft(){
  digitalWrite(motor1Pin, HIGH); //left back
  digitalWrite(motor2Pin, LOW);
  digitalWrite(motor3Pin, HIGH); //right forward
  digitalWrite(motor4Pin, LOW);
  analogWrite(speed1Pin, 255);
  analogWrite(speed2Pin, 255);
}
void reverse(){
  analogWrite(buz, 128);
  digitalWrite(motor1Pin, LOW); //left back
  digitalWrite(motor2Pin, HIGH);
  digitalWrite(motor3Pin, HIGH); //right back
  digitalWrite(motor4Pin, LOW);
  analogWrite(speed1Pin, 255);
  analogWrite(speed2Pin, 255);
}
void turnRight(){
  digitalWrite(motor1Pin, LOW); //left forward
  digitalWrite(motor2Pin, HIGH);
  digitalWrite(motor3Pin, LOW); //right back
  digitalWrite(motor4Pin, HIGH);
  analogWrite(speed1Pin, 255);
  analogWrite(speed2Pin, 255);
}

void accelerate(){
  for(speed=231;speed<=255;speed++){
    analogWrite(speed1Pin, speed);
    analogWrite(speed2Pin, speed);
    digitalWrite(led, HIGH);
    delay(40);
    digitalWrite(led, LOW);
    delay(40);
  } //speed up
}
void decelerate(){
  for(speed=255;speed>=231;speed--){
    analogWrite(speed1Pin, speed);
    analogWrite(speed2Pin, speed);
    digitalWrite(led, HIGH);
    delay(40);
    digitalWrite(led, LOW);
    delay(40);
  } //speed down
}

