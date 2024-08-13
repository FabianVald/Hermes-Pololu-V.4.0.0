#include "Pin.h"         //Define los pines.
#include <QTRSensors.h>  //Librería sensor QTR Pololu V.4.0.0
QTRSensors qtr;

const byte SensorCount = 6;   //Cantidad de Sensores
const uint8_t samples = 16;      //Cantidad de Samples
uint16_t sensorValues[SensorCount];  //Arreglo que guarda las lecturas del sensor
int position = 0;


void setup() {
  motorSetup();  //Configura los pines del Driver.

  // Configuración del Sensor
  qtr.setTypeAnalog();  // Setear el sensor como Análogo
  qtr.setSamplesPerSensor(samples);  //Sets the number of analog readings to average per analog sensor.

  qtr.setSensorPins((const byte[]){ 5, 4, 3, 2, 1, 0 }, SensorCount);  //Setea los Pines del QTR8A.
  /*qtr: Esto es una instancia de una clase o un objeto relacionado con el sensor QTR.

  setSensorPins: Es un método de la clase qtr que se utiliza para definir qué pines del
   microcontrolador están conectados a los sensores.
   
  (const byte[]){ 5, 4, 3, 2, 1, 0 }: Esto es un array constante de 
  tipo byte que contiene los números de los pines. 
  En este caso, los pines 5, 4, 3, 2, 1 y 0 están asignados a los sensores.*/

  qtr.setEmitterPin(EMITTER_PIN);  //Setea el Pin Emisor

  calibrar();  //Realiza la calibración

  //Inicializar la comunicación Serial
  Serial.begin(9600);
}

void loop() {
  //motor_A(120);  //Mueve el Motor A;
  //motor_B(120);  //Mueve el Motor B;
  //motor(180,180);  //Mueve ambas ruedas motor(vel_izq, vel_derecha) | vel_iqz, vel_der ~ [0,255]


  //uint16_t position = qtr.readLineBlack(sensorValues); //Para linea Negra
  // Valor in [i,j]; i = 0 , j = 1000*(N-1), N = Cantidad de Sensores.

  position = qtr.readLineWhite(sensorValues);  //Para linea Blanca
  // Valor in [i,j]; i = 0 , j = 1000*(N-1), N = Cantidad de Sensores.

  position = map(position, 0, 5000, -255, 255);

  for (uint8_t i = 0; i < SensorCount; i++) {
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  Serial.print("| Posición: ");
  Serial.print(position);
  Serial.println();
}
