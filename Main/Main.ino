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
  /*qtr: Esto es una instancia de una clase o un objeto relacionado con el sensor QTR.
  setSensorPins: Es un método de la clase qtr que se utiliza para definir qué pines del microcontrolador están conectados a los sensores.
  (const uint8_t[]){ 5, 4, 3, 2, 1, 0 }: Esto es un array constante de tipo uint8_t (un entero sin signo de 8 bits) que contiene los números de los pines. En este caso, los pines 5, 4, 3, 2, 1 y 0 están asignados a los sensores.*/


  qtr.setEmitterPin(EMITTER_PIN);

  //Calibración
  for (uint16_t i = 0; i < 100; i++) {
    qtr.calibrate();
  }

  //Inicializar la comunicación Serial
  Serial.begin(9600);
}

void loop() {
  //motor_A(120);  //Mueve el Motor A;
  //motor_B(120);  //Mueve el Motor B;
  //motor(180,180);  //Mueve ambas ruedas motor(vel_izq, vel_derecha) | vel_iqz, vel_der ~ [0,255]
  

  uint16_t position = qtr.readLineBlack(sensorValues); // Valor in [i,j]; i = 0 , j = 1000*(N-1), N = Cantidad de Sensores. Type uint16_t  
  position = map(position, 0, 5000, -255, 255); 

  for (uint8_t i = 0; i < SensorCount; i++) {
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  Serial.print("| ");
  Serial.println(position);


  delay(250);
  Serial.println();
} 
