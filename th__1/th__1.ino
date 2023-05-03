
const int sensor1 = 36;
const int sensor2 = 37;
const int sensor3 = 38;
const int sensor4 = 39;


int va1 = 0;

int va2 = 0;

int va3 = 0;

int va4 = 0;


void setup() {
  Serial.begin(9600);
  pinMode(sensor1, INPUT);
    pinMode(sensor2, INPUT);
      pinMode(sensor3, INPUT);
        pinMode(sensor4, INPUT);
}

void loop(){
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
}
