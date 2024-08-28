#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>  

Servo myservo1;
Servo myservo2;

 int pos = 0;  

LiquidCrystal_I2C lcd(0x38, 16, 2);

const int initialHours = 48;
int hoursRemaining;
int minutesRemaining;
int secondsRemaining;
unsigned long previousMillis = 0;
const long interval = 1000;

void setup() {
  myservo1.attach(7);    
 myservo2.attach(9);
 myservo2.write(90);
  myservo1.write(90);  


  lcd.begin();
  lcd.backlight();
  hoursRemaining = initialHours;
  minutesRemaining = 0;
  secondsRemaining = 0;
  updateDisplay();
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if (secondsRemaining == 0) {
      if (minutesRemaining == 0) {
        if (hoursRemaining == 0) {
          hoursRemaining = 0;
          
        } else {
          hoursRemaining--;
          minutesRemaining = 59;
          secondsRemaining = 59;
        }
      } else {
        minutesRemaining--;
        secondsRemaining = 59;
      }
    } else {
      secondsRemaining--;
    }

    updateDisplay();
  }
}

void updateDisplay() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Time Remaining:");
  lcd.setCursor(0, 1);
  if (hoursRemaining < 10) lcd.print("0");
  lcd.print(hoursRemaining);
  lcd.print(":");
  if (minutesRemaining < 10) lcd.print("0");
  lcd.print(minutesRemaining);
  lcd.print(":");
  if (secondsRemaining < 10) lcd.print("0");
  lcd.print(secondsRemaining);
}
