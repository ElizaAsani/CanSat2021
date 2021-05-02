#include <Arduino.h>   // required before wiring_private.h
#include "wiring_private.h" // pinPeripheral() function
#include <HardwareSerial.h>

#define PIN_SERIAL_RX (24) //microcontroller's RX, XBee TX 20
#define PIN_SERIAL_TX (23) //microcontroller's TX, XBee RX 19
#define PAD_SERIAL_RX (SERCOM_RX_PAD_3)
#define PAD_SERIAL_TX (UART_TX_PAD_2)

//Serial1 already defined in arduino 

Uart Serial2(&sercom4, PIN_SERIAL_RX, PIN_SERIAL_TX, PAD_SERIAL_RX, PAD_SERIAL_TX);

void SERCOM4_Handler()
{
	Serial2.IrqHandler();
}

