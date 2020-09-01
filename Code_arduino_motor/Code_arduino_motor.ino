#define pinOut1 13
#define pinOut2 12
void setup() 
{
  pinMode(pinOut1, OUTPUT);
  pinMode(pinOut2, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  const int recebido = Serial.parseInt();
  if(Serial.available())
  {
    if(recebido == 3)
    {
      digitalWrite(pinOut1, LOW);
      digitalWrite(pinOut2, LOW);
      delay(500);
      digitalWrite(pinOut1, HIGH);
      digitalWrite(pinOut2, LOW);
    }
    else if(recebido == 4)
    {
      digitalWrite(pinOut1, LOW);
      digitalWrite(pinOut2, LOW);
      delay(500);
      digitalWrite(pinOut1, LOW);
      digitalWrite(pinOut2, HIGH);
    }
    else
    {
      digitalWrite(pinOut1, LOW);
      digitalWrite(pinOut2, LOW);
    } 
  }
  
}
