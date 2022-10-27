  #include <Stepper.h> 
#include <SoftwareSerial.h>
#include <Wire.h>
#include<ds3231.h>
#define ADDRESS 0x60 //defines address of compass


int numberofstep = 48*64; 
int time=5; 
struct ts t;                            
Stepper motor(numberofstep,9,11,10,6);    // we use pins 9, 11, 10, 6        
int motor1pin1 = 2;
int motor1pin2 = 3;
int tm=0,hr8,hr9,hr10,hr11,hr12,hr13,hr14,hr15,hr16,hr17;
void setup() 
{ 
  Serial.begin(9600);
  Wire.begin();
  motor.setSpeed(2); // we set motor speed at 9
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  Wire.begin();
  DS3231_init(DS3231_CONTROL_INTCN);
  t.hour=10; 
  t.min=59;
  t.sec=0;
  t.mday=18;
  t.mon=1;
  t.year=2022;
  DS3231_set(t);
}
void loop() 
{
  DS3231_get(&t);
  Serial.print("Date : ");
  Serial.print(t.mday);
  Serial.print("/");
  Serial.print(t.mon);
  Serial.print("/");
  Serial.print(t.year);
  Serial.print("\t Hour : ");
  Serial.print(t.hour);
  Serial.print(":");
  Serial.print(t.min);
  Serial.print(".");
  Serial.println(t.sec);
  
  byte highByte;
  byte lowByte;
  
  Wire.beginTransmission(ADDRESS);      //starts communication with cmps03
  Wire.write(2);                         //Sends the register we wish to read
  Wire.endTransmission();

  Wire.requestFrom(ADDRESS, 2);        //requests high byte
  while(Wire.available() < 2);         //while there is a byte to receive
  highByte = Wire.read();           //reads the byte as an integer
  lowByte = Wire.read();
  int bearing = ((highByte<<8)+lowByte)/10; 
  Serial.println("Angle:");
  Serial.println(bearing);
   delay(5000);

  if (t.hour > 12 && t.hour < 18 && bearing >0 && bearing <10)
  {
     motor.step(283);    
  }
  if (t.hour > 12 && t.hour < 18 && bearing >10 && bearing <20)
  {
     motor.step(267);    
  }
  if (t.hour > 12 && t.hour < 18 && bearing >20 && bearing <30)
  {
     motor.step(250);    
  }
  if (t.hour > 12 && t.hour < 18 && bearing >30 && bearing <40)
  {
     motor.step(233);    
  }
  if (t.hour > 12 && t.hour < 18 && bearing >40 && bearing <50)
  {
     motor.step(217);    
  }
  if (t.hour > 12 && t.hour < 18 && bearing >50 && bearing <60)
  {
     motor.step(200);    
  }
  if (t.hour > 12 && t.hour < 18 && bearing >60 && bearing <70)
  {
     motor.step(183);    
  }
  if (t.hour > 12 && t.hour < 18 && bearing >70 && bearing <80)
  {
     motor.step(167);    
  }
  if (t.hour > 12 && t.hour < 18 && bearing >80 &&bearing <90)
  {
     motor.step(150);    
  }
  if (t.hour > 12 && t.hour < 18 && bearing >90 && bearing <100)
  {
     motor.step(128);    
  }
  if (t.hour > 12 && t.hour < 18 && bearing >100 && bearing <110)
  {
     motor.step(116);    
  }
  if (t.hour > 12 && t.hour < 18 && bearing >110 && bearing <120)
  {
     motor.step(100);    
  }
  if (t.hour > 12 && t.hour < 18 && bearing >120 && bearing <130)
  {
     motor.step(83);    
  }
  if (t.hour > 12 && t.hour < 18 && bearing >130 && bearing <140)
  {
     motor.step(66);    
  }
  if (t.hour > 12 && t.hour < 18 && bearing >140 && bearing <150)
  {
     motor.step(50);    
  }
  if (t.hour > 12 && t.hour < 18 && bearing >150 && bearing <160)
  {
     motor.step(33);    
  }
  if (t.hour > 12 && t.hour < 18 && bearing >160 && bearing <170)
  {
     motor.step(16); 
  }
   if (t.hour > 12 && t.hour < 18 && bearing >190 && bearing <200)
  {
     motor.step(-16);    
  }
  if (t.hour > 12 && t.hour < 18 && bearing >200 && bearing <210)
  {
     motor.step(-33);    
  }
  if (t.hour > 12 && t.hour < 18 && bearing >210 && bearing <220)
  {
     motor.step(-50);    
  }
  if (t.hour > 12 && t.hour < 18 && bearing >220 && bearing <230)
  {
     motor.step(-66);    
  }
  if (t.hour > 12 && t.hour < 18 && bearing >230 && bearing <240)
  {
     motor.step(-83);    
  }
  if (t.hour > 12 && t.hour < 18 && bearing >240 && bearing <250)
  {
     motor.step(-100);    
  }
  if (t.hour > 12 && t.hour < 18 && bearing >250 && bearing <260)
  {
     motor.step(-116);    
  }
  if (t.hour > 12 && t.hour < 18 && bearing >260 && bearing <270)
  {
     motor.step(-128);    
  }
  if (t.hour > 12 && t.hour < 18 && bearing >270 && bearing <280)
  {
     motor.step(-150);    
  }
  if (t.hour > 12 && t.hour < 18 && bearing >280 && bearing <290)
  {
     motor.step(-167);
  }
  if (t.hour > 12 && t.hour < 18 && bearing >290 && bearing <300)
  {
     motor.step(-183);    
  }
  if (t.hour > 12 && t.hour < 18 && bearing >300 && bearing <310)
  {
     motor.step(-200);    
  }
  if (t.hour > 12 && t.hour < 18 && bearing >310 && bearing <320)
  {
     motor.step(-217);    
  }
  if (t.hour > 12 && t.hour < 18 && bearing >320 && bearing <330)
  {
     motor.step(-233);    
  }
  if (t.hour > 12 && t.hour < 18 && bearing >330 && bearing <340)
  {
     motor.step(-250);    
  }
  if (t.hour > 12 && t.hour < 18 && bearing >340 && bearing <350)
  {
     motor.step(-267);    
  }
  
  if (t.hour > 8 && t.hour < 12 && bearing >340 && bearing <350)
  {
     motor.step(-584);    
  }
  if (t.hour > 8 && t.hour < 12 && bearing >330 && bearing <340)
  {
     motor.step(-568);    
  }
  if (t.hour > 8 && t.hour < 12 && bearing >320 && bearing <330)
  {
     motor.step(-551);    
  }
  if (t.hour > 8 && t.hour < 12 && bearing >310 && bearing <320)
  {
     motor.step(-534);    
  }
  if (t.hour > 8 && t.hour < 12 && bearing >310 && bearing <300)
  {
     motor.step(-517);    
  }
  if (t.hour > 8 && t.hour < 12 && bearing >300 && bearing <310)
  {
     motor.step(-501);    
  }
  if (t.hour > 8 && t.hour < 12 && bearing >290 && bearing <300)
  {
     motor.step(-484);    
  }
  if (t.hour > 8 && t.hour < 12 && bearing >280 && bearing <290)
  {
     motor.step(-467);    
  }
  if (t.hour > 8 && t.hour < 12 && bearing >270 && bearing <280)
  {
     motor.step(-451);    
  }
  if (t.hour > 8 && t.hour < 12 && bearing >260 && bearing <270)
  {
     motor.step(-434);    
  }
  if (t.hour > 8 && t.hour < 12 && bearing >250 && bearing <260)
  {
     motor.step(-417);    
  }
  if (t.hour > 8 && t.hour < 12 && bearing >240 && bearing <250)
  {
     motor.step(-400);    
  }
  if (t.hour > 8 && t.hour < 12 &&bearing >230 && bearing <240)
  {
     motor.step(-384);    
  }
  if (t.hour > 8 && t.hour < 12 && bearing >220 && bearing <230)
  {
     motor.step(-367);    
  }
  if (t.hour > 8 && t.hour < 12 && bearing >210 && bearing <220)
  {
     motor.step(-351);    
  }
  if (t.hour > 8 && t.hour < 12 && bearing >200 && bearing <210)
  {
     motor.step(-334);    
  }
  if (t.hour > 8 && t.hour < 12 && bearing >190 && bearing <200)
  {
     motor.step(-317);    
  }
  if (t.hour > 8 && t.hour < 12 && bearing >180 && bearing <190)
  {
     motor.step(-300);    
  }
  if (t.hour > 8 && t.hour < 12 && bearing >170 && bearing <180)
  {
     motor.step(-283);    
  }
  if (t.hour > 8 && t.hour < 12 && bearing >160 && bearing <170)
  {
     motor.step(-267);    
  }
  if (t.hour > 8 && t.hour < 12 && bearing >150 && bearing <160)
  {
     motor.step(-250);    
  }
  if (t.hour > 8 && t.hour < 12 && bearing >140 && bearing <150)
  {
     motor.step(-233);    
  }
  if (t.hour > 8 && t.hour < 12 && bearing >130 && bearing <140)
  {
     motor.step(-217);    
  }
  if (t.hour > 8 && t.hour < 12 && bearing >120 && bearing <130)
  {
     motor.step(-200);    
  }
  if (t.hour > 8 && t.hour < 12 && bearing >110 && bearing <120)
  {
     motor.step(-183);    
  }
  if (t.hour > 8 && t.hour < 12 && bearing >100 && bearing <110)
  {
     motor.step(-167);    
  }
  if (t.hour > 8 && t.hour < 12 && bearing >90 && bearing <100)
  {
     motor.step(-150);    
  }
  if (t.hour > 8 && t.hour < 12 && bearing >80 && bearing <90)
  {
     motor.step(-128);    
  }
  if (t.hour > 8 && t.hour < 12 && bearing >70 && bearing <80)
  {
     motor.step(-116);    
  }
  if (t.hour > 8 && t.hour < 12 && bearing >60 && bearing <70)
  {
     motor.step(-100);    
  }
  if (t.hour > 8 && t.hour < 12 && bearing >50 && bearing <60)
  {
     motor.step(-83);    
  }
  if (t.hour > 8 && t.hour < 12 && bearing >40 && bearing <50)
  {
     motor.step(-66);    
  }
  if (t.hour > 8 && t.hour < 12 && bearing >30 && bearing <40)
  {
     motor.step(-50);    
  }
  if (t.hour > 8 && t.hour < 12 && bearing >20 && bearing <30)
  {
     motor.step(-33);    
  }
  if (t.hour > 8 && t.hour < 12 && bearing >6 && bearing <10)
  {
     motor.step(-16);    
  }
  if(t.hour > 18 && t.hour < 7)
  {
   Serial.println("TIME  night "); // set solar pane east position as per practical
   if(tm<1)
    tm=2;
    hr8=hr9=hr10=hr11=hr12=hr13=hr14=hr15=hr16=hr17=0;
  }
  if(t.hour == 8)
  {
   Serial.println("TIME 8 AM"); 
   if(hr8<1)
   {
   digitalWrite(motor1pin1,HIGH);
   digitalWrite(motor1pin2,LOW);
   delay(1370);
   digitalWrite(motor1pin1,LOW);
   digitalWrite(motor1pin2,LOW);
   hr8=2;
   }
  }
  if(t.hour == 8 && t.min ==59 && t.sec == 52)
  {
   digitalWrite(motor1pin1,LOW);
   digitalWrite(motor1pin2,HIGH);
   delay(1220);
  }
  if(t.hour == 9)
  {
   Serial.println("TIME 9 AM"); 
   if(hr9<1)
   {
   digitalWrite(motor1pin1,HIGH);
   digitalWrite(motor1pin2,LOW);
   delay(2740);
   digitalWrite(motor1pin1,LOW);
   digitalWrite(motor1pin2,LOW);
   hr9=2;
   }
  }
  if(t.hour == 9 && t.min ==59 && t.sec == 52)
  {
   digitalWrite(motor1pin1,LOW);
   digitalWrite(motor1pin2,HIGH);
   delay(2440); 
  }
  if(t.hour == 10)
  {
   Serial.println("TIME 10 AM"); 
   if(hr10<1)
   {
   digitalWrite(motor1pin1,HIGH);
   digitalWrite(motor1pin2,LOW);
   delay(4110);
   digitalWrite(motor1pin1,LOW);
   digitalWrite(motor1pin2,LOW);
   hr10=2;
   }
  }
  if(t.hour == 10 && t.min ==59 && t.sec == 52)
  {
   digitalWrite(motor1pin1,LOW);
   digitalWrite(motor1pin2,HIGH);
   delay(3660);
  }
  if(t.hour == 11)
  {
   Serial.println("TIME 11 AM"); 
   if(hr11<1)
   {
   digitalWrite(motor1pin1,HIGH);
   digitalWrite(motor1pin2,LOW);
   delay(5480);
   digitalWrite(motor1pin1,LOW);
   digitalWrite(motor1pin2,LOW);
   hr11=2;
   }
  }
  if(t.hour == 11 && t.min ==59 && t.sec == 52)
  {
   digitalWrite(motor1pin1,LOW);
   digitalWrite(motor1pin2,HIGH);
   delay(4880);
  }
  if(t.hour == 12)
  {
   Serial.println("TIME 12 AM"); 
   if(hr12<1)
   {
   digitalWrite(motor1pin1,HIGH);
   digitalWrite(motor1pin2,LOW);
   delay(6850);
   digitalWrite(motor1pin1,LOW);
   digitalWrite(motor1pin2,LOW);
   hr12=2;
   }
  }
  if(t.hour == 12 && t.min ==59 && t.sec == 52)
  {
   digitalWrite(motor1pin1,LOW);
   digitalWrite(motor1pin2,HIGH);
   delay(6100);
  }
  if(t.hour == 13)
  {
   Serial.println("TIME 1 PM"); 
   if(hr13<1)
   {
   digitalWrite(motor1pin1,HIGH);
   digitalWrite(motor1pin2,LOW);
   delay(6850);
   digitalWrite(motor1pin1,LOW);
   digitalWrite(motor1pin2,LOW);
   hr13=2;
   }
  }
  if(t.hour == 13 && t.min ==59 && t.sec == 52)
  {
   digitalWrite(motor1pin1,LOW);
   digitalWrite(motor1pin2,HIGH);
   delay(6100);
  }
  if(t.hour == 14)
  {
   Serial.println("TIME 2 PM "); 
   if(hr14<1)
   {
   digitalWrite(motor1pin1,HIGH);
   digitalWrite(motor1pin2,LOW);
   delay(5480);
   digitalWrite(motor1pin1,LOW);
   digitalWrite(motor1pin2,LOW);
   hr14=2;
   }
  }
   if(t.hour == 14 && t.min ==59 && t.sec == 52)
  {
   digitalWrite(motor1pin1,LOW);
   digitalWrite(motor1pin2,HIGH);
   delay(4880);
  }
  if(t.hour == 15)
  {
   Serial.println("TIME 3 pm"); 
   if(hr15<1)
   {
   digitalWrite(motor1pin1,HIGH);
   digitalWrite(motor1pin2,LOW);
   delay(4110);
   digitalWrite(motor1pin1,LOW);
   digitalWrite(motor1pin2,LOW);
   hr15=2;
   }
  }
  if(t.hour == 15 && t.min ==59 && t.sec == 52)
  {
   digitalWrite(motor1pin1,LOW);
   digitalWrite(motor1pin2,HIGH);
   delay(3660);
  }
  if(t.hour == 16)
  {
   Serial.println("TIME 4 PM"); 
   if(hr16<1)
   {
   digitalWrite(motor1pin1,HIGH);
   digitalWrite(motor1pin2,LOW);
   delay(2740);
   digitalWrite(motor1pin1,LOW);
   digitalWrite(motor1pin2,LOW);
   hr16=2;
   }
  }
   if(t.hour == 16 && t.min ==59 && t.sec == 52)
  {
   digitalWrite(motor1pin1,LOW);
   digitalWrite(motor1pin2,HIGH);
   delay(2440);
  }
  if(t.hour == 17)
  {
   Serial.println("TIME 5pm"); 
   if(hr17<1)
   {
   digitalWrite(motor1pin1,HIGH);
   digitalWrite(motor1pin2,LOW);
   delay(1370);
   digitalWrite(motor1pin1,LOW);
   digitalWrite(motor1pin2,LOW);
   hr17=2;
   }
  }
  if(t.hour == 17 && t.min ==59 && t.sec == 52)
  {
   digitalWrite(motor1pin1,LOW);
   digitalWrite(motor1pin2,HIGH);
   delay(1220);
  }
 }
  
