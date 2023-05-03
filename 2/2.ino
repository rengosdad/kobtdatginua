#include <Servo.h> 
#include <MaxMatrix.h>
int bientroX = A0;
int bientroY = A1;
int cambien = A2;
int nutnhan = 4;
int DIN = 7;   // DIN pin -> MAX7219 module
int CLK = 6;   // CLK pin -> MAX7219 module
int CS = 5;    // CS pin -> MAX7219 module
int maxInUse = 1;
int servo2 = 10;
int servo1 = 11;
int servo3 = 9;
int servo4 = 8;
int t = 0;
int n = 0;
int i = 0;
int va1 = 0;
int va2 = 0;
int va3 = 0;
int va4 = 0;
int goc;
int giatriX;
int giatriY;
int giatrinut;
///////////////////////////////////
int ch1Value;
int ch2Value;
int ch3Value;
int ch4Value; 
int ch5Value;
bool ch6Value;
#define CH1 30
#define CH2 31
#define CH3 32
#define CH4 33
#define CH5 34
#define CH6 35
/////////////////////////////////////
MaxMatrix m(DIN, CS, CLK, maxInUse); 
Servo myServo4;
Servo myServo1;
Servo myServo2;
Servo myServo3;
//////////////////////////////////////////////////////////////////////

const int sensor1 = 36;
const int sensor2 = 37;
const int sensor3 = 38;
const int sensor4 = 39;
/////////////////////////////////////////////////////////////
int readChannel(int channelInput, int minLimit, int maxLimit, int defaultValue){
  int ch = pulseIn(channelInput, HIGH, 30000);
  if (ch < 100) return defaultValue;
  return map(ch, 1000, 2000, minLimit, maxLimit);
}

bool readSwitch(byte channelInput, bool defaultValue){
  int intDefaultValue = (defaultValue)? 100: 0;
  int ch = readChannel(channelInput, 0, 100, intDefaultValue);
  return (ch > 50);
}
////////////////////
char A[] = {8, 8,
          B00110000,
          B00011100,
          B00000110,
          B11111011,
          B11111011,
          B00000110,
          B00011100,
          B00110000,
           };
char B[] = {8, 8,
         B00011000,
         B00111100,
         B01100110,
         B01011010,
         B11011011,
         B10011001,
         B00011000,
         B00011000,
           };
char C[] = {8, 8,
           B00001100,
           B00111000,
           B01100000,
           B11011111,
           B11011111,
           B01100000,
           B00111000,
           B00001100,
                 };
char D[] = {8, 8,
           B00011000,
           B00011000,
           B10011001,
           B11011011,
           B01011010,
           B01100110,
           B00111100,
           B00011000,
                 };
