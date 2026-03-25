#include <Wire.h>
#include "RTClib.h"

RTC_DS3231 rtc;

String serialData = "";

void setup() {
  Serial.begin(9600);

  if (!rtc.begin()) {
    Serial.println("RTC no encontrado");
    while (1);
  }
}

void loop() {

  leerSerialRTC();

  DateTime now = rtc.now();

  Serial.print(now.day());
  Serial.print("/");
  Serial.print(now.month());
  Serial.print("/");
  Serial.print(now.year());
  Serial.print(" ");

  Serial.print(now.hour());
  Serial.print(":");
  Serial.print(now.minute());
  Serial.print(":");
  Serial.println(now.second());

  delay(1000);
}

void leerSerialRTC() {

  if (Serial.available()) {

    serialData = Serial.readStringUntil('\n');

    int dia, mes, anio, hora, minuto, segundo;

    int parsed = sscanf(serialData.c_str(), "%d,%d,%d,%d,%d,%d",
                        &dia, &mes, &anio, &hora, &minuto, &segundo);

    if (parsed == 6) {

      rtc.adjust(DateTime(anio, mes, dia, hora, minuto, segundo));

      Serial.println("RTC actualizado");

    } else {

      Serial.println("Formato incorrecto");
    }
  }
}
