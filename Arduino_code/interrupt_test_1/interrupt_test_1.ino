/*
 * A first sketch to test the interrupts
 */

volatile byte chA, chB = 0;

void setup() 
{
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2), chA_ISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(3), chB_ISR, CHANGE);

}

void loop() 
{
  Serial.print(chA);
  Serial.print("\t");
  Serial.println(chB);
}




void chA_ISR()
{
  chA = (PIND & B00000100)>>2;
}

void chB_ISR()
{
  chB = (PIND & B00001000)>>3;
}

