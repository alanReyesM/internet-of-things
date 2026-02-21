const int pinesLeds[] = {13, 12, 11, 10, 9};
//Alan Sebastian Reyes Martinez 
void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(pinesLeds[i], OUTPUT);
  }
}

void loop() {
  for (int numero = 0; numero <= 20; numero++) {
    
    for (int ledActual = 0; ledActual < 5; ledActual++) {
     //herramienta nativa de Arduino para leer los bits
      int estadoBit = bitRead(numero, ledActual);
      digitalWrite(pinesLeds[ledActual], estadoBit);
    }

    delay(1300);
  }
}