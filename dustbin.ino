#include <Servo.h>
Servo servo1;

// LiquidCrystal_I2C lcd(0x27, 16, 2); // Format -> (Address,Width,Height )
// int buzzer = 9;
int echoPin = 2; // attach pin D2 Arduino to Echo pin of Sensor module
int trigPin = 3; // attach pin D3 Arduino to Trig pin of Sensor module
int position  = 0;
long duration; // Declare variable to store echo time duration
			
int distance; // Declare variable to store the result (distance)
			

void setup()
{
	// lcd.init(); // initialize the lcd
	// lcd.backlight(); // Turn on the Backlight

	pinMode(trigPin,OUTPUT); // Sets the trigPin as an OUTPUT
			
	pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT

	// Serial Communication is starting with 9600 of baudrate speed
	Serial.begin(9600);

	// The text to be printed in serial monitor									
	Serial.println("Distance measurement using Arduino Uno");
	servo1.attach(8);

	delay(500);
}

void loop()
{
	digitalWrite(trigPin, LOW);
	delay(2000);
	digitalWrite(trigPin, HIGH);
	delay(1000);
	digitalWrite(trigPin, LOW);
	duration = pulseIn(echoPin, HIGH);
	distance = duration * 0.0344 / 2;
	Serial.print("Distance: ");
	Serial.print(distance);
	Serial.println(" cm");

	// lcd.clear(); // Clear the display buffer
	// lcd.setCursor(0, 0); // Set cursor for "Distance:" (Column, Row)
  if(distance <= 20){
    for (position = 0; position <= 120; position++)
  	{
  		servo1.write(position);
    	delay(10);
  	}
  }
}
  // if(distance >= 20 && distance <= 40){
  //   for (position = 0; position <= 90; position++)
  // 	{
  // 		servo1.write(position);
  //   	delay(100);
  // 	}
  // }
  // if(distance >=  40){
  //   for (position = 0; position <= 90; position++)
  // 	{
  // 		servo1.write(position);
  //   	delay(100);
  // 	}
  // }
	// lcd.print("Distance:"); // print "Distance:" at (0, 0)
	// lcd.setCursor(0,1); // Set cursor for output value (0, 1)
				
	// lcd.print(distance); // print Output in cm at (0, 1)
	// lcd.setCursor(4, 1); // move cursor to (4, 1)
	// lcd.print("cm"); // print "cm" at (4, 1)\
}
