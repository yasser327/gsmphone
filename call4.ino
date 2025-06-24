#include <Wire.h>

#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

SoftwareSerial sim800l(11, 10);
const byte ROWS = 4; 
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

LiquidCrystal_I2C lcd(0x27, 16, 2);  

void setup(){
  Serial.begin(9600);  
  sim800l.begin(9600); 
 // lcd.begin(16, 2); //initialize the lcd
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);  lcd.print("Enter a number:"); //prompt
}

void loop(){
  char key = keypad.getKey(); //get key from keypad
  if (key){
    lcd.clear(); //clear the screen
    
         Serial.print(key);

    // Display different messages based on the key pressed
    switch(key){
      case 'A':
        sim800l.println("ATA");
        Serial.println("ATA");

        break;
      case 'B':
        sim800l.println("ATH");
        Serial.println("ATH");

        break;

      case '1':
        lcd.setCursor(0, 0);
        Serial.println("calling");
        lcd.setCursor(1, 1);
        lcd.print("The creator");
        Serial.println("ATD+num1;");
        delay(3000);

        break;
      case '2':
        lcd.setCursor(0, 0);
        Serial.println("calling");
        lcd.setCursor(1, 1);
        lcd.print("nm2");
        Serial.println("ATD+num2;");
        sim800l.println("ATD+num2;");
        
        Serial.print(key);
        delay(3000);

        break;
      case '3':
        lcd.setCursor(0, 0);
        lcd.print("calling");
        lcd.setCursor(1, 1);
        lcd.print("num3");
        sim800l.println("ATD+num3");
        
        delay(3000);

        break;
        case '4':
        lcd.setCursor(0, 0);
        lcd.print("calling..");
        lcd.setCursor(1, 1);
        lcd.print("num4");
        Serial.println("ATD+num4");
        sim800l.println("ATD+num4;");
        
        delay(3000);

        break;
        case'5':
        sim800l.println("AT+CLIP=1");
        lcd.setCursor(0, 0);
        lcd.print("calling..");
        lcd.setCursor(1, 1);
        lcd.print("num5");
        Serial.println("ATD+num5;");
        sim800l.println("ATD+num5;");
        
        delay(3000);
       break;
       case'6':
        sim800l.println("AT+CLIP=1");
        lcd.setCursor(0, 0);
        lcd.print("calling..");
        lcd.setCursor(1, 1);
        lcd.print("num");
        Serial.println("ATD+num6;");
        sim800l.println("ATD+num6");
        
        delay(3000);
       break;
       case'7':
        sim800l.println("AT+CLIP=1");
        lcd.setCursor(0, 0);
        lcd.print("calling..");
        lcd.setCursor(1, 1);
        lcd.print("num");
        Serial.println("ATD+num7;");
        sim800l.println("ATD+num7;");
        
        delay(3000);
       break;
       

      
      default:
        lcd.setCursor(0, 1);
        lcd.print("Invalid key");
        break;
    }

    delay(3000); //delay for readability
    lcd.clear(); //clear the screen
    lcd.print("Enter a number:"); //prompt
  }
}
