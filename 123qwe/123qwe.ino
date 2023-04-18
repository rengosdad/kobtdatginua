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
int n = 0;
int i = 0;
int goc;
int giatriX;
int giatriY;
int giatrinut;
MaxMatrix m(DIN, CS, CLK, maxInUse); 
Servo myServo4;
Servo myServo1;
Servo myServo2;
Servo myServo3;
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


    
}

 
void loop() 
{ 
  {
  int doc_cambien = analogRead(cambien);
  
  int phantram = map(doc_cambien,0,1023,1,100);

  int phantramthuc = 100 - phantram;

  Serial. print("Analog: "); Serial. print(doc_cambien);
  Serial. print(" ");
  Serial. print("~");
  Serial. print(" ");
  Serial. print(phantramthuc);
  Serial. println("%");
  delay (500);

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
    m.clear();
    m.writeSprite(0, 0, A);
  delay(1000);
     
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
    

    m.clear();
    m.writeSprite(0, 0, B);
  delay(1000);

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
    m.clear();
   m.writeSprite(0, 0, C);
  delay(1000);
  
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
    m.clear();
    m.writeSprite(0, 0, D);
  delay(1000);

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
}