void setup() 
{
  {
  Serial.begin(9600);
  pinMode(sensor1, INPUT);
    pinMode(sensor2, INPUT);
      pinMode(sensor3, INPUT);
        pinMode(sensor4, INPUT);
}

  {
  Serial. begin (9600);

  pinMode (cambien, INPUT);

}
   {
    Serial.begin (9600);
  
    pinMode (bientroX, INPUT);
    pinMode (bientroY, INPUT);
    pinMode (nutnhan, INPUT_PULLUP);
  
  }
  {
  m.init(); // MAX7219 tanımlaması
  m.setIntensity(8); // Ledlerin parlaklık ayarı yapılıyor.
}
  { 
    Serial.begin(9600);
    myServo1.attach(servo1); 
}
 { 
    Serial.begin(9600);
    myServo2.attach(servo2); 
}
 { 
    Serial.begin(9600);
    myServo3.attach(servo3); 
}
 { 
    Serial.begin(9600);
    myServo4.attach(servo4); 
}
////////////////////////////////////////////////////
{
  Serial.begin(115200);
  pinMode(CH1, INPUT);
  pinMode(CH2, INPUT);
  pinMode(CH3, INPUT);
  pinMode(CH4, INPUT);
  pinMode(CH5, INPUT);
  pinMode(CH6, INPUT);
}
//////////////////////////////////////////////////
  
}

 
void loop() 
{ ///////////////////////////////////////
  {
  {

  va1 = digitalRead(sensor1);
  Serial.println(va1);
  delay(30);
}
{
  va2 = digitalRead(sensor2);
  Serial.println(va2);
  delay(30);
}
{
  va3 = digitalRead(sensor3);
  Serial.println(va3);
  delay(30);
}
{
  va4 = digitalRead(sensor4);
  Serial.println(va4);
  delay(30);
}
}/////////////////////////////////
  {
  ch1Value = readChannel(CH1, -100, 100, 0);
  ch2Value = readChannel(CH2, -100, 100, 0);
  ch3Value = readChannel(CH3, -100, 100, -100);
  ch4Value = readChannel(CH4, -100, 100, 0);
  ch5Value = readChannel(CH5, -100, 100, 0);
  ch6Value = readSwitch(CH6, false);
  Serial.print("Ch1: ");
  Serial.print(ch1Value);
  Serial.print(" | Ch2: ");
  Serial.print(ch2Value);
  Serial.print(" | Ch3: ");
  Serial.print(ch3Value);
  Serial.print(" | Ch4: ");
  Serial.print(ch4Value);
  Serial.print(" | Ch5: ");
  Serial.print(ch5Value);
  Serial.print(" | Ch6: ");
  Serial.println(ch6Value);
  
  delay(500);
}
  {
  giatriX = analogRead(bientroX);
  giatriY = analogRead(bientroY);
  giatrinut = digitalRead(nutnhan);

  Serial.print ("Giá trị X: ");
  Serial.print (giatriX);
  Serial.print ("   ");
  Serial.print ("Giá trị Y: ");
  Serial.print (giatriY);
  Serial.print ("   ");
  Serial.print ("Giá trị nút nhấn: ");
  Serial.println (giatrinut);
  delay (500);

}
{
  if (giatriY==0)
  {
  // if (n==0)
//{
    m.clear();
    m.writeSprite(0, 0, A);
  delay(1000);
//} 
     
    myServo1.write(0);
    goc = myServo1.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo1.write(90);
    goc = myServo1.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo1.write(180);
    goc = myServo1.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
    
     myServo2.write(0);
    goc = myServo2.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo2.write(90);
    goc = myServo2.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo2.write(180);
    goc = myServo2.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);

    myServo3.write(0);
    goc = myServo3.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo3.write(90);
    goc = myServo3.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo3.write(180);
    goc = myServo3.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
    
    myServo4.write(0);
    goc = myServo4.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo4.write(90);
    goc = myServo4.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo4.write(180);
    goc = myServo4.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
    n++;
  }
  else if (giatriX==0)
  {
    
    //if (n==1)
//{
    m.clear();
    m.writeSprite(0, 0, B);
  delay(1000);
//}
    
   myServo1.write(0);
    goc = myServo1.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo1.write(90);
    goc = myServo1.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo1.write(180);
    goc = myServo1.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
    
     myServo2.write(0);
    goc = myServo2.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo2.write(90);
    goc = myServo2.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo2.write(180);
    goc = myServo2.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);

    myServo3.write(0);
    goc = myServo3.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo3.write(90);
    goc = myServo3.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo3.write(180);
    goc = myServo3.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
    
    myServo4.write(0);
    goc = myServo4.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo4.write(90);
    goc = myServo4.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo4.write(180);
    goc = myServo4.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
    n++;
  }
