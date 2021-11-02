#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

#define trigPin 7
#define echoPin 6
#define redLED A4
#define greenLED A5

void setup() {
  // Initiate virtual terminal for serial signal
  Serial.begin(9600);  

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  
  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, LOW);

  lcd.begin(16, 2);
}

void loop(){
  lcd.clear();
  
  // generate a digital signal on trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // measure the time (int microseconds) it took for the echoPin to get from LOW to HIGH
  long duration = pulseIn(echoPin, HIGH);

  // speed of sound in air is 340 m/s 
  float distance = (3.4 * duration / 2)/100.00;    

  if (distance > 100.00) {
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
  } else {
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
  }

  lcd.setCursor(0, 0);
  lcd.print(distance);

  // print the distance on the virtual terminal
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.print("cm");
  Serial.println();
  
  delay(300);
}
