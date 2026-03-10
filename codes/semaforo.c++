#define LED1 13
#define LED2 12
#define LED3 11  
//Alan Sebastian Reyes Martinez 
int leds[] = {LED1, LED2, LED3, LED2};

void setup() {
  for(int i = 0; i < 3; i++){
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  for(int i = 0; i < 4; i++){ 
    digitalWrite(leds[i], HIGH);
    delay(1000);
    digitalWrite(leds[i], LOW);
    delay(1000);
  }
}
