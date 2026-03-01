#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD 
LiquidCrystal_I2C lcd(0x27, 16, 2);

// SHIFT REGISTER 
const int dataPin  = 11;
const int clockPin = 12;
const int latchPin = 13;

uint32_t ledState = 0;

// JOYSTICK 
const int joyX = A0;
const int joyY = A1;
const int joySW = 2;

// BUZZER 
const int buzzerPin = 3;

// LED MAPPING
const byte letterToLed[26] = {
  29,27,26,24,21,19,17,16,28,13,11,25,9,
  20,4,18,2,14,12,10,8,6,5,3,1,0
};

// CURSOR 
int cursorX = 0;
int cursorY = 0;

// MESSAGE
int message[32];
int messageLength = 0;

// TIMING
unsigned long lastMove = 0;

// SETUP
void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(joySW, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.noBlink();

  randomSeed(analogRead(A2));
  clearLEDs();
  drawAlphabet();
}

// LOOP
void loop() {
  handleJoystick();
  handleButton();
}

// JOYSTICK
void handleJoystick() {

  int x = analogRead(joyX);
  int y = analogRead(joyY);

  if (millis() - lastMove > 200) {

    if (x < 300) {
      cursorX--;
      if (cursorX < 0) cursorX = (cursorY == 1 ? 13 : 12);
      lastMove = millis();
      drawAlphabet();
    }

    if (x > 700) {
      cursorX++;
      if (cursorY == 0 && cursorX > 12) cursorX = 0;
      if (cursorY == 1 && cursorX > 13) cursorX = 0;
      lastMove = millis();
      drawAlphabet();
    }

    if (y < 300) {
      cursorY = 0;
      if (cursorX > 12) cursorX = 12;
      lastMove = millis();
      drawAlphabet();
    }

    if (y > 700) {
      cursorY = 1;
      lastMove = millis();
      drawAlphabet();
    }
  }
}

// BUTTON 
void handleButton() {

  if (digitalRead(joySW) == LOW) {
    delay(50);

    if (cursorY == 1 && cursorX == 13) {
      sendMessage();
    } else {
      addLetter();
    }

    while (digitalRead(joySW) == LOW);
  }
}

// DISPLAY 
void drawAlphabet() {

  lcd.clear();

  lcd.setCursor(0, 0);
  for (int i = 0; i < 13; i++) {
    lcd.print(char('A' + i));
  }

  lcd.setCursor(0, 1);
  for (int i = 13; i < 26; i++) {
    lcd.print(char('A' + i));
  }

  lcd.setCursor(13, 1);
  lcd.print(">");

  lcd.setCursor(cursorX, cursorY);
  lcd.blink();
}

// ADD LETTER
void addLetter() {
  int letterIndex = cursorY * 13 + cursorX;

  if (letterIndex < 26 && messageLength < 32) {
    message[messageLength++] = letterIndex;
    tone(buzzerPin, 800, 100); 
  }
}

// SEND MESSAGE 
void sendMessage() {

  lcd.clear();
  lcd.print("Sending...");
  tone(buzzerPin, 1200, 200);
  delay(800);

  playMessage();
  chaosMode(5000);

  messageLength = 0;
  drawAlphabet();
}

// LED CONTROL
void turnOnLED(int letterIndex) {
  ledState = 0;
  ledState |= (1UL << letterToLed[letterIndex]);
  updateShiftRegister();
}

void clearLEDs() {
  ledState = 0;
  updateShiftRegister();
}

void updateShiftRegister() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, (ledState >> 24) & 0xFF);
  shiftOut(dataPin, clockPin, MSBFIRST, (ledState >> 16) & 0xFF);
  shiftOut(dataPin, clockPin, MSBFIRST, (ledState >> 8) & 0xFF);
  shiftOut(dataPin, clockPin, MSBFIRST, ledState & 0xFF);
  digitalWrite(latchPin, HIGH);
}

// PLAYBACK
void playMessage() {

  clearLEDs();
  delay(500);

  for (int i = 0; i < messageLength; i++) {

    int freq = 400 + (message[i] * 20); 

    turnOnLED(message[i]);
    tone(buzzerPin, freq, 300);

    delay(700);
    clearLEDs();
    delay(200);
  }
}

// CHAOS MODE
void chaosMode(int durationMs) {

  unsigned long start = millis();

  while (millis() - start < durationMs) {

    int rndLetter = random(0, 26);
    int rndFreq = random(200, 2000);
    int rndDelay = random(50, 200);

    turnOnLED(rndLetter);
    tone(buzzerPin, rndFreq);

    delay(rndDelay);
  }

  noTone(buzzerPin);
  clearLEDs();
}