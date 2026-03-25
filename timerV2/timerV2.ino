#include <Wire.h>
#include "RTClib.h"

RTC_DS3231 rtc;

const int rele1 = 4;
const int rele2 = 5;

//////////////////////////////////////////configuracion tiempo//////////////////////////////////////////////
int horaInicio = 10;
int horaFin    = 22;

int tiempoCarga = 6;   // minutos
int tiempoHumo  = 10;   // segundos
int tiempoEspera = 15;  // minutos entre ciclos
///////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup() {
  pinMode(rele1, OUTPUT);
  pinMode(rele2, OUTPUT);

  digitalWrite(rele1, LOW);
  digitalWrite(rele2, LOW);

  Serial.begin(9600);
  rtc.begin();
}

void loop() {

  DateTime now = rtc.now();

  int hora = now.hour();
  int minuto = now.minute();
  int segundo = now.second();

  bool sistemaActivo = (hora >= horaInicio && hora < horaFin);

  if (sistemaActivo) {

    int minutoCiclo = minuto % tiempoEspera;

    // -------- RELE 1 (carga) --------
    if (minutoCiclo < tiempoCarga) {
      digitalWrite(rele1, HIGH);
    } else {
      digitalWrite(rele1, LOW);
    }

    // -------- RELE 2 (humo) --------
    if (minutoCiclo == (tiempoCarga - 1) && segundo >= (60 - tiempoHumo)) {
      digitalWrite(rele2, HIGH);
    } else {
      digitalWrite(rele2, LOW);
    }

  } 
  else {
    digitalWrite(rele1, LOW);
    digitalWrite(rele2, LOW);
  }

  // Debug opcional
  /*Serial.print(hora);
  Serial.print(":");
  Serial.print(minuto);
  Serial.print(":");
  Serial.print(segundo);
  Serial.print("  ciclo: ");
  Serial.println(minuto % tiempoEspera);

  delay(200);*/
}
