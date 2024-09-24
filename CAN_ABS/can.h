// can.h
#ifndef CAN_H
#define CAN_H

#include <stdint.h>

// Define a structure for CAN Message
typedef struct {
    uint16_t id;          // CAN Identifier (11-bit)
    uint8_t data[8];      // CAN Data (up to 8 bytes)
    uint8_t dataLength;   // Length of data (0-8)
    int errorStatus;      // Error status (0 = no error, 1 = error)
} CAN_Message;

// Function declarations
int validateCANMessage(CAN_Message msg);
void sendCANMessage(CAN_Message msg);
void receiveCANMessage(CAN_Message msg);

// Define message IDs
#define ABS_MESSAGE_ID 0x400
#define STOP_COMMAND_ID 0x401

#endif
