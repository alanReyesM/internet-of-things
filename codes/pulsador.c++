#define VERDE 13
#define AMARILLO 12
#define ROJO 11
#define BOTON 2
//Alan Sebastian Reyes Martínez
//profe me toco cambiar el delay por el millis
int modo = -1;
int estadoBotonActual;
int estadoBotonAnterior = HIGH;
int leds[] = {VERDE, AMARILLO, ROJO};
int direccion = 1; // 1 significa avanzar, -1 significa retroceder

// esto reemplaza los delays
unsigned long tiempoAnterior = 0;
const long intervalo = 300; // El tiempo de parpadeo
int estadoLed = LOW;
int pasoSemaforo = 0; // Para saber qué luz toca en el modo semáforo

void setup() {
  pinMode(VERDE, OUTPUT);
  pinMode(AMARILLO, OUTPUT);
  pinMode(ROJO, OUTPUT);
  pinMode(BOTON, INPUT_PULLUP);
}

void loop() {
  estadoBotonActual = digitalRead(BOTON);

  if (estadoBotonAnterior == HIGH && estadoBotonActual == LOW) {
    modo++;
    if (modo > 3) modo = -1;  // Ajustado a los 5 modos (-1, 0, 1, 2, 3)
    delay(50); // Un anti-rebote
    
    // Al cambiar de modo, reiniciamos todo para entrar limpios al nuevo modo
    apagarTodo();
    tiempoAnterior = millis();
    estadoLed = LOW;
    pasoSemaforo = 0;
  }
  
  estadoBotonAnterior = estadoBotonActual;

  // modoss con MILLIS()
  unsigned long tiempoActual = millis(); // Miramos el reloj

  switch (modo) {

    case 0: // 1° Solo verde
      digitalWrite(VERDE, HIGH);
      break;

    case 1: // 2° Todas parpadeando
      if (tiempoActual - tiempoAnterior >= intervalo) {
        tiempoAnterior = tiempoActual; // Reiniciamos el cronómetro
        
        estadoLed = (estadoLed == LOW) ? HIGH : LOW; 
        
        digitalWrite(VERDE, estadoLed);
        digitalWrite(AMARILLO, estadoLed);
        digitalWrite(ROJO, estadoLed);
      }
      break;

    case 2: 
      if (tiempoActual - tiempoAnterior >= intervalo) {
        tiempoAnterior = tiempoActual;
        estadoLed = (estadoLed == LOW) ? HIGH : LOW;
        digitalWrite(AMARILLO, estadoLed);
      }
      break;

    case 3: //esta al final de el code el como se apaga todo profe
      apagarTodo();
      break;

    case -1:
      if (tiempoActual - tiempoAnterior >= intervalo) {
        tiempoAnterior = tiempoActual; 
        
        // Encendemos el LED que toca
        if (estadoLed == LOW) {
          estadoLed = HIGH;
          digitalWrite(leds[pasoSemaforo], HIGH);
        } 
        // Lo apagamos y calculamos el siguiente paso
        else {
          estadoLed = LOW;
          digitalWrite(leds[pasoSemaforo], LOW);
          
          // Sumamos la dirección (puede ser +1 o -1)
          pasoSemaforo = pasoSemaforo + direccion; 
       
          if (pasoSemaforo >= 2) {
            pasoSemaforo = 2; //para no salir límite xd
            direccion = -1;   //regresar hacia el verde
          } else if (pasoSemaforo <= 0) {
            pasoSemaforo = 0; //casi me da una embolia haciendo esto profe
            direccion = 1;    //de regreso(hacia el rojo)
          }
        }
      }
      break;
  }
}
void apagarTodo() {
  digitalWrite(VERDE, LOW);
  digitalWrite(AMARILLO, LOW);
  digitalWrite(ROJO, LOW);
}