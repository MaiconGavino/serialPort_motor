#define pinOut1 13
#define pinOut2 12
int ouo = 0;
void setup() 
{
  pinMode(pinOut1, OUTPUT);
  pinMode(pinOut2, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  if(Serial.available())
  {
    const int recebido = Serial.parseInt();
    if(recebido == 1)
    {
      digitalWrite(pinOut1, HIGH);
      digitalWrite(pinOut2, LOW);
    }
    else if(recebido == 2)
    {
      digitalWrite(pinOut2, HIGH);
      digitalWrite(pinOut1, LOW);
    }
    else
    {
      digitalWrite(pinOut1, LOW);
      digitalWrite(pinOut2, LOW);
    }
  }
}
