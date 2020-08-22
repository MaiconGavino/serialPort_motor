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
  int recebido = Serial.parseInt();
  if(recebido == 1){
    ouo = 1;
  }
   if(recebido == 2)
  {
    ouo = 2;
  }
   if( recebido == 0){
    ouo = 0;
  }


  
  while(ouo == 1)
  {
    digitalWrite(pinOut2, LOW);
    digitalWrite(pinOut1, HIGH);
  }
   while(ouo == 2)
  {
    digitalWrite(pinOut1, LOW);
    digitalWrite(pinOut2,LOW);
    delay(10   );
    digitalWrite(pinOut1, LOW);
    digitalWrite(pinOut2,HIGH);
  }
   while(ouo == 0)
  {
    digitalWrite(pinOut2, LOW);
    digitalWrite(pinOut1, LOW);
  }
}
