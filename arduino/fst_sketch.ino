// H T M A Riyadh
// Interactive Systems, Summer 2020
// eTextile: Force sensetive textile ssensor
// https://github.com/MoonRiyadh/eTextilePressureSensor.git
// This is the code for sensing the pressure from the textile sensor 


// Based on the adcTouch library --> https://github.com/martin2250/ADCTouch
// Based on zPatch --> https://github.com/zPatch/zPatch.github.io

int redPin = 12;
int greenPin = 9;
int bluePin = 7;
long randNumber;

//value for storing resistive readings
int resValues;

void setup()
{
  Serial.begin(9600); // open the arduino serial port
  delay(50); //wait a bit before establishing baseline
  resValues = dualAnalogRead(A0, A1, 3); //this line should not be needed, but might stabalize readings
   
  // initialize the led's pin mode
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  delay(50);
}


void loop()
{
  resValues = dualAnalogRead(A0, A1, 3); //sample resistance
  led_on(resValues);

//print to serial port
//  Serial.print(resValues); 
//  Serial.println(); 
  delay(5); // (so as not to completely flood the serial port)

}

// read from analog signals and store resistance
int dualAnalogRead(int pinA, int pinB, int number) {
  int resistanceA = 0;
  int resistanceB = 0;
  int resistance = 0;

  for (int i = 0; i < number; i++) {
    pinMode(pinA, OUTPUT);
    digitalWrite(pinA, LOW);
    pinMode(pinB, INPUT_PULLUP);
    resistanceB = analogRead(pinB);

    pinMode(pinB, OUTPUT);
    digitalWrite(pinB, LOW);
    pinMode(pinA, INPUT_PULLUP);
    resistanceA = analogRead(pinA);

    resistance = resistance + (resistanceA + resistanceB) / 2;

  }
  return resistance / number;
}

void led_on(int cap_value)
{
  Serial.println(cap_value);
  //----------
  randNumber = cap_value;
    if (randNumber > 700)
    {
      digitalWrite(greenPin, HIGH);
      delay(500);
      digitalWrite(greenPin, LOW);
//      delay(500);
    }
    else if ((randNumber > 350) && (randNumber < 700))
    {
      digitalWrite(bluePin, HIGH);
      delay(500);
      digitalWrite(bluePin, LOW);
//      delay(500);
    }
    else
    {
      digitalWrite(redPin, HIGH);
      delay(500);
      digitalWrite(redPin, LOW);
//      delay(500);
    }
}
