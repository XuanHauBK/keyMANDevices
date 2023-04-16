#include <Arduino.h>
#include <uart_rfid.h>
#include <test.h>

#define passadmin 0000
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  RFID.begin(9600);
} 

void loop() {
// put your main code here, to run repeatedly:
  int data = 1;
  read_rfid();  
  if(quetID() == 1 && ID != ""){ 
    Serial.println("the da ton tai");  
    reset_id();
    return; 

  }
  if(quetID() == 0 && ID != "")
  {
    Serial.println("Co muon them thanh vien moi khong?");
    if (data == 1)
    {
      Serial.println("Nhap pass admin");
      sl++;
      nhap();
     
    }
    
  }
  
 reset_id();
  
delay(100);
}