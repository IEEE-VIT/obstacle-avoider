
#include <Servo.h>
#include <NewPing.h>

// our L298N control pins
const int leftForward = 13;
const int leftBackward = 11;
const int rightForward = 10;
const int rightBackward = 12;

// sensor pins
#define trig_pin A1 // analog input 1
#define echo_pin A2 // analog input 2

#define maximum_distance 200
boolean goesForward = false;
int distance = 100;

NewPing sonar(trig_pin, echo_pin, maximum_distance); // sensor function
Servo myServo;                                       // our servo name

void setup()
{

  pinMode(rightForward, OUTPUT);
  pinMode(leftForward, OUTPUT);
  pinMode(leftBackward, OUTPUT);
  pinMode(rightBackward, OUTPUT);

  myServo.attach(5); // our servo pin

  myServo.write(115);
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
}

void loop()
{

  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);

  if (distance <= 20)
  {
    moveStop();
    delay(300);
    Backward();
    delay(400);
    moveStop();
    delay(300);
    distanceRight = lookRight();
    delay(300);
    distanceLeft = lookLeft();
    delay(300);

    if (distance >= distanceLeft)
    {
      Right();
      moveStop();
    }
    else
    {
      Left();
      moveStop();
    }
  }
  else
  {
    Forward();
  }
  distance = readPing();
}

int lookRight()
{
  myServo.write(10);
  delay(500);
  int distance = readPing();
  delay(100);
  myServo.write(115);
  return distance;
}

int lookLeft()
{
  myServo.write(180);
  delay(500);
  int distance = readPing();
  delay(100);
  myServo.write(115);
  return distance;
  delay(100);
}

int readPing()
{
  delay(70);
  int cm = sonar.ping_cm();
  if (cm == 0)
  {
    cm = 250;
  }
  return cm;
}

void moveStop()
{

  digitalWrite(rightForward, LOW);
  digitalWrite(leftForward, LOW);
  digitalWrite(rightBackward, LOW);
  digitalWrite(leftBackward, LOW);
}

void Forward()
{

  if (!goesForward)
  {

    goesForward = true;

    digitalWrite(leftForward, HIGH);
    digitalWrite(rightForward, HIGH);

    digitalWrite(leftBackward, LOW);
    digitalWrite(rightBackward, LOW);
  }
}

void Backward()
{

  goesForward = false;

  digitalWrite(leftBackward, HIGH);
  digitalWrite(rightBackward, HIGH);

  digitalWrite(leftForward, LOW);
  digitalWrite(rightForward, LOW);
}

void Right()
{

  digitalWrite(leftForward, HIGH);
  digitalWrite(rightBackward, HIGH);

  digitalWrite(leftBackward, LOW);
  digitalWrite(rightForward, LOW);

  delay(900);

  digitalWrite(leftForward, HIGH);
  digitalWrite(rightForward, HIGH);

  digitalWrite(leftBackward, LOW);
  digitalWrite(rightBackward, LOW);
}

void Left()
{

  digitalWrite(leftBackward, HIGH);
  digitalWrite(rightForward, HIGH);

  digitalWrite(leftForward, LOW);
  digitalWrite(rightBackward, LOW);

  delay(900);

  digitalWrite(leftForward, HIGH);
  digitalWrite(rightForward, HIGH);

  digitalWrite(leftBackward, LOW);
  digitalWrite(rightBackward, LOW);
}