#include <Servo.h>  
 Servo myservo1;
Servo myservo2;

 int pos = 0;  


 void setup() {    
  myservo1.attach(7);    
 myservo2.attach(8);
 myservo2.write(180);
  myservo1.write(0);     
 } 
 void loop(){
  }
