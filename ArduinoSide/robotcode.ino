#include <SoftwareSerial.h>

SoftwareSerial bt(10, 11);

#define BAUD 9600

#define SPEED 250
#define REDUCED_SPEED 50

//Enumeration for direction
enum DIRECTION {FORWARD, LEFT, RIGHT, BACKWARD, NOWHERE};

//At first robot will do nothing
DIRECTION Direction = NOWHERE;

//Motor pins
int enableA = 9;
int inputA1 = 3;
int inputA2 = 8;

int enableB = 5;
int inputB1 = 7;
int inputB2 = 6;

//incoming command
String command;

//Go forward
void forward(int speed){
  //Setting the speed;
  analogWrite(enableA, speed);
  analogWrite(enableB, speed);
  
  digitalWrite(inputA1, LOW);
  digitalWrite(inputA2, HIGH);

  digitalWrite(inputB1, LOW);
  digitalWrite(inputB2, HIGH);

}

void left(int speed){
  analogWrite(enableB, REDUCED_SPEED);
  analogWrite(enableA, speed);

  digitalWrite(inputA1, LOW);
  digitalWrite(inputA2, HIGH);

  digitalWrite(inputB1, LOW);
  digitalWrite(inputB2, HIGH);
}

void right(int speed){
  analogWrite(enableB, speed);
  analogWrite(enableA, REDUCED_SPEED);

  digitalWrite(inputA1, LOW);
  digitalWrite(inputA2, HIGH);

  digitalWrite(inputB1, LOW);
  digitalWrite(inputB2, HIGH);
}

void stop(void){
  digitalWrite(enableA, LOW);
  digitalWrite(enableB, LOW);

  digitalWrite(inputA1, LOW);
  digitalWrite(inputA2, LOW);

  digitalWrite(inputB1, LOW);
  digitalWrite(inputB2, LOW);
}

void setup() {
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  pinMode(enableA, OUTPUT);
  pinMode(enableB, OUTPUT);
  pinMode(inputA1, OUTPUT);
  pinMode(inputA2, OUTPUT);
  pinMode(inputB1, OUTPUT);
  pinMode(inputB2, OUTPUT);
  Serial.begin(BAUD);
  bt.begin(BAUD);
  
}

void loop() {
  if (bt.available() > 0){
    command = bt.readStringUntil('\n');
  }

  
    if (command.equals("F")) forward(SPEED);
    else if (command.equals("L")) left(SPEED);
    else if (command.equals("R")) right(SPEED);
    else if (command.equals("S")) stop();
  
}
