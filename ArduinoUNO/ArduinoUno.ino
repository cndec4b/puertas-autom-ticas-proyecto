#include <Servo.h>
#include "Config.h"
#include "Actuadores.h"

Servo miServo;

void setup() {
  Serial.begin(9600);
  inicializarActuadores(miServo);
  Serial.println("Arduino Uno listo. Esperando comandos...");
}

void loop() {
  if (Serial.available() > 0) {
    String comando = Serial.readStringUntil('\n');
    comando.trim();

    if (comando == "ACCESO_PERMITIDO") {
      ejecutarAccesoPermitido(miServo);
    } 
    else if (comando == "ACCESO_DENEGADO") {
      ejecutarAccesoDenegado();
    }
  }
}