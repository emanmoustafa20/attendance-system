#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance.

int readsuccess;
byte readcard[4];
char str[32] = "";
String StrUID;
String Name;
int n ;
int NumbCard[4];
int j=0; 

void setup() {
  Serial.begin(9600); // Initialize serial communications with the PC
  SPI.begin();      // Init SPI bus
  mfrc522.PCD_Init(); // Init MFRC522 card

  Serial.println("CLEARDATA");
  Serial.println("LABEL,Date,Time,RFID UID");
  delay(1000);
  
  Serial.println("Scan PICC to see UID...");
  Serial.println("");
}
// --------------------------------------------------------------------
void loop() {
  readsuccess = getid();
 
  if(readsuccess){
  
    if (StrUID == "8DB29435")
    {
      Name = "one";
      j=0;
      }
      if (StrUID == "70C69435")
    {
      Name = "two";
       j=1;
      }if (StrUID == "961D177E")
    {
      Name = "three";
       j=2;
      }if (StrUID == "D6CF227E")
    {
      Name = "four";
      j=3;
      }
    Serial.println( (String) "DATA,DATE,TIME," + StrUID +","+ Name );
  }
  if(NumbCard[j] == 0){//to check if the card already detect
      //if you want to use LCD
      Serial.println("Already Exist");
      }
      else{
      NumbCard[j] = 1;
       n++;
      }
}
// --------------------------------------------------------------------
int getid(){  
  if(!mfrc522.PICC_IsNewCardPresent()){
    return 0;
  }
  if(!mfrc522.PICC_ReadCardSerial()){
    return 0;
  }
 
  
  Serial.println("THE UID OF THE SCANNED CARD IS:");
  
  for(int i=0;i<4;i++){
    readcard[i]=mfrc522.uid.uidByte[i]; //storing the UID of the tag in readcard
    array_to_string(readcard, 4, str);
    StrUID = str;
  }

  mfrc522.PICC_HaltA();
  return 1;
}
// --------------------------------------------------------------------
void array_to_string(byte array[], unsigned int len, char buffer[])
{
    for (unsigned int i = 0; i < len; i++)
    {
        byte nib1 = (array[i] >> 4) & 0x0F;
        byte nib2 = (array[i] >> 0) & 0x0F;
        buffer[i*2+0] = nib1  < 0xA ? '0' + nib1  : 'A' + nib1  - 0xA;
        buffer[i*2+1] = nib2  < 0xA ? '0' + nib2  : 'A' + nib2  - 0xA;
    }
    buffer[len*2] = '\0';
}
