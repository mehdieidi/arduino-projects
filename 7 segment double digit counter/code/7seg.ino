//a1 13
//b1 12
//c1 11
//d1 10
//e1 9
//f1 8
//g1 7
//a2 6
//b2 5
//c2 4
//d2 3
//e2 2
//f2 1
//g2 0

int nums[10][7] = {{ HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,LOW },   // 0
                   { LOW,HIGH,HIGH,LOW,LOW,LOW,LOW },       // 1
                   { HIGH,HIGH,LOW,HIGH,HIGH,LOW,HIGH },    // 2
                   { HIGH,HIGH,HIGH,HIGH,LOW,LOW,HIGH },    // 3
                   { LOW,HIGH,HIGH,LOW,LOW,HIGH,HIGH },     // 4
                   { HIGH,LOW,HIGH,HIGH,LOW,HIGH,HIGH },    // 5
                   { HIGH,LOW,HIGH,HIGH,HIGH,HIGH,HIGH },   // 6
                   { HIGH,HIGH,HIGH,LOW,LOW,LOW,LOW },      // 7
                   { HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH },  // 8
                   { HIGH,HIGH,HIGH,LOW,LOW,HIGH,HIGH }};   // 9
   

void displayNum(int num);
void displayTens(int t);
void displayOnes(int o);

void setup() {
  for (int i = 0; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }

  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
}

void loop() {
  digitalWrite(A5, HIGH);
  
  // main algorithm for finding prime nums between 1-100
  for (int i = 2; i < 100; i++) {
    int count = 0;
    for (int j = 2; j <= i/2; j++) {
      if (i % j == 0) {
        count++;
        break;
      }
    }

    if (count == 0) {
      if (i > 50) {
        digitalWrite(A5, LOW);
        digitalWrite(A4, HIGH);
      }
      
      displayNum(i);
      delay(400);
    }
  }

  // reset the left 7 segment and turn red led off
  displayTens(0);
  digitalWrite(A4, LOW);
}

// displayNum displays the given num on the 7 segments
void displayNum(int num) {
  if (num > 9) {
    int t = (int) num / 10;
    int o = num % 10;

    displayTens(t);
    displayOnes(o);
  } else {
    displayOnes(num);
  }
}

// displayOnes displays the number o on the right 7 segment
void displayOnes(int o) {
  int pin = 6;
  for (int i = 0; i < 7; i++) {
    digitalWrite(pin, nums[o][i]);
    pin--;
  }
}

// displaysTens displays the number t on the left 7 segment
void displayTens(int t) {
  int pin = 13;
  for (int i = 0; i < 7; i++) {
    digitalWrite(pin, nums[t][i]);
    pin--;
  }
}
