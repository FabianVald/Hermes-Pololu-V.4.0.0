void motor(int16_t vel_izquierdo, int16_t vel_derecho){
  motor_A(vel_izquierdo);
  motor_B(vel_derecho);
}

void motor_A(int16_t velocidad) {
  if (velocidad > 0) {
    // Da la dirección del Giro
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);

    //Da la velocidad
    analogWrite(PWMA, velocidad);
  }
  else{
    // Da la dirección del Giro
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);

    //Da la velocidad
    velocidad *= -1;
    analogWrite(PWMA, velocidad);
  }
}

void motor_B(int16_t velocidad) {
  if (velocidad > 0) {
    // Da la dirección del Giro
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);

    //Da la velocidad
    analogWrite(PWMB, velocidad);
  }
  else{
    // Da la dirección del Giro
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);

    //Da la velocidad
    velocidad *= -1;
    analogWrite(PWMB, velocidad);
  }
}