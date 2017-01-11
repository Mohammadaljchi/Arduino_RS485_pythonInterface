/**
 * Read temperature sensor DHT11 via rs485:
 * the purpouse of this code is to read temperature from dht11 via arduino and to
 * display the value for the temperature via rs485 on QModbus or 
 * python.
 * The circuit:
 * dht11 VCC to 5V, signal pin to pin7, graund
 * max485 RO to RX0, RE&DE to PIN2, DO to TX0 ,
 * A B to A B(on the usb port), VCC to 5V,ground.
 */
/**
 * The Modbus communication requires the ModbusRtu-library  
 * (https://github.com/smarmengol/Modbus-Master-Slave-for-Arduino).
 */
#include <ModbusRtu.h>
#include <dht.h>

// Assign the Arduino pin that must be connected to RE-DE RS485 transceiver
#define TXEN 2
// Assign the sensor pin that must be connected to signal pin
#define DHT11_PIN 7

dht DHT;
unsigned long previousMillis = 0;
const long Delay = 1000;
int State = LOW; // when state low the circuit it is not working

// data array for modbus network sharing
uint16_t au16data[16] = {
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

/**
 * Modbus object declaration
 * u8id : node id = 0 for master, = 1..247 for slave
 * u8serno : serial port (use 0 for Serial)
 * u8txenpin : 0 for RS-232 and USB-FTDI
 * or any pin number > 1 for RS-485
 */
Modbus slave(2,0,TXEN); // this is slave 2 and RS-485

void setup() {
  slave.begin( 19200 ); // baud-rate at 19200
}

void loop() {
  /**
   * The if condition makes a delay of 1000 millisecond for the circuit 
   * I used this way because if we but a delay() command in the code 
   * the circuit will not work
   */
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= Delay){
    previousMillis = currentMillis;
    if (State == LOW) {
      State = HIGH;
      int chk = DHT.read11(DHT11_PIN);
      au16data[1] = DHT.temperature;
      au16data[2] = DHT.humidity;
    } 
    else {
      State = LOW;
    }
  }
  
  // Put data on the bus
  slave.poll( au16data, 16 );
}
