#include <SoftwareSerial.h>
#include <math.h>

SoftwareSerial RFID(19,23); // TX and RX

String ID; 
char c;

 
void analysis_data() 
{ 
  ID = ID.substring(1, 11);
  Serial.println("Card ID : " );
  Serial.println(ID);
}
void read_rfid(){ 
    while (RFID.available() > 0) {
    delay(5);
    c = RFID.read();
    ID += c;
    }
    if (ID.length() > 20)
    analysis_data();
    
    delay(100);
    
}
void reset_id() 
{ 
    ID = ""; 
}
