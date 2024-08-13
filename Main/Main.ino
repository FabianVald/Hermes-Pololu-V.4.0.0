#include "Pin.h"  //Define los pines.
#include <QTRSensors.h>

QTRSensors qtr;

const uint8_t SensorCount = 6; //Cantidad de Sensores
uint16_t sensorValues[SensorCount];  //Arreglo que guarda las lecturas del sensor

void setup() {
  motorSetup();  //Configura los pines del Driver.
  
  // Configuración del Sensor
  qtr.setTypeAnalog();  // Setear el sensor como uno Reflectance Capacitive
  qtr.setSensorPins((const uint8_t[]){ 5, 4, 3, 2, 1, 0 }, SensorCount);
  qtr.setEmitterPin(EMITTER_PIN);

  //Calibración
  for (uint16_t i = 0; i < 200; i++) {
    qtr.calibrate();
  }

  //Inicializar la comunicación Serial
  Serial.begin(9600);
}

void loop() {
  //motor_A(120);  //Mueve el Motor A;
  //motor_B(120);  //Mueve el Motor B;
  //motor(180,180);  //Mueve ambas ruedas motor(vel_izq, vel_derecha) | vel_iqz, vel_der ~ [0,255]
  

  uint16_t position = qtr.readLineBlack(sensorValues);
  position = map(position, 0, 5000, -255, 255); 

  for (uint8_t i = 0; i < SensorCount; i++) {
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  Serial.println(position);

  delay(250);
  Serial.println();
} 
