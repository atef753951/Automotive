#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "can.h"

// External functions
extern uint16_t simulateABS(); // From abs.c
extern void checkSpeedAndStop(uint16_t wheelSpeed); // From abs.c

int main() {
    srand(time(NULL)); // Seed random number generator

    // Simulate ABS module and check speed multiple times
    for (int i = 0; i < 5; i++) { // Simulate 5 cycles
        uint16_t wheelSpeed = simulateABS(); // Get the wheel speed from the ABS simulation
        checkSpeedAndStop(wheelSpeed); // Check speed and send stop command if necessary
    }

    return 0;
}
