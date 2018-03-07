void setup() {
  
  //pinMode(buzzer,OUTPUT);
  pinMode(8,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
   if(millis()<=60000)
  {
      if((millis()/1000)%10==0)
      {
          func1(100);
          delay(1000);
      }
  }
  if(millis()>60000 && millis()<=120000)
  {
      if(((millis()/1000)-60)%7==0)
      {
          func1(100);
          delay(1000);
      }
  }
  if(millis()>120000 && millis()<=170000)
  {
       if(((millis()/1000)-120)%4==0)
       {
          func1(100);
          delay(1000);
       }
  }
   if(millis()>170000 && millis()<=180000)
  {
       if((millis()/1000)%1==0)
       {
          func1(60);
          delay(1000);
       }
  }

}
void func1(int x) {
    digitalWrite(8,HIGH);
    delay(x);
    digitalWrite(8,LOW);
}
  // put your main code here, to run repeatedly:


