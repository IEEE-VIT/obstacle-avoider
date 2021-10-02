// Define the pins used to control
#define trigPin 13
#define echoPin 12
// Defines variables used

long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  //Set the digital pins' pinMode as INPUT or OUTPUT as needed.
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
 }
 double calcDistance(){
  /*  Use any of the IR proximity sensor or Ultrasonic sensor to find the distance of obstacle in cms
   *  You can refer to the sample codes given in the repository. 
   */
   return (distance);
 }
 
 int isObstacle(int distance){
  /* write a function to check if any obstacle is there in the range of 10 cm from the bot.  
   * If obstacle is there, return logic 1 
   * if obstacle is not there, return logic 0
   */
   
  // Sound signal is sent to measure the distance
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  
  //Measuring the duration of the reflecting sound
  duration = pulseIn(echoPin, HIGH);

  //Calculte the distance(in cm) from the object
  distance = (duration/2)/29.1;
  
  //display the duration and dis
  Serial.print(distance);

  //returning 1 if object is less than 10cm, else return 0
  if (distance <= 10 )
    {return 1;}
   else
    {return 0;}
 }

 int moveSpeed(int Speed)
 {
  /*
   * Code to desired robot speed
   * Calculate rpm and use diameter of wheel to get the estimate speed of robot.
   */
 }

 void changeDirection(String dir,int angle)
 {
  /*
   * Code to change direction i.e, To rotate left , right or u_turn
   * On an advance level you can make this function to rotate robot to an specific angle (degrees) i.e , 30 deg, 60 deg
   */
 }

 void failSafe()
 {
  /*
   * Function to stop the car in case any unfortunate failure happens eg : Motor driver is fried etc..
   * Use a voltage controlled switch to cut off power when actual speed is not the desired speed.
   */
 }

 double distanceMoved(int Speed)
 {
  /*
   * Code to calculate estimate distance moved by car using motor speed.
   */
 }

 void Move(int Speed)
 {
  /* Function to make the bot move forward or backwards
   *  If Speed>0 move forwards else move Backwards
   */
 }
 
void loop() {
  // put your main code here, to run repeatedly:
  /*
   * Logic and implementation of functions to effectively move the robot forward avoiding obstacle met.
   * i.e ,
   * Move robot ,if it encounters obstacle handle the situation , move again. 
   */

}

