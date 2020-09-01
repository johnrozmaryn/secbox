

/*
  Showing number 0-9 on a Common Anode 7-segment LED display (plus the eigth decimal poit)
    A
   ---
F |   | B
  | G |
   ---
E |   | C
  |   |
   ---        X Decimal
    D
 */

int pinA = 12;
int pinB = 8;
int pinC = 5;
int pinD = 3;
int pinE = 2;
int pinF = 11;
int pinG = 6;
//int pinDP = 4; I don't think I'm going to use the decimal points
int D1 = 13;
int D2 = 10;
int D3 = 9;
int D4 = 7;
int SW1 = A4;  
int SW10 = A5; 
int SW100 = A3;
int SW1000 = A2;
int SWRandomizer = A0;

int btnGuess = A1;
int pinSpeaker = 4;

int stateSW1 = LOW;
int stateSW10 = LOW;
int stateSW100 = LOW;
int stateSW1000 = LOW;
int stateRandomizer = LOW;

long n = 1234; //n represents value displayed on the LED display. When n=0,0000 is displayed
int x = 100; //not sure what this is yet?
int del = 1; //used for fine tuning the display code

int count = 0; //This goes up by 1 every 0.1 second? Not sure if that's pertinent here yet

void setup() {
  // set all the pins to output
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
// pinMode(pinDP, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(pinSpeaker, OUTPUT);

  // these are my cool buttons
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW10, INPUT_PULLUP);
  pinMode(SW100, INPUT_PULLUP);
  pinMode(SW1000, INPUT_PULLUP);
  pinMode(btnGuess, INPUT_PULLUP);
  pinMode(SWRandomizer, INPUT_PULLUP);

  stateSW1 = digitalRead(SW1);
  stateSW10 = digitalRead(SW10);
  stateSW100 = digitalRead(SW100);
  stateSW1000 = digitalRead(SW1000); 
  stateRandomizer = digitalRead(SWRandomizer);
}

void loop() {
  // put your main code here, to run repeatedly:

  clearLEDs();//clear the 7-segment display screen
  pickDigit(0);//Light up 7-segment display d1
  pickNumber((n/1000));// get the value of thousand
  delay(del);//delay 5ms

  clearLEDs();//clear the 7-segment display screen
  pickDigit(1);//Light up 7-segment display d2
  pickNumber((n%1000)/100);// get the value of hundred
  delay(del);//delay 5ms

  clearLEDs();//clear the 7-segment display screen
  pickDigit(2);//Light up 7-segment display d3
  pickNumber(n%100/10);//get the value of ten
  delay(del);//delay 5ms

  clearLEDs();//clear the 7-segment display screen
  pickDigit(3);//Light up 7-segment display d4
  pickNumber(n%10);//Get the value of single digit
  delay(del);//delay 5ms
  
  if (stateSW1 != digitalRead(SW1)) add1();
  if (stateSW10 != digitalRead(SW10)) add10();
  if (stateSW100 != digitalRead(SW100)) add100();
  if (stateSW1000 != digitalRead(SW1000)) add1000();
  if (stateRandomizer != digitalRead(SWRandomizer)) {
    n=random(0,10000);
    stateRandomizer = digitalRead(SWRandomizer);
    }
  if (digitalRead(btnGuess) == LOW) guess();  
}


void pickDigit(int x) //
{
  //first, turn them all on high. Then we'll push the one we want low (if I have a common anode this will need to be backwards?

  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);

  switch(x)
  {
    case 0:
    digitalWrite(D1, LOW);
    break;
    case 1:
    digitalWrite(D2, LOW);
    break;
    case 2:
    digitalWrite(D3, LOW);
    break;
    case 3:
    digitalWrite(D4, LOW);
    break;
  }
}

void pickNumber(int x)
{
  switch(x)
  {
    default: 
    zero(); 
    break;
    case 1: 
    one(); 
    break;
    case 2: 
    two(); 
    break;
    case 3: 
    three(); 
    break;
    case 4: 
    four(); 
    break;
    case 5: 
    five(); 
    break;
    case 6: 
    six(); 
    break;
    case 7: 
    seven(); 
    break;
    case 8: 
    eight(); 
    break;
    case 9: 
    nine(); 
    break;
  }
}

void clearLEDs() //clear the 7-segment display screen
{
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
//  digitalWrite(pinDP, LOW);
}

void zero() //the 7-segment led display 0
{
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, LOW);
//  digitalWrite(pinDP, LOW);
}

void one() //the 7-segment led display 1
{
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
 // digitalWrite(pinDP, LOW);
}

void two() //the 7-segment led display 2
{
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
// digitalWrite(pinDP, LOW);
}
void three() //the 7-segment led display 3
{
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
//  digitalWrite(pinDP, LOW);
}

void four() //the 7-segment led display 4
{
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
//  digitalWrite(pinDP, LOW);
}

void five() //the 7-segment led display 5
{
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
//  digitalWrite(pinDP, LOW);
}

void six() //the 7-segment led display 6
{
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
 // digitalWrite(pinDP, LOW);
}

void seven() //the 7-segment led display 7
{
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
//  digitalWrite(pinDP, LOW);
}

void eight() //the 7-segment led display 8
{
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
//  digitalWrite(pinDP, LOW);
}

void nine() //the 7-segment led display 9
{
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
//  digitalWrite(pinDP, LOW);
}

void add1()
{
  n += 1;
  if (n > 9999) n = 0;
  stateSW1 = digitalRead(SW1);
}

void add10()
{
  n += 10;
  if (n > 9999) n = 0;
  stateSW10 = digitalRead(SW10);
}

void add100()
{
  n += 100;
  if (n > 9999) n = 0;
  stateSW100 = digitalRead(SW100);
}

void add1000()
{
  n += 1000;
  if (n > 9999) n = 0;
  stateSW1000 = digitalRead(SW1000);
}

void guess()
{
  
 
  
  if (n%9 == 0){
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
       
    tone(pinSpeaker, 300, 250);
    delay(250);
    tone(pinSpeaker, 400, 250);
    delay(250);
    tone(pinSpeaker, 500, 250);
    delay(500);
  }
  else {
  
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, HIGH);
    
    tone(pinSpeaker, 70, 250);
    delay(500);
    tone(pinSpeaker, 70, 250);
    delay(500);
    tone(pinSpeaker, 70, 250);
    delay(500);  
  }
}
