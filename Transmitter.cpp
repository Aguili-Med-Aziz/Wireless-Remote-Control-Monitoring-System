#include <VirtualWire.h>

const int buttonPin = 2;  // Pin for button press (input)
const int rfTransmitterPin = 12; // Pin for RF Transmitter

void setup() {
  pinMode(buttonPin, INPUT);
  vw_set_tx_pin(rfTransmitterPin);
  vw_setup(2000);  // Set the speed of RF transmission (2000bps)
}

void loop() {
  if (digitalRead(buttonPin) == HIGH) {
    const char *msg = "Turn ON";  // Command message to send (Turn ON command)
    vw_send((uint8_t *)msg, strlen(msg));
    vw_wait_tx();  // Wait until transmission is complete
    delay(500);  // Debounce delay
  }
}
