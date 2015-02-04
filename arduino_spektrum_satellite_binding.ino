/**
 * Arduino sketch for binding with Spektrum compatible Satellite Receivers
 *
 * Connection: Connect black wire to GND, orange wire (VDD) to PIN 10 and grey wire (TX) to pin 6
 */


const uint8_t TxPin = 6;
const uint8_t PowerPin = 10;
/**
 * Change the number of pulses according to your setup:
 * 2 low pulses: DSM2 1024/22ms
 * 4 low pulses: DSM2 2048/11ms
 * 6 low pulses: DSMX 22ms
 * 8 low pulses: DSMX 11ms
 */
const uint8_t numPulses = 2;
const uint8_t pulseLength = 116;
uint32_t time;

void setup() {
  pinMode(PowerPin, OUTPUT);
}

void loop() {
  digitalWrite(PowerPin, HIGH); // power up receiver
  pinMode(TxPin, INPUT);
  digitalWrite(TxPin, HIGH);
  if (digitalRead(TxPin) == LOW) {
    time = millis();
    while(time+1000 > millis()) { // wait at most 1 second for TxPin to become high
      if(digitalRead(TxPin) == HIGH) {
        delay(90); // give the receiver some time to start up
        SendBindingPulses(); // bring the receiver into binding mode by sending a sequence of low pulses
        digitalWrite(TxPin, LOW);
        while(1); // assume everything worked fine and stay in endless loop
      }
    }
  }
  digitalWrite(PowerPin, LOW); // shut down receiver
}

void SendBindingPulses(void) {
  pinMode(TxPin, OUTPUT);
  for(uint8_t i; i < numPulses; i++) {
    digitalWrite(TxPin, LOW);
    delayMicroseconds(pulseLength);
    digitalWrite(TxPin, HIGH);
    delayMicroseconds(pulseLength);
  }
}
