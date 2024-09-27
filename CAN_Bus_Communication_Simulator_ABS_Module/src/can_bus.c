// can_bus.c
#include <stdio.h>
#include "can.h"

// Function to check for errors in a CAN Message
int validateCANMessage(CAN_Message msg) {
    if (msg.id > 0x7FF || msg.dataLength > 8) {
        printf("Error: Invalid CAN message.\n");
        return 1;
    }
    return 0;
}

// Function to simulate sending a CAN Message
void sendCANMessage(CAN_Message msg) {
    if (validateCANMessage(msg)) {
        printf("Message not sent due to errors.\n");
        return;
    }
    printf("Sending CAN message with ID: 0x%X\n", msg.id);
}

// Function to simulate receiving a CAN Message
void receiveCANMessage(CAN_Message msg) {
    if (validateCANMessage(msg)) {
        printf("Message not processed due to errors.\n");
        return;
    }
    printf("Receiving CAN message with ID: 0x%X\n", msg.id);

    // Process messages
    if (msg.id == ABS_MESSAGE_ID) {
        uint16_t wheelSpeed = (msg.data[0] << 8) | msg.data[1];
        printf("ABS: Wheel speed: %d km/h\n", wheelSpeed);
    } else if (msg.id == STOP_COMMAND_ID) {
        printf("ABS: Stopping the wheels!\n");
        // Additional logic to stop the wheels could be added here
    }
}
