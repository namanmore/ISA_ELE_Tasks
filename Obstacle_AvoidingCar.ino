int M_Left_P1= 7,M_Left_P2=8 ,M_Right_P1= 13,M_Right_P2=12 , speedLeft =9 ,speedRight =11 ;
int dist,TIME,trig= 5,echo=6;
void setup()
{
pinMode(M_Left_P1,OUTPUT);
pinMode(M_Left_P2,OUTPUT);
pinMode(M_Right_P1,OUTPUT);
pinMode(M_Right_P2,OUTPUT);
pinMode(speedLeft,OUTPUT);
pinMode(speedRight,OUTPUT);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
digitalWrite(M_Left_P1,LOW);
digitalWrite(M_Left_P2,LOW);        // Initializing the Motors to LOW for no Motion
digitalWrite(M_Right_P1,LOW);
digitalWrite(M_Right_P2,LOW);
Serial.begin(9600);
}
void cal()
{
digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);          // Function to Calculate the distance of the obstacle from the sensor
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  TIME=pulseIn(echo,HIGH);
  dist= TIME* (0.03/2); 
}
void forward()
{
  cal();
  while(dist>30)
  {
   analogWrite(speedLeft,255);      // Making the speed of both the motors maximum
analogWrite(speedRight,255);
digitalWrite(M_Left_P1,HIGH);
digitalWrite(M_Left_P2,LOW);          // Forward Motion of the Car
digitalWrite(M_Right_P1,HIGH);
digitalWrite(M_Right_P2,LOW);
cal();
}
digitalWrite(M_Left_P1,LOW);
digitalWrite(M_Left_P2,LOW);            // When an object is present, stopping the CAR.
digitalWrite(M_Right_P1,LOW);
digitalWrite(M_Right_P2,LOW);

}

void rotateantiClockwise()
{
  cal();
  while(dist<=30)
  {
  analogWrite(speedLeft,200);
analogWrite(speedRight,200);         // Reducing the speed when rotating a bit
digitalWrite(M_Left_P1,LOW);
digitalWrite(M_Left_P2,HIGH);
digitalWrite(M_Right_P1,HIGH);
digitalWrite(M_Right_P2,LOW);
cal();
}
digitalWrite(M_Left_P1,LOW);
digitalWrite(M_Left_P2,LOW);
digitalWrite(M_Right_P1,LOW);      // Stopping the CAR when no object is present
digitalWrite(M_Right_P2,LOW);
}
void loop()
{
  cal();
  if(dist>30)
  forward();
  else
  {
  rotateantiClockwise();
}
}
