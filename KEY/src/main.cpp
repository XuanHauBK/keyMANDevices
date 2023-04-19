#include <Arduino.h>
#include <uart_rfid.h>
#include <test.h> 
#include <keypad_lcd.h>

char mode1;
char mode2;
char hello;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  RFID.begin(9600);
} 

void loop() {
// put your main code here, to run repeatedly:
  
  mode1 = myKeypad.getKey();
  if (mode1)
  { mode1=0;
    turn_on_LCD();
    lcd.clear();
    lcd.setCursor(0,0); // sets the cursor on the lcd
    lcd.print("Chon che do");
    delay(1000);
    lcd.clear();
    lcd.setCursor(1,0); // sets the cursor on the lcd
    lcd.print("1.Password");
    lcd.setCursor(1,1); // sets the cursor on the lcd
    lcd.print("2.ID"); 
    while ( mode1 == 0)
    {
      /* code */mode1 = myKeypad.getKey();
    }
    
  
    delay(1000);
    //mode1 = myKeypad.getKey();
    if(mode1 == '1')
    { 
      lcd.clear();
      enter_password();
    }
    else if(mode1 == '2') 
    { 
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Quet the");
      reset_id;
      while (ID == "")
      {
        /* code */
        read_rfid();
      }
      
      unsigned long time;
      
      lcd.print("Quet the 2");
      if(quetID() == 0 && ID != "")
      {
        lcd.clear();
        lcd.print("Add member?");
        delay(1000);
        lcd.clear();
        lcd.setCursor(1,0);
        lcd.print("1.Yes");
        lcd.setCursor(1,1);
        lcd.print("2.No");
        delay(4000);
        lcd.clear();   
        while ( hello == 0)
    {
      /* code */hello = myKeypad.getKey();
    }
    
        if (hello =='1')
        {
          add_member();
        }

      } 

    }
    else 
    {
      lcd.clear();
      lcd.setCursor(1,0); // sets the cursor on the lcd
      lcd.print("Press Wrong ccc");
      delay(1000);
      return;
    }
  }
   reset_id();
}