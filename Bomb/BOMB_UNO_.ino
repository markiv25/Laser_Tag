
#include <SPI.h>
#include <MFRC522.h>
int buzzer=8;
//int button=2;
//int i=0, buzz =8;
//int ldrStatus

//int btns =2;

 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 2
#define DIO 3

// The amount of time (in milliseconds) between tests
#define TEST_DELAY   2000
int lco=0000;
int cont = 259;
TM1637Display display(CLK, DIO);
int c=178;


void setup() {
display.setBrightness(0xF);
 uint8_t data[] = { 0x0, 0x0, 0x0, 0x0 };
 display.setSegments(data);

   Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();
  
  pinMode(6,OUTPUT);
  //Serial.begin(9600);
   //attachInterrupt(1,interrupt1, RISING);   
}
void(*resetFunc)(void)= 0;
void loop() {

digitalWrite(6,HIGH);
funk();  while(c>0){
 uint8_t segto;
 display.showNumberDec(cont, true);
 funk();
 delay(465);
 cont--;
 segto = 0x80 | display.encodeDigit((cont / 100)%10);
 funk();
 display.setSegments(&segto, 1, 1);
 funk();
 delay(465);
 if (cont==200||cont==100){
 cont-=41;
 funk();
 }
 
 c--;
   }
 //if (++cont == 10000)
 
}
/*
  
if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
     
  }//Show UID on serial monitor
  Serial.print("UID tag :");
  String content1= " ";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
     
  }
  
  Serial.println();
  Serial.print("Message : ");
  int flag=0;
  content.toUpperCase();
  if (content.substring(1) == "E5 B1 5F 1C") //change here the UID of the card/cards that you want to give access
{ //Serial.print(content.substring(1) );

     //flag=1;
 //   int x=millis();
    delay(1000);
    fuck();
    return();
   // else
 //{   
 if(flag==10)
 {last();
 }
 }
  //  break();
// 

  
 
 else   {
    Serial.println(" Access denied");
  }
  /*goto PQR;
  ABC: last();
  PQR: ;
*/
  

void funk(){
  //int flag=0;
  static int flag=0;
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
 return;
    //flag++;
  }
 
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    flag++;
  //return;
  }
  //Show UID on serial monitor
//delay(1000);
 // Serial.print(flag);
//  return;
  /*if(flag>=10)
   {last();
   }
    */
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
     //flag++;
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  
  if(content.substring(1) == "4C 9D 5D 59" ) //change
//   here the UID of the card/cards that you want to give access
  {flag++;
     //Serial.println("going");
    
  
  // content.substring(1) = "E5 B1 5F 1B";
  delay(1000);
   Serial.println(flag);
 
    Serial.println();
    
    if(flag>=6)
   {
    last();
   }
    
    }
 //    
  
//  
//}
 else   {
  Serial.println(" Access denied");
   delay(1000);
 }
  

  }
  
  

  void func1(int x) {
    digitalWrite(buzzer,HIGH);
    delay(x);
    digitalWrite(buzzer,LOW);
}
void last()
{
  Serial.println(" done");
  display.showNumberDec(lco, true);
  digitalWrite(6,LOW);
    delay(10000);
    resetFunc();
 //digitalWrite(buzzer,LOW);

}

 
  
  

