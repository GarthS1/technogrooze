void setup() {
  // initialize serial communication at 9600 bits per second
  Serial.begin(9600);
  // sets the digital pin 4 as output
  pinMode(4, OUTPUT);    
}

void loop() {
  // read the inputs on analog pins and convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V)
  float sourceVoltage = analogRead(A0) * (5.0 / 1023.0);
  float circuitVoltage = analogRead(A1) * (5.0 / 1023.0);
  float loadVoltage = analogRead(A2) * (5.0 / 1023.0);
  float batteryChargeVoltage = analogRead(A3) * (5.0 / 1023.0);

  // if source voltage doesn't supply enough power switch to battery
  if (sourceVoltage < 2){
    digitalWrite(4, HIGH); 
  }
  // use source to supply power
  else{
    digitalWrite(4, LOW);
  }

  // display graph
  Serial.print("Source_Voltage:"); Serial.print(sourceVoltage); Serial.print("V,");
  Serial.print("Circuit_Voltage:"); Serial.print(circuitVoltage); Serial.print("V,");
  Serial.print("Load_Voltage:"); Serial.print(loadVoltage); Serial.print("V,");
  Serial.print("Battery_Charge_Voltage:"); Serial.print(batteryChargeVoltage); Serial.print("V,");
  Serial.print("Power:"); Serial.print(((circuitVoltage-loadVoltage)*loadVoltage)/330.0*1000.0); Serial.println("mW");

  // wait for a second
  delay(1000);            
}




