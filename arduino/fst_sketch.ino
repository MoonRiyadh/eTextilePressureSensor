// H T M A Riyadh
// Interactive Systems, Summer 2020
// eTextile: Force sensitive textile sensor
// https://github.com/MoonRiyadh/eTextilePressureSensor.git
// This is the code for sensing the pressure from the textile sensor 


// Based on the adcTouch library --> https://github.com/martin2250/ADCTouch
// Based on zPatch --> https://github.com/zPatch/zPatch.github.io

int redPin = 12;
int greenPin = 9;
int bluePin = 7;
long randNumber;

//read and store resistance values from the sensor
int resistiveReading;

void setup()
{
  // open the arduino serial port
  Serial.begin(9600); 
  
  //make some dealy before establishing connection
  delay(50); 
  resistiveReading = readAnalogResistance(A0, A1, 3);
   
  // initialize the led's pin mode
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  delay(50);
}


void loop()
{
  resistiveReading = readAnalogResistance(A0, A1, 3);
  led_on(resistiveReading);
  // not to flood the serial port
  delay(5);

}

// read from analog signals and store resistance
int readAnalogResistance(int pinA, int pinB, int number) {
  //initialize sensor resistance for each pin  
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
  randNumber = cap_value;
    if (randNumber > 700)
    {
      digitalWrite(greenPin, HIGH);
      delay(500);
      digitalWrite(greenPin, LOW);
    }
    else if ((randNumber > 350) && (randNumber < 700))
    {
      digitalWrite(bluePin, HIGH);
      delay(500);
      digitalWrite(bluePin, LOW);
    }
    else
    {
      digitalWrite(redPin, HIGH);
      delay(500);
      digitalWrite(redPin, LOW);
    }
}
