long duration;
long distance;
void setup() 
{
 // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(7,INPUT);
  pinMode(8,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(3,OUTPUT);
}
void loop() 
{
  // put your main code here, to run repeatedly:
  digitalWrite(8,LOW);
  delayMicroseconds(2);
  digitalWrite(8,HIGH);
  delayMicroseconds(10);
  digitalWrite(8,LOW);
  duration = pulseIn(7,HIGH);
  distance = duration/58.2;
  Serial.println(distance);
  delay(100);

  
  if(distance <= 10)
  {
    digitalWrite(12,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(5,LOW);
    delay(500);
  }
  else if(distance > 10 && distance < 50 )
  {
    digitalWrite(3,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(5,LOW);
    delay(500);
  }
  else
  {
    digitalWrite(5,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(3,LOW);
    delay(500);
  }
}
