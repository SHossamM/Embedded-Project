#include <LiquidCrystal.h>
#include "Ultrasonic.h"
long distance  ;
float timer_int ;
bool parksystem ;
float velocity = 10.0f ;
// tp -> 10 
//ep -> 11
const int rs = 12, en = 13, d4 = 5, d5 = 4, d6 = 3, d7 = 2, ep = 8, tp = 9;
Ultrasonic ult = Ultrasonic(10,11,40/100,1);
Ultrasonic frontUltrasonic = Ultrasonic(tp,ep,0.3,1); //forward distance is 3cm


LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() 
{
  parksystem = false ;
  setupLCD();
  Serial.begin(9600);
}



void loop() {
  while(!parksystem)
  {
    distance = ult.Ranging(1);
    if (distance < 40 )
    {
        lcd.clear();
      continue ;
    Serial.println(" no space at first distance is:  ");
    Serial.print(distance);
    }
    timer_int = millis();
    while(!parksystem)
    {
      
      if ( velocity *((millis ()-timer_int)/1000) > 40)
      {
        
        Serial.println("  space found  ");
        Serial.println(ult.Ranging(1));
        
        if(checkForward())
        {
          displaySlotDetected();
          parksystem = true ;
        }
        break ;
      }
        
      distance = ult.Ranging(1) ;
      
      if(distance <40)
      {
            lcd.clear();
            Serial.println(" no space at first distance is:  ");
            Serial.print(distance);
            break ;
      
      }
      }
  }
}

/*************** Front Ultrasonic Sensor Functions ************/
bool checkForward()
{
  float distance = frontUltrasonic.Ranging(1);  
  if(distance<30)
  return false;
  else
  return true;
}

/*********************** LCD FUNCTIONS ***********************/

void setupLCD()

{

  lcd.begin(16, 2);

}



void displayWarning()

{

  lcd.clear();

  lcd.setCursor(0, 0);

  lcd.print("Slow down to en_");

  lcd.setCursor(0,1);

  lcd.print("able the system.");

}



void displaySlotDetected()

{

  lcd.clear();

  lcd.setCursor(0,0);

  lcd.print("A parking slot");

  lcd.setCursor(0,1);

  lcd.print("is detected!");
delay(60);
}



void displaySystemActivated()

{

  lcd.clear();

  lcd.setCursor(0,0);

  lcd.print("Slot detection");

  lcd.setCursor(0,1);

  lcd.print("is activated.");

}



void displayKeepMoving()

{

  lcd.clear();

  lcd.setCursor(0,0);

  lcd.print("No slot detected");

  lcd.setCursor(0,1);

  lcd.print("Keep moving...");

}

/**********************************************************/
