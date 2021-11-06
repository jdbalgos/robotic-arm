/**************************************************/
/***************Robotech Arm Project***************/
/*************Tuesday, Sept. 30 , 2013*************/
/********Source Code By: John David Balgos*********/
/********************ESET-E4G**********************/
/*****************SY. 2013 - 2014******************/
/**************************************************/

/*PROJECT ARMS Directives*/
#define Servo_1 PORTB.RB7
#define Servo_2 PORTB.RB6
#define Servo_3 PORTB.RB4
#define Servo_4 PORTB.RB5
#define Trigger2 PORTA.RA3
#define Echo2    PORTA.RA2
#define Trigger1 PORTA.RA0
#define Echo1    PORTA.RA1
#define Switch1  PORTB.RB1
#define Switch2  PORTB.RB2
/*PROJECT ARMS Directives*/

/*PROJECT ARMS Function Prototypes Declaration*/
void ArmNormal();
void FrontMovement();
void BackMovement();
void FrontUltrasonic();
void BackUltrasonic();
void TurnDelay();
void CounterClocwiseTurn();
void Init();
void RealAccuracy();
void Real360();
/*PROJECT ARMS Function Prototypes Declaration*/

/*PROJECT ARMS Variable Declaration*/
     signed short s1 , s2 , s3 ,s4;
     short button1 = 0;
     signed int a1 = 41;
     signed int a2 = 55;
     signed int a3 = 0;
     signed int a4 = 0;
     const int D1 = 450;
     const int TurningDelay = 1;
     short a;
     signed int width1,range1,y;
     signed int width2,range2;
     int count1 = 0;
     int count2 = 0;
     int x =0;
/*PROJECT ARMS Variable Declaration*/


/**********MAIN FUNCTION***********/
void main()
{
 Init();
 y =0;
 ArmNormal();
 while(1)
 {
   if(Switch1)
   {
    RealAccuracy();
   }
   if(Switch2)
   {
    Real360();
   }
   y++;
   delay_ms(10);
   if(y == 300)
   {
   RealAccuracy();
   }
 }
}
/**********MAIN FUNCTION***********/

/**********INIT FUNCTION***********/
void Init()
{
     CMCON = 0x07;
     TRISA = 0b00000110;
     TRISB = 0b00000110;
     PORTB = 0x00;
     PORTA = 0x00;
}/**********INIT FUNCTION***********/


/**********ArmNormal FUNCTION***********/
void ArmNormal()
{
for(a=0; a<50; a++)
{
         Servo_1 = 1;
         delay_us(D1);
         for(s1=0;s1<=a1;s1++) delay_us(1);
         Servo_1 = 0; delay_ms(4);
         Servo_2 = 1;
         delay_us(D1);
         for(s2=0;s2<=a2;s2++) delay_us(1);
         Servo_2 = 0; delay_ms(4);
         Servo_4 = 1;
         delay_us(500);
         for(s4=0;s4<=a4;s4++) delay_us(1);
         Servo_4 = 0; delay_ms(4);
         Servo_3 = 1;
         delay_us(D1);
         for(s3=0;s3<=x;s3++) delay_us(1);
         Servo_3 = 0; delay_ms(4);
}
}
/**********ArmNormal FUNCTION***********/

/**********front Movement FUNCTION***********/
void FrontMovement()
{
     a2 = 31;
     ArmNormal();
     a2 = 21;
     ArmNormal();
     a2 = 15;
     ArmNormal();
     a2 = 10;
     ArmNormal();
     a1 = 55;
     ArmNormal();
     a4 = 20;
     ArmNormal();
     a2 = 50;
     ArmNormal();
     a1 = 65;
     ArmNormal();
     a1 = 75;
     ArmNormal();
     a1 = 85;
     ArmNormal();
     a1 = 95; a2 = 59;
     ArmNormal();
     a4 = 0;
     ArmNormal(); a2 = 55; a1 = 41;ArmNormal();
     count1++;
}
/**********FrontMovement FUNCTION***********/

/**********BackMovement FUNCTION***********/
void BackMovement()
{
         a2 = 100;
         ArmNormal();
         a1 = 30;
         ArmNormal();
         a4 = 20;
         ArmNormal();
         a2 = 52;
         ArmNormal();
         a1 = 20;
         ArmNormal();
         a1 = 10;
         ArmNormal();
         a1 = 0;
         ArmNormal();
         a4 = 0;
         ArmNormal(); a2 = 55; a1 = 41;ArmNormal();
         count2++;
}
/**********BackMovement FUNCTION***********/

