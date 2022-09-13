#include <AccelStepper.h>
#include <TimerOne.h> 
// 1mm = 260p
#define xylanhGiuGiay 43
#define xylanhKep 35
#define xylanhChan 37
#define xylanhKeo 39
#define xylanhChat 41
#define bechuaUp 2
#define bechuaDown 3
#define giuGiay 31
#define bangtaiThuan 7
#define bangtaiNguoc 6


#define PULCat A10
#define DIRCat A11
#define ENCat A12

#define PULCuon A13
#define DIRCuon A14
#define ENCuon A15

#define PULDay 36
#define DIRDay 34
#define ENDay 32

#define butStart A5
#define butStartPress !digitalRead(butStart)

#define butStop A4
#define butStopPress !digitalRead(butStop)

#define butSelect A3
#define butSelectPress !digitalRead(butSelect)

#define ss1 42
#define ss1R !digitalRead(ss1)
#define ss2 44
#define ss2R !digitalRead(ss2)
#define ss3 48
#define ss3R !digitalRead(ss3)
#define ss4 46
#define ss4R !digitalRead(ss4)
#define q1 38
#define q1R !digitalRead(q1)
#define q2 40
#define q2R !digitalRead(q2)


#define airVan A9
#define airVanR !digitalRead(airVan)

AccelStepper RL_Day(1,PULDay, DIRDay);
AccelStepper RL_Cuon(1,PULCuon, DIRCuon);
AccelStepper SL_Cat(1,PULCat, DIRCat);


void setup() {
  Serial.begin(9600);
  Timer1.initialize(500);
  Timer1.attachInterrupt(TR);
  pinMode(xylanhKep, OUTPUT);
  pinMode(xylanhChan, OUTPUT);
  pinMode(xylanhKeo, OUTPUT);
  pinMode(xylanhChat, OUTPUT);
  pinMode(giuGiay,OUTPUT);
  pinMode(xylanhGiuGiay,OUTPUT);

  pinMode(PULCat,OUTPUT);
  pinMode(DIRCat,OUTPUT);
  pinMode(ENCat,OUTPUT);

  pinMode(PULCuon,OUTPUT);
  pinMode(DIRCuon,OUTPUT);
  pinMode(ENCuon,OUTPUT);
  
  pinMode(PULDay,OUTPUT);
  pinMode(DIRDay,OUTPUT);
  pinMode(ENDay,OUTPUT);
  

  pinMode(butStart, INPUT_PULLUP);
  pinMode(butStop, INPUT_PULLUP);
  pinMode(ss1, INPUT_PULLUP);
  pinMode(ss2, INPUT_PULLUP);
  pinMode(ss3, INPUT_PULLUP);
  pinMode(ss4, INPUT_PULLUP);
  pinMode(q1, INPUT_PULLUP);
  pinMode(q2, INPUT_PULLUP);
  pinMode(airVan, INPUT_PULLUP);

   RL_Day.setMaxSpeed(500.0);
   RL_Day.setAcceleration(5000.0);
   RL_Day.moveTo(-100000);

   RL_Cuon.setMaxSpeed(20000.0);
   RL_Cuon.setAcceleration(5000.0);
   RL_Cuon.moveTo(-100000);

   SL_Cat.setMaxSpeed(1700.0);
   SL_Cat.setAcceleration(3000.0);
   SL_Cat.moveTo(-10000);

   while(!airVanR)
   {
   }
  analogWrite(bechuaDown,100);
  delay(2000);
  analogWrite(bechuaDown,0);
  while(!ss2R)
  {
    analogWrite(bechuaUp,100);
  }
  if(ss2R)
  {
    analogWrite(bechuaUp,0);
  }
  Serial.println(ss4R);

  while(!ss4R)
  { 
    SL_Cat.run();
  }
  Serial.println("PASS");
  digitalWrite(giuGiay,LOW);
}
long t1 = 0;
long t2 = 0;
long t3 = 0;
long countC = 0;
int countS = 0;
long countDung = 0;
bool RUN = false;
int downC = 0;
bool dung = true;

