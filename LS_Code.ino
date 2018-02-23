#define RED    2
#define BUTTON 8
#define X A1
#define Y A2
#define Z A2

int result1;
int result2;
int x;
int y;
int z;
boolean lightOn = false;
boolean lastButton = LOW;
boolean currentButton = LOW;

boolean debounce(boolean last) {
  boolean current = digitalRead(BUTTON);
  if(last != current) {
    delay(5);
    current = digitalRead(BUTTON);    
  }
  return current;
}

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(RED, OUTPUT);
  digitalWrite(RED, LOW);
  pinMode(BUTTON, INPUT);
  pinMode(X,INPUT);
  pinMode(Y,INPUT);
  pinMode(Z,INPUT);

  Serial.begin(9600);
  result1 = analogRead(X) + analogRead(Y) + analogRead(Z);
}

// the loop function runs over and over again forever
void loop() {
  currentButton = debounce(lastButton);
  
  if (lastButton == LOW && currentButton == HIGH) {
    lightOn = !lightOn;
    }
    lastButton = currentButton;
    digitalWrite(RED, lightOn);
}
