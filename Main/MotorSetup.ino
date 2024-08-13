void motorSetup(){
  //Config Pin Mode in Output
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  //Motor A
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  //Motor B
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
}