void loop() {
Stp:

  while(RUN)
  {
New:
      countS =0;
      t1=0;
      t2=0;
      while(!q1R && RUN)
      {      
      }
      delay(300);
      dung = false;
      while(!q2R && RUN)
      { 
          if(t2 == 2)
          {
            if(RUN)digitalWrite(PULCuon,!digitalRead(PULCuon));
            t2 = 0;
          }
          delayMicroseconds(10);
          t1++;
          t2++;
      }
      dung = true;
      countC = 0;
      countDung = 0;
      digitalWrite(giuGiay,LOW);
      t2=0;
      while(countC < 4740 & RUN)
      { 
        if(t2 == 5)
        {
          digitalWrite(PULCuon,!digitalRead(PULCuon));
          t2 = 0;
          countC++;
        }
        delayMicroseconds(10);
        t2++;
      }
      digitalWrite(xylanhChat,HIGH);
      delay(1000);
      countC = 0;
      while(countC < 17990 & RUN)
      { 
        if(t2 == 5)
        {
          digitalWrite(PULCuon,!digitalRead(PULCuon));
          t2 = 0;
          countC++;
        }
        delayMicroseconds(10);
        t2++;
      }
      digitalWrite(xylanhChan,HIGH);
      delay(200);  
      digitalWrite(xylanhGiuGiay,HIGH);
      delay(300);
      digitalWrite(DIRCat,HIGH);
       for(long k = 0; k <3200 ;k++)
      {
         digitalWrite(PULCat,!digitalRead(PULCat));
        if(k<100)
          delayMicroseconds(550);
        else
          delayMicroseconds(200);
      }
      digitalWrite(DIRCat,LOW);
      
      long n = 0;
      while(!ss4R)
      {
        n++;
        digitalWrite(PULCat,!digitalRead(PULCat));
        if(n< 100)
          delayMicroseconds(550);
        else
          delayMicroseconds(200);
      }
      n = 0;
      digitalWrite(xylanhChan,LOW);
      digitalWrite(xylanhGiuGiay,LOW);
      delay(200);
      analogWrite(bangtaiNguoc,130);
      delay(500);
      analogWrite(bangtaiNguoc,0);
      
      
    
Rep:      
      countC = 0;
      t2=0;
      while(countC < 6030)
      { 
        if(t2 == 4)
        {
          digitalWrite(PULCuon,!digitalRead(PULCuon));
          t2 = 0;
          countC++;
        }
        delayMicroseconds(10);
        t2++;
      }
      digitalWrite(xylanhChan,HIGH);
      delay(200);
      digitalWrite(xylanhGiuGiay,HIGH);
      delay(500);
      digitalWrite(DIRCat,HIGH);
       for(long k = 0; k <3200 ;k++)
      {
        
        digitalWrite(PULCat,!digitalRead(PULCat));
        if(k<100)
          delayMicroseconds(550);
        else
          delayMicroseconds(200);
      }
      digitalWrite(xylanhGiuGiay,LOW);
      delay(150);
      digitalWrite(xylanhGiuGiay,HIGH);
      delay(160);
      digitalWrite(xylanhGiuGiay,LOW);
      delay(350);
//      analogWrite(bangtaiThuan,120);
//      delay(100);
//      analogWrite(bangtaiThuan,97);
//      delay(500);
     // analogWrite(bangtaiThuan,0);
      digitalWrite(DIRCat,LOW);
      n = 0;
      while(!ss4R)
      {
        n++;
        analogWrite(bangtaiThuan,40);
        if(n >100)
          analogWrite(bangtaiThuan,60);
        if(n >200)
          analogWrite(bangtaiThuan,70);
        if(n >300)
          analogWrite(bangtaiThuan,80);
        digitalWrite(PULCat,!digitalRead(PULCat));
        if(n< 100)
          delayMicroseconds(550);
        else
          delayMicroseconds(200);
      }
      analogWrite(bangtaiThuan,0);
      n = 0;
      digitalWrite(xylanhChan,LOW);
      delay(200);
      countS++;
      if(countS%2 ==0)
      {
        analogWrite(bechuaDown,90);
        delay(60);
        analogWrite(bechuaDown,0); 
      }
      if(countS < 10)
      {
        goto Rep;
      }
      countC = 0;
      t2=0;
      while(countC < 6050)
      { 
        if(t2 == 5)
        {
          digitalWrite(PULCuon,!digitalRead(PULCuon));
          t2 = 0;
          countC++;
        }
        delayMicroseconds(10);
        t2++;
      }
      digitalWrite(xylanhChan,HIGH);
      delay(200);
      digitalWrite(xylanhKeo,HIGH);
      delay(800);
      digitalWrite(xylanhKep,HIGH);
      delay(400);
      digitalWrite(xylanhChan,LOW);
      delay(200);
      digitalWrite(xylanhKeo,LOW);
      delay(700);
      digitalWrite(xylanhKep,LOW);
      delay(200);
      digitalWrite(xylanhChat,LOW);
      if(!RUN)
      {
        digitalWrite(xylanhKep, LOW);
        digitalWrite(xylanhChan, LOW);
        digitalWrite(xylanhKeo, LOW);
        digitalWrite(xylanhChat, LOW);
        digitalWrite(giuGiay,LOW);
        digitalWrite(xylanhGiuGiay,LOW);
      
        digitalWrite(PULCat,LOW);
        digitalWrite(DIRCat,LOW);
        digitalWrite(ENCat,LOW);
      
        digitalWrite(PULCuon,LOW);
        digitalWrite(DIRCuon,LOW);
        digitalWrite(ENCuon,LOW);
        
        digitalWrite(PULDay,LOW);
        digitalWrite(DIRDay,LOW);
        digitalWrite(ENDay,LOW);
        break;
        
      }
      goto New;
    }
}


long countTimer = 0;
void TR()
{
  if(butStartPress && airVanR)
  {
    RUN = true;
  }
  if(butStopPress)
  {
    RUN =false;
    digitalWrite(PULCuon,LOW); 
  }
  if(RUN && (!q1R|| !dung) && countS < 9 && airVanR)
  {
     if(countTimer <3000)
        digitalWrite(PULDay,!digitalRead(PULDay));
     else if (countTimer <3200)
     {     
     }
     else 
        countTimer = 0;
     
     countTimer++;
  }
  if (RUN && q1R && countS < 2)
  {
    digitalWrite(giuGiay,HIGH);
  }
  else
  {
    digitalWrite(giuGiay,LOW);
  }
}
