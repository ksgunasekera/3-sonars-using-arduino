#include <AFMotor.h>;
AF_DCMotor motorR(1, MOTOR12_1KHZ);
AF_DCMotor motorL(2,MOTOR12_1KHZ);
const int trigPinFront = 28;
const int echoPinFront = 26;

const int trigPinL = 34;
const int echoPinL = 36;

const int trigPinR = 18;
const int echoPinR = 19;

// defines variables
long durationLeft;
int distanceLeft;
long durationFront;
int distanceFront;
long durationRight;
int distanceRight;
void setup() {
pinMode(trigPinL, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPinL, INPUT); // Sets the echoPin as an Input
pinMode(trigPinR, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPinR, INPUT);
pinMode(trigPinFront, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPinFront, INPUT);

Serial.begin(9600); // Starts the serial communication

motorL.setSpeed(200);
motorR.setSpeed(200);
}
void loop() {
// Clears the trigPin
digitalWrite(trigPinL, LOW);
delayMicroseconds(2);
digitalWrite(trigPinL, HIGH);
delayMicroseconds(10);
digitalWrite(trigPinL, LOW);
durationLeft = pulseIn(echoPinL, HIGH);
distanceLeft= durationLeft*0.034/2;
Serial.print("DistanceLeft: ");
Serial.println(distanceLeft);

digitalWrite(trigPinR, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPinR, HIGH);
delayMicroseconds(10);
digitalWrite(trigPinR, LOW);
durationRight=pulseIn(echoPinR,HIGH);
distanceRight=durationRight*0.034/2;
Serial.print("DistanceRight: ");
Serial.println(distanceRight);


digitalWrite(trigPinFront, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPinFront, HIGH);
delayMicroseconds(10);



digitalWrite(trigPinFront, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds


durationFront=pulseIn(echoPinFront,HIGH);

// Calculating the distance


distanceFront=durationFront*0.034/2;

// Prints the distance on the Serial Monitor




Serial.print("DistanceFront: ");
Serial.println(distanceFront);
}
