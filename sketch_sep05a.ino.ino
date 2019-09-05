const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
}

void loop() {
   long duration, cm;
   pinMode(4, INPUT);
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   cm =microsecondsToCentimeters(duration);
   Serial.print(cm);
   Serial.print("cm\n");
   Serial.println();
   delay(1000);
    if (digitalRead(4) == 1)
  {
   Serial.print("\nMotion Detection\n"); 
  }
  else
  {
    Serial.print("\nNo Motion Detected\n");
    }
  }

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29.15 / 2; //Sound travels at 343 meters per second, which means it needs 29.15 microseconds per centimeter. 
}
