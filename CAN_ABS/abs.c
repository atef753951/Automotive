// abs.c
#include <stdio.h>
#include <stdlib.h>  // Required for rand()
#include "can.h"

#define MAX_WHEEL_SPEED 150 // Maximum simulated wheel speed
#define SPEED_THRESHOLD 120  // Speed threshold for stopping

// Function to simulate ABS sending wheel speed data
uint16_t simulateABS() {
    CAN_Message absMessage;
    absMessage.id = 0x400;           // ABS CAN ID
    absMessage.dataLength = 2;

    // Simulate wheel speed (in km/h)
    uint16_t wheelSpeed = rand() % (MAX_WHEEL_SPEED + 1); // Random speed between 0 and MAX_WHEEL_SPEED
    absMessage.data[0] = (wheelSpeed >> 8) & 0xFF;  // High byte
    absMessage.data[1] = wheelSpeed & 0xFF;         // Low byte

    printf("ABS: Sending wheel speed: %d km/h\n", wheelSpeed); // Print the wheel speed
    sendCANMessage(absMessage);

    return wheelSpeed; // Return the current wheel speed
}

// Function to check the speed and send a stop command if necessary
void checkSpeedAndStop(uint16_t wheelSpeed) {
    if (wheelSpeed > SPEED_THRESHOLD) {
        CAN_Message stopMessage;
        stopMessage.id = 0x401; // Stop command CAN ID
        stopMessage.dataLength = 0; // No data needed for stop command
        sendCANMessage(stopMessage);
        printf("ABS: Sending stop command! Wheel speed exceeded %d km/h\n", SPEED_THRESHOLD);
    }
}
