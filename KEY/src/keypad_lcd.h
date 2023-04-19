#include <Keypad.h> // the library for the 4x4 keypad
#include <LiquidCrystal_I2C.h> // the library for the i2c 1602 lcd

LiquidCrystal_I2C lcd(0x27,16,2); // gets the lcd 


#define Password_Length 5 // the length of the password, if the password is 4 digits long set this to 5
#define Passadmin_Length 9
char Particular1[Password_Length]; // the password length 
char Particular2[Passadmin_Length];
char Specific[Password_Length] = "2211"; // the password which is called specific in the code, change this to anything you want with the numbers 0-9 and the letters A-D
char Admin[Passadmin_Length] = "22112002";
byte Particular_Count = 0, Specific_Count = 0; // counts the amount of digits and and checks to see if the password is correct

char Key; 
const byte ROWS = 4; // the amount of rows on the keypad
const byte COLS = 4; // the amount of columns on the keypad
char keys[ROWS][COLS] = { // sets the rowns and columns
  // sets the keypad digits
  {'1','2','3','A'}, 

  {'4','5','6','B'},

  {'7','8','9','C'},

  {'*','0','#','D'}
};
bool Password = 0; // the servo 
bool Passadmin = 0;
char press;
// the pins to plug the keypad into
static byte rowPins[ROWS] = {14, 12, 13, 15};
static byte colPins[COLS] = {2, 4, 16, 17};
Keypad myKeypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS); // gets the data from the keypad
// locked charcater
byte Locked[8] = { 
  B01110,
  B10001,
  B10001,
  B11111,
  B11011,
  B11011,
  B11011,
  B11111
};
// open character
byte Opened[8] = {
  B01110,
  B00001,
  B00001,
  B11111,
  B11011,
  B11011,
  B11011,
  B11111
};

void turn_on_LCD()
{
  lcd.init(); // initializes the lcd 
  lcd.backlight(); // turns on the backlight
  lcd.setCursor(0,0); // sets the cursor on the lcd
  lcd.print("MANDEVICES LAB"); // prints the text/charater
  delay(4000); // waits 4 seconds
  lcd.clear(); // clears the lcd diplay
}

void Select()
{

  
}

void clearData() // clears the data
{
  while (Particular_Count != 0) // counts the digits pressed
  {
    Particular1[Particular_Count--] = 0; // counts how many digits 
    Particular2[Particular_Count--] = 0;
  }
  return; // returns the data
}

