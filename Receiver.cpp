#include <VirtualWire.h>

const int rfReceiverPin = 11;  // Pin for RF Receiver
const int ledPin = 13;         // Pin for LED control

void setup() {
  pinMode(ledPin, OUTPUT);
  vw_set_rx_pin(rfReceiverPin);
  vw_setup(2000);  // Set the speed of RF communication (2000bps)
  vw_rx_start();   // Start the receiver
}

void loop() {
  uint8_t receivedMessage[10];  // Array to store incoming message
  uint8_t messageLength = sizeof(receivedMessage);

  if (vw_get_message(receivedMessage, &messageLength)) {
    String msg = String((char*)receivedMessage);
    if (msg == "Turn ON") {
      digitalWrite(ledPin, HIGH);  // Turn on LED if "Turn ON" command is received
    }
    else if (msg == "Turn OFF") {
      digitalWrite(ledPin, LOW);  // Turn off LED if "Turn OFF" command is received
    }
    // Optionally: Add more commands like "Status Request" and send sensor data back
  }
}
