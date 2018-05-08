int LED = 9;
int LDR = A0;
bool ON = false; // LED status

void setup() 
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(LDR, INPUT);
}

void loop() {
  // Read data from LDR sensor
  int LDRValue = analogRead(LDR);
  
  // print ldrvalue for debugging
  Serial.print("sensor = ");
  Serial.print(LDRValue);

  // if ldr value is less then
  // 700 then it will be dark outside 
  // and Lights should be on.
  if (LDRValue <=700) 
  {
    // checked if light already on?
    if (!ON)
    {
      // LED fade in
      for(int fadeValue=0 ; fadeValue<255 ; fadeValue += 5)
      {
        analogWrite(LED,fadeValue);
        delay(30);
      }
      digitalWrite(LED, HIGH);
    }
    // set LED status on
    ON = true;
    Serial.println("It's Dark Outside; Lights status: ON");
  }
  else 
  {
    // checked if light already off?
    if (ON)
    {
      // LED fade out
      for(int fadeValue=255 ; fadeValue>0 ; fadeValue -= 5)
      {
        analogWrite(LED,fadeValue);
        delay(30);
      }
      digitalWrite(LED, LOW);
    }
    // set LED status off
    ON = false;
    Serial.println("It's Bright Outside; Lights status: OFF");
  }
}
