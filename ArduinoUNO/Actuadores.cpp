#include "Actuadores.h"

void inicializarActuadores(Servo &servo) {
  servo.attach(PIN_SERVO);
  servo.write(0);   // Puerta cerrada inicialmente

  pinMode(PIN_LED_VERDE, OUTPUT);
  pinMode(PIN_LED_ROJO, OUTPUT);
  pinMode(PIN_BUZZER, OUTPUT);

  digitalWrite(PIN_LED_ROJO, HIGH);
  digitalWrite(PIN_LED_VERDE, LOW);
}

void ejecutarAccesoPermitido(Servo &servo) {
  digitalWrite(PIN_LED_ROJO, LOW);
  digitalWrite(PIN_LED_VERDE, HIGH);
  
  tone(PIN_BUZZER, 2000, 100);
  delay(150);
  tone(PIN_BUZZER, 2500, 100);

  servo.write(90); // Abre la puerta
  delay(4000);

  servo.write(0);  // Cierra la puerta
  digitalWrite(PIN_LED_VERDE, LOW);
  digitalWrite(PIN_LED_ROJO, HIGH);
}

void ejecutarAccesoDenegado() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(PIN_LED_ROJO, HIGH);
    tone(PIN_BUZZER, 500, 150);
    delay(200);
    digitalWrite(PIN_LED_ROJO, LOW);
    delay(200);
  }
  digitalWrite(PIN_LED_ROJO, HIGH);
}