#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

const unsigned int flamePin = 7;

void setup() {
  pinMode(flamePin, INPUT);

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Status: ");
}

void loop() {
  lcd.setCursor(0, 1);
  
  if (digitalRead(flamePin) == HIGH) {
    lcd.print("Flame, Run!    ");
  } else {
    lcd.print("No Flame, Relax");
  }
}
