/*
#include <SPI.h>
#include <MFRC522.h>
#include <math.h>
#define SS_PIN 5
#define RST_PIN 15

MFRC522 rfid(SS_PIN, RST_PIN);

MFRC522::MIFARE_Key key;
long long ID = 0;
byte nuidPICC[4]; // Init array chua id
void printHex(byte *buffer, byte buffersize)
{
    for (byte i = 0; i < buffersize; i++ )
    {
        Serial.print(buffer[i] < 0x10 ? "0" : " ");
        Serial.print(buffer[i], HEX);
    }
}

void printDec(byte *buffer, byte buffersize)
{  
    
    for (byte i = 0; i < buffersize; i++ )
    {
        Serial.print(buffer[i] < 0x10 ? "0" : " ");
        ID += buffer[i] *  pow(256,i);
        
    }
    Serial.println(ID);
}
void readRFID()
{  
    // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if ( ! rfid.PICC_IsNewCardPresent())
    return;

  // Verify if the NUID has been readed
  if ( ! rfid.PICC_ReadCardSerial())
    return;

  if (rfid.uid.uidByte[0] != nuidPICC[0] || 
    rfid.uid.uidByte[1] != nuidPICC[1] || 
    rfid.uid.uidByte[2] != nuidPICC[2] || 
    rfid.uid.uidByte[3] != nuidPICC[3] ) {
    Serial.println(F("A new card has been detected."));

    // Store NUID into nuidPICC array
    for (byte i = 0; i < 4; i++) {
      nuidPICC[i] = rfid.uid.uidByte[i];
    }
   
    Serial.print(F("ID: "));
    printDec(rfid.uid.uidByte, rfid.uid.size);
    

  }
  else Serial.println(F("Card read previously."));



  
}
*/