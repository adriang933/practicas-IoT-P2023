//Mi medidor de “Distancia”
const int trigPin= 5;
const int echoPin= 18;
//define soundspeedin cm/uS
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701
long duration;
float distanceCm;
float distanceInch;
void setup() {
Serial.begin(115200); // Startstheserial communication
pinMode(trigPin, OUTPUT); // Sets thetrigPinas anOutput
pinMode(echoPin, INPUT); // Sets theechoPinas anInput
}
void loop() {
// ClearsthetrigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets thetrigPinonHIGH statefor10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// ReadstheechoPin, returnsthesoundwave traveltime in microseconds
duration= pulseIn(echoPin, HIGH);
// Calculatethedistance
distanceCm= duration* SOUND_SPEED/2;
// Converttoinches
distanceInch= distanceCm* CM_TO_INCH;
// Printsthedistancein theSerial Monitor
Serial.print("Distance(cm): ");
Serial.println(distanceCm);
Serial.print("Distance(inch): ");
Serial.println(distanceInch);
delay(1000);
}