else if (giatriY==1023)
  {
     // if (n==2)
//{
    m.clear();
   m.writeSprite(0, 0, C);
  delay(1000);
//}
  
    myServo1.write(0);
    goc = myServo1.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo1.write(90);
    goc = myServo1.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo1.write(180);
    goc = myServo1.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
    
     myServo2.write(0);
    goc = myServo2.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo2.write(90);
    goc = myServo2.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo2.write(180);
    goc = myServo2.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);

    myServo3.write(0);
    goc = myServo3.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo3.write(90);
    goc = myServo3.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo3.write(180);
    goc = myServo3.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
    
    myServo4.write(0);
    goc = myServo4.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo4.write(90);
    goc = myServo4.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo4.write(180);
    goc = myServo4.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
    n++;
  }
   else if (giatriX==1023)
   {
//if (n==3)
//{
    m.clear();
    m.writeSprite(0, 0, D);
  delay(1000);
//}
  
     myServo1.write(0);
    goc = myServo1.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo1.write(90);
    goc = myServo1.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo1.write(180);
    goc = myServo1.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
    
     myServo2.write(0);
    goc = myServo2.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo2.write(90);
    goc = myServo2.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo2.write(180);
    goc = myServo2.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);

    myServo3.write(0);
    goc = myServo3.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo3.write(90);
    goc = myServo3.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo3.write(180);
    goc = myServo3.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
    
    myServo4.write(0);
    goc = myServo4.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo4.write(90);
    goc = myServo4.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo4.write(180);
    goc = myServo4.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
    n=i;
  }
  
}
{//////////////////////////////////////////////////////////////
  if (ch2Value==100)
  {
  // if (n==0)
//{
    m.clear();
    m.writeSprite(0, 0, A);
  delay(1000);
//} 
     
    myServo1.write(0);
    goc = myServo1.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo1.write(90);
    goc = myServo1.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo1.write(180);
    goc = myServo1.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
    
     myServo2.write(0);
    goc = myServo2.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo2.write(90);
    goc = myServo2.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo2.write(180);
    goc = myServo2.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);

    myServo3.write(0);
    goc = myServo3.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo3.write(90);
    goc = myServo3.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo3.write(180);
    goc = myServo3.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
    
    myServo4.write(0);
    goc = myServo4.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo4.write(90);
    goc = myServo4.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo4.write(180);
    goc = myServo4.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
    t++;
  }
  else if (ch2Value==-100)
  {
    
    //if (n==1)
//{
    m.clear();
    m.writeSprite(0, 0, B);
  delay(1000);
//}
    
   myServo1.write(0);
    goc = myServo1.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo1.write(90);
    goc = myServo1.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo1.write(180);
    goc = myServo1.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
    
     myServo2.write(0);
    goc = myServo2.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo2.write(90);
    goc = myServo2.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo2.write(180);
    goc = myServo2.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);

    myServo3.write(0);
    goc = myServo3.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo3.write(90);
    goc = myServo3.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo3.write(180);
    goc = myServo3.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
    
    myServo4.write(0);
    goc = myServo4.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo4.write(90);
    goc = myServo4.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo4.write(180);
    goc = myServo4.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
    t++;
  }
else if (ch3Value==100)
  {
     // if (n==2)
//{
    m.clear();
   m.writeSprite(0, 0, C);
  delay(1000);
//}
  
    myServo1.write(0);
    goc = myServo1.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo1.write(90);
    goc = myServo1.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo1.write(180);
    goc = myServo1.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
    
     myServo2.write(0);
    goc = myServo2.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo2.write(90);
    goc = myServo2.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo2.write(180);
    goc = myServo2.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);

    myServo3.write(0);
    goc = myServo3.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo3.write(90);
    goc = myServo3.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo3.write(180);
    goc = myServo3.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
    
    myServo4.write(0);
    goc = myServo4.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo4.write(90);
    goc = myServo4.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo4.write(180);
    goc = myServo4.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
    t++;
  }
   else if (ch3Value==-100)
   {
//if (n==3)
//{
    m.clear();
    m.writeSprite(0, 0, D);
  delay(1000);
//}
  
     myServo1.write(0);
    goc = myServo1.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo1.write(90);
    goc = myServo1.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo1.write(180);
    goc = myServo1.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
    
     myServo2.write(0);
    goc = myServo2.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo2.write(90);
    goc = myServo2.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo2.write(180);
    goc = myServo2.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);

    myServo3.write(0);
    goc = myServo3.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo3.write(90);
    goc = myServo3.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo3.write(180);
    goc = myServo3.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
    
    myServo4.write(0);
    goc = myServo4.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo4.write(90);
    goc = myServo4.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
  
    myServo4.write(180);
    goc = myServo4.read();
    Serial.print("Góc hiện tại: "); Serial.println(goc);
    delay(1000);
   t=i;
  }
  
}
////////////////////////////////
}
