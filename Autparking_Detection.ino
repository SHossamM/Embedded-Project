#include <LiquidCrystal.h>
const int rs = 12, en = 13, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  setupLCD();
}

void loop() {
  displayWarning();
  delay(2000);
  displaySlotDetected();
  delay(2000);
  displaySystemActivated();
  delay(2000);
  displayKeepMoving();
  delay(2000);
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
