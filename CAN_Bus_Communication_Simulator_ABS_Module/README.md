# CAN Bus Communication Simulator with ABS Module

## Project Specifications for CAN Bus Communication Simulator with ABS Module 

**TBA**: This project serves as an educational tool for understanding CAN communication and ABS concepts. Substantial enhancements and rigorous testing would be required for real-world vehicle applications.

## Project Overview
This project simulates a CAN Bus communication system designed for an Anti-lock Braking System (ABS) in vehicles. It demonstrates how different electronic control units (ECUs) can communicate over a CAN bus to monitor and control vehicle functions.

## Project Components
1. **CAN Bus Simulator**: Manages sending and receiving messages.
2. **ABS Module**: Simulates the ABS functionality by sending wheel speed data and determining when to send a stop command.
3. **Main Program**: Integrates the CAN Bus and ABS modules, controlling the simulation flow.

## Code Structure
1. **can.h**: Contains shared data structures and function declarations for CAN messages.
2. **can_bus.c**: Implements the CAN Bus functionality, including message validation and communication.
3. **abs.c**: Implements the ABS module logic, including dynamic speed simulation and stop command logic.
4. **main.c**: Ties all components together, initiating the simulation and handling interactions.

## Functional Specifications
1. **CAN Bus Functionality**:
   - Validate CAN messages to ensure proper format and data integrity.
   - Simulate sending and receiving CAN messages between the ABS module and the main program.

2. **ABS Module Functionality**:
   - Simulate dynamic wheel speed generation (0 to a defined maximum speed).
   - Send wheel speed data to the main program through the CAN Bus.
   - Receive a stop command when the wheel speed exceeds a threshold of 120 km/h.

3. **Main Program Functionality**:
   - Initialize the simulation environment and manage the interaction between components.
   - Continuously monitor wheel speed and send stop commands when needed.

## Technical Specifications
1. **Language**: C programming language.
2. **Compilation**: Uses GCC for compiling the code.
3. **Operating Environment**: Simulated, with no real hardware integration.
4. **Random Speed Generation**: Uses a random number generator to simulate wheel speeds.

## Limitations and Considerations
1. **Safety and Reliability**: The system needs rigorous testing and validation to meet automotive safety standards.
2. **Hardware Integration**: The project does not include real sensor or actuator integration, limiting its real-world application.
3. **Compliance**: The project must comply with automotive standards (e.g., ISO 26262) for safety-critical systems.
4. **Real-Time Processing**: The current simulation lacks real-time capabilities for actual vehicle environments.

## Compilation Instructions

### Windows
1. Download and install **MinGW** (Minimalist GNU for Windows) from [MinGW official website](http://www.mingw.org/).
2. Add the MinGW `bin` directory to your system's PATH (e.g., `C:\MinGW\bin`).
3. Open the **Command Prompt** or **Git Bash**.
4. Navigate to the project folder.
5. Run the following command to compile the project:
   ```bash
   gcc -o abs_simulator.exe src/can_bus.c src/abs.c src/main.c -I src/

## Output Examples