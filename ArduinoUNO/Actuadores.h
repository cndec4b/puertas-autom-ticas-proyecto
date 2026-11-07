#ifndef ACTUADORES_H
#define ACTUADORES_H

#include <Arduino.h>
#include <Servo.h>
#include "Config.h"

void inicializarActuadores(Servo &servo);
void ejecutarAccesoPermitido(Servo &servo);
void ejecutarAccesoDenegado();

#endif