/**********FrontUltrasonic FUNCTION***********/
void FrontUltrasonic()
{
        width1 = 0;
        range1 = 0;
        Trigger1 = 1;
        delay_us(5);
        Trigger1 = 0;
        while(Echo1==0);
        while(Echo1==1)
        {
            width1++;
            delay_us(10);
        }
        range1 = (width1*0.3);
//First Ultrasonic End
//First Ultrasonic Condition
        if(range1 >= 11 && range1 <= 20)
        {
             count1++;
        }
}
/**********FrontUltrasonic FUNCTION***********/

/**********BackUltrasonic FUNCTION***********/
void BackUltrasonic()
{
//Second Ultrasonic Start
        width2 = 0;
        range2 = 0;
        Trigger2 = 1;
        delay_us(5);
        Trigger2 = 0;
        while(Echo2==0);
        while(Echo2==1)
        {
            delay_us(10);
            width2++;
        }
        range2 = (width2*0.3);
//Second Ultrasonic End
//Second Ultrasonic Condition
        if(range2 >= 11 && range2 <= 21)
        {
             count2++;
        }

}
/**********BackUltrasonic FUNCTION***********/

/**********TurnDelay FUNCTION***********/
void TurnDelay()
{

             Servo_3 = 1;
             delay_us(D1);
             for(s3=0;s3<=x;s3++) delay_us(1);
             Servo_3 = 0; delay_ms(20);
}
/**********TurnDelay FUNCTION***********/

void RealAccuracy()
{
while(1)
 {
 x=0;
  ArmNormal();
  ArmNormal();
 for(x=5; x<= 118;x++)
    {
     TurnDelay();
     FrontUltrasonic();
     if(x==118)
     {
     if (range1 >=11 && range1 <= 19)
      goto that;
     }
     if ((range1 < 11 || range1 > 19) && (count1 >= 10 && count1 <= 50))
     {
that:
      if (x >= 10 && x <= 24 )
      {
       x = 4;
      }
      if (x >= 25 && x <= 37 )
      {
       x = 19;
      }
      if (x >= 38 && x <= 50 )
      {
       x = 32;
      }
      if (x >= 51 && x <= 65 )
      {
       x = 46;
      }
      if (x >= 66 && x <= 76 )
      {
       x = 60;
      }
      if (x >= 77 && x <= 91 )
      {
       x = 74;
      }
      if (x >= 92 && x <= 108 )
      {
       x = 89;
      }
      if (x >= 109 && x <= 123 )
      {
       x = 104;
      }
       ArmNormal;
       FrontMovement();
       count1 = 0;
     }
     BackUltrasonic();
          if(x==118)
     {
     if (range2 >=10 && range2 <= 21)
      goto here;
     }
     if ((range2 < 11 || range2 > 21) && (count2 >= 10 && count2 <= 100))
      {
here:
      if (x >= 10 && x <= 24 )
      {
       x = 8;                            //p
      }
      if (x >= 25 && x <= 37 )
      {
       x = 22;                           //.
      }
      if (x >= 38 && x <= 50 )
      {
       x = 36;                          //u
      }
      if (x >= 51 && x <= 65 )
      {
       x = 50;                          //.
      }
      if (x >= 66 && x <= 79 )          //
      {
       x = 63;                          //t
      }
      if (x >= 80 && x <= 95 )
      {
       x = 77;                          //4
      }
      if (x >= 96 && x <= 108 )
      {
       x = 92;                          //1
      }
      if (x >= 109 && x <= 123 )
      {
       x = 108;                         //0
      }
       ArmNormal;
       BackMovement();
       count2 = 0;
      }
    }
 count1 = 0;
 count2 = 0;
 }
}

void Real360()
{
 while(1)
 {
     for(x=0; x<= 123;x++)
    {
     TurnDelay();
     FrontUltrasonic();
     if ((range1 < 10 || range1 > 19) && (count1 >= 5 && count1 <= 50))
      {
       count1++;
       x -= (count1/2);
       ArmNormal;
       FrontMovement();
       count1 = 100;
      }
     BackUltrasonic();
     if ((range2 < 10 || range2 > 19) && (count2 >= 5 && count2 <= 50))
      {
       count2++;
       x -= (count2/2);
       ArmNormal;
       BackMovement();
       count2 = 100;
      }
    }
 count1 = 0;
 count2 = 0;
for(x=123; x>= 0;x--)
 {
  TurnDelay();
  FrontUltrasonic();
  if ((range1 < 11 || range1 > 20) && (count1 >= 5 && count1 <= 50))
  {
   count1++;
   x += (count1/2);
   ArmNormal;
   FrontMovement();
   count1 = 100;
  }
  BackUltrasonic();
  if ((range2 < 11 || range2 > 21) && (count2 >= 5 && count2 <= 50))
  {
   count2++;
   x += (count2/2);
   ArmNormal;
   BackMovement();
   count2 = 100;
  }
 }
 count1 = 0;
 count2 = 0;
 }
}
