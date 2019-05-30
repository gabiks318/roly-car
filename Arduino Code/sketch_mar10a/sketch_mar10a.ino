#include <SoftwareSerial.h>
#include <PololuQik.h>

#define RxMotorPin 4
#define TxMotorPin 5
#define ResetMotorPin 3

#define RxRaspi 12
#define TxRaspi 13

PololuQik2s12v10 qik(RxMotorPin,TxMotorPin,ResetMotorPin);
SoftwareSerial raspi(RxRaspi,TxRaspi);

void motor_write(byte command)
{
  if(command==49) //forward
  {
   qik.setM0Speed(-127);
   qik.setM1Speed(127); 
  }
  else if(command==50) //backward
  {
   qik.setM0Speed(127);
   qik.setM1Speed(-127); 
  }
  else if(command==51) //left
  {
   qik.setM0Speed(-127);
   qik.setM1Speed(-127); 
  }
  else if(command==52) //right
  {
   qik.setM0Speed(127);
   qik.setM1Speed(127); 
  }
  else if(command==48) //stop
  {
   qik.setM0Speed(0);
   qik.setM1Speed(0); 
  }
}

void setup() {
  qik.init();
  Serial.begin(9600);
  pinMode(RxRaspi,INPUT);
  pinMode(TxRaspi,OUTPUT);
  raspi.begin(9600);
}

void loop() {
 if(raspi.available())
 {
  byte comm;
  comm=raspi.read();
  motor_write(comm);
  Serial.println(comm);
 }
}
