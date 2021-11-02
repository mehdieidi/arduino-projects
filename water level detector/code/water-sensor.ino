#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2); 
 
int analogValue = 0;  
int sensorPin = A3; 
  
void setup() {  
  lcd.begin(16, 2); 

  lcd.print("Level Of Water:"); 
} 

void loop() { 
  lcd.setCursor(0, 1); 
  
  analogValue = analogRead(sensorPin); 
  
  lcd.print(analogValue);
}
