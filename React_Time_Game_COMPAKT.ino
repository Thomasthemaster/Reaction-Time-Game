/* Reaction Time Speed Game COMPAKT Version (on 1 singular breadboard)
  USING A 16x2 LCD (not I2C)

  Contains a Reaction Time Speed Game + Very Cool Anti-Cheat
  Made on Aug 29, 2026 by Thomas
*/

// LCD Stuff
#include <LiquidCrystal.h>

int rsPin = 3;
int enPin = 6;
int d4Pin = 8;
int d5Pin = 10;
int d6Pin = 11;
int d7Pin = 12;

LiquidCrystal lcd(rsPin, enPin, d4Pin, d5Pin, d6Pin, d7Pin);

// Other Stuff

int setUpDelay = 1000;
int startDelay = 1000;
int celebrationDelay = 2500;
int cheatDelay = 3000;
int buzzDelay = 100;

int buttonPin = 2;
int buttonVal;

int ledPins[] = {A3, A4, A5, 9, 7};
int targetLedIndex = 2;

int buzzerPin = A0;

int cheatScore;
int cheatThreshold = 5;
int i;

bool devCheat;
int devPin = 4;
bool devRig;
int devRigPin = 5;

void checkForCheating() {
  buttonVal = digitalRead(buttonPin);
  if (buttonVal == 0) {
    cheatScore = cheatScore + 1;
    buttonVal = digitalRead(buttonPin);
  }
  if (cheatScore >= cheatThreshold) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("CHEATING ");
    lcd.setCursor(0, 1);
    lcd.print(" DETECTED! ");
    delay(cheatDelay);
    while(true) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("how dare you");
      lcd.setCursor(0, 1);
      lcd.print("CHEAAAAAAAATTT!!");
      delay(cheatDelay);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("press reset on");
      lcd.setCursor(0, 1);
      lcd.print("arduino");
      delay(cheatDelay);
    }
  }
}

void setup() {
  Serial.begin(115200);
  lcd.begin(16, 2);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);
  pinMode(devPin, INPUT_PULLUP);
  if (digitalRead(devPin) == LOW) { // If the wire is there
    devCheat = true;
  }
  pinMode(devRigPin, INPUT_PULLUP);
  if (digitalRead(devRigPin) == LOW) { // If the wire is there
    devRig = true;
  }
  else {
    devRig = false;
  }
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  // Seed the random generator using background static noise from an empty pin
  randomSeed(analogRead(A2)); 

  delay(setUpDelay);
  
  lcd.setCursor(0, 0);
  lcd.print("Press button");
  lcd.setCursor(5, 1);
  lcd.print("to begin");
  buttonVal = digitalRead(buttonPin);
  while (buttonVal != 0) {
    buttonVal = digitalRead(buttonPin);
  }
  lcd.clear();
}

void loop() {
  cheatScore = 0;
  lcd.setCursor(0, 0);
  lcd.print("Game Starting...");
  delay(startDelay);
  lcd.clear();

  // --- THE RANDOM FLASHING PHASE ---
  int totalIntroFlashes = random(12, 20); // Blink side lights at least 12 times before target
  
  for (int f = 0; f < totalIntroFlashes; f++) {
    int currentRandomIndex;
    
    // Pick a random number between 0 and 4
    currentRandomIndex = random(0, 5); 
    
    // HIDDEN RULE: If it randomly picks the middle target index, 
    // we make it re-roll a new number so it stays a mystery side light!
    while (currentRandomIndex == targetLedIndex) {
      currentRandomIndex = random(0, 5);
    }

    checkForCheating();

    // Turn ON the picked random LED
    digitalWrite(ledPins[currentRandomIndex], HIGH);
    delay(300); // Keep it on for a split second
    
    checkForCheating();

    // Turn OFF the picked random LED
    digitalWrite(ledPins[currentRandomIndex], LOW);
    delay(200); // Small gap before the next jump
    
    checkForCheating();
  }

  lcd.setCursor(0, 0);
  lcd.print("!!! SMACK IT !!!");
  digitalWrite(ledPins[targetLedIndex], HIGH);
  digitalWrite(buzzerPin, HIGH);

  unsigned long startTime = millis(); // Start time in milliseconds
  buttonVal = digitalRead(buttonPin);
  while (buttonVal != 0) {
    buttonVal = digitalRead(buttonPin);
  }
  digitalWrite(buzzerPin, LOW);
  unsigned long reactTime = millis() - startTime; // Calculates reaction speed
  digitalWrite(ledPins[targetLedIndex], LOW);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Your Time is: ");
  lcd.setCursor(0, 1);
  if (devCheat == true) {
    reactTime = random(100, 150); // adjustable based on what you want
  }
  if (devRig == true) {
    reactTime = reactTime + 100; // you can increase more if you want
  }
  lcd.print(reactTime);
  lcd.print(" ms!  ");
  delay(celebrationDelay);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Reset by press");
  lcd.setCursor(0, 1);
  lcd.print(reactTime);
  lcd.print(" ms!  ");

  buttonVal = digitalRead(buttonPin);
  while (buttonVal != 0) {
    buttonVal = digitalRead(buttonPin);
  }
  buttonVal = digitalRead(buttonPin);
  while (buttonVal != 1) {
    buttonVal = digitalRead(buttonPin);
  }
  lcd.clear();
  digitalWrite(buzzerPin, HIGH);
  delay(buzzDelay);
  digitalWrite(buzzerPin, LOW);
}