void add_member()
{ 
  lcd.setCursor(1,0); // sets the cursor on the lcd
  lcd.print("Enter Password:"); // prints the text
  while(Passadmin == 0)
  {
  Key = myKeypad.getKey(); // gets the keys you press from the keypad
  if (Key)
  {
    Particular2[Particular_Count] = Key; 
    lcd.setCursor(Particular_Count, 1); // sets the cursor on the lcd
    lcd.print("*"); // prints '*' instead of the password
    Particular_Count++; // counts the length of the password
  }

  if (Particular_Count == Passadmin_Length - 1) // gets the length of the password 
  {
    if (!strcmp(Particular2, Admin)) // counts the length and checks to see if the password is correct
    {
      lcd.clear();
      lcd.setCursor(2,0); // sets the cursor on the lcd
      lcd.print("Door Opened");
      lcd.createChar(1, Opened);
      lcd.setCursor(14,0); // sets the cursor on the lcd
      lcd.write(1);
      lcd.setCursor(0,1); // sets the cursor on the lcd
      lcd.print("Press A to add member");
      Passadmin = 1;
    }
    else
    {
      lcd.clear();
      lcd.setCursor(0,0); // sets the cursor on the lcd
      lcd.print("Wrong Password"); // prints the text/character
      lcd.setCursor(0,1);
      lcd.print("Try Again In");
      lcd.setCursor(13,1);
      lcd.print("10");
      delay(1000);
      lcd.setCursor(13,1);
      lcd.print("09");
      delay(1000);
      lcd.setCursor(13,1);
      lcd.print("08");
      delay(1000);
      lcd.setCursor(13,1);
      lcd.print("07");
      delay(1000);
      lcd.setCursor(13,1);
      lcd.print("06");
      delay(1000);
      lcd.setCursor(13,1);
      lcd.print("05");
      delay(1000);
      lcd.setCursor(13,1);
      lcd.print("04");
      delay(1000);
      lcd.setCursor(13,1);
      lcd.print("03");
      delay(1000);
      lcd.setCursor(13,1);
      lcd.print("02");
      delay(1000);
      lcd.setCursor(13,1);
      lcd.print("01");
      delay(1000);
      lcd.setCursor(13,1);
      lcd.print("00");
      delay(1000);
      lcd.clear();
    }
    clearData(); // clears the data
  }
} 
  lcd.print("Press B to add member");
  delay(1000);
   Key=0;
   while ( Key == 0)
    {
          Key = myKeypad.getKey(); // the word key = myKeypad which gets the value
    }
  
    
    if(Key == 'A')
    {
      lcd.clear(); // clears the lcd diplay
      lcd.setCursor(0,0); // sets the cursor on the lcd
      lcd.print("ENTER MSSV"); // prints the text to the lcd
      delay(1000);
      int i;
      while(myKeypad.getKey()!=0||i<9)
      {
        lab[sl].MSSV+=myKeypad.getKey();
        i=(lab[sl].MSSV).length();
      }
      Passadmin = 0; // closes the door
    }

}
void enter_password()
{
  lcd.setCursor(1,0); // sets the cursor on the lcd
  lcd.print("Enter Password:"); // prints the text
  while(Password == 0)
  {
  Key = myKeypad.getKey(); // gets the keys you press from the keypad
  if (Key)
  {
    Particular1[Particular_Count] = Key; 
    lcd.setCursor(Particular_Count, 1); // sets the cursor on the lcd
    lcd.print("*"); // prints '*' instead of the password
    Particular_Count++; // counts the length of the password
  }

  if (Particular_Count == Password_Length - 1) // gets the length of the password 
  {
    if (!strcmp(Particular1, Specific)) // counts the length and checks to see if the password is correct
    {
      lcd.clear();
      lcd.setCursor(2,0); // sets the cursor on the lcd
      lcd.print("Door Opened");
      lcd.createChar(1, Opened);
      lcd.setCursor(14,0); // sets the cursor on the lcd
      lcd.write(1);
      lcd.setCursor(0,1); // sets the cursor on the lcd
      lcd.print("Press A to get key");
      Password = 1;
    }
    else
    {
      lcd.clear();
      lcd.setCursor(0,0); // sets the cursor on the lcd
      lcd.print("Wrong Password"); // prints the text/character
      lcd.setCursor(0,1);
      lcd.print("Try Again In");
      lcd.setCursor(13,1);
      lcd.print("10");
      delay(1000);
      lcd.setCursor(13,1);
      lcd.print("09");
      delay(1000);
      lcd.setCursor(13,1);
      lcd.print("08");
      delay(1000);
      lcd.setCursor(13,1);
      lcd.print("07");
      delay(1000);
      lcd.setCursor(13,1);
      lcd.print("06");
      delay(1000);
      lcd.setCursor(13,1);
      lcd.print("05");
      delay(1000);
      lcd.setCursor(13,1);
      lcd.print("04");
      delay(1000);
      lcd.setCursor(13,1);
      lcd.print("03");
      delay(1000);
      lcd.setCursor(13,1);
      lcd.print("02");
      delay(1000);
      lcd.setCursor(13,1);
      lcd.print("01");
      delay(1000);
      lcd.setCursor(13,1);
      lcd.print("00");
      delay(1000);
      lcd.clear();
    }
    clearData(); // clears the data
  }
} 
    Key = myKeypad.getKey(); // the word key = myKeypad which gets the value
    while (Key == 'A') // when the 'A' key is pressed

    {
      lcd.clear(); // clears the lcd diplay
      lcd.setCursor(2,0); // sets the cursor on the lcd
      lcd.print("Nhap mat khau thanh cong"); // prints the text to the lcd
      lcd.createChar(0, Locked); // prints the locked character 
      lcd.setCursor(14,0); // sets the cursor on the lcd
      lcd.write(0); // prints the first character when you are on the door closed page
      delay(3000); // waits 3 seconds
      Password = 0; // closes the door
    }
}


