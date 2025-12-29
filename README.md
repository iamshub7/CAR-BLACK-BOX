Car Black Box

📌 Description

The Car Black Box is an embedded systems project developed in Embedded C that simulates an automotive black box used to monitor and record critical vehicle parameters and events. The system captures real-time data such as speed, gear position, braking events, and system logs, storing them for later analysis.

This project was developed to demonstrate real-time embedded programming, peripheral interfacing, data logging, and automotive safety concepts using microcontroller-based firmware.

⚙️ Features

Real-time monitoring of vehicle parameters

Event logging for critical actions (brake, collision, overspeed, etc.)

Persistent storage of logs using external EEPROM

Time-stamped data logging using RTC

Menu-driven interface for viewing stored logs

UART-based communication for data display/debugging

🛠 Technologies Used

Language: Embedded C

Microcontroller: PIC Microcontroller

Modules Covered:

UART Communication

I2C Protocol

EEPROM Interfacing

RTC (DS1307)

ADC

IDE: MPLAB X IDE

Compiler: XC8 Compiler

📂 Project Structure
CAR_BLACK_BOX.X/
 ├── main.c          # Main application logic
 ├── adc.c / adc.h   # Speed sensing (ADC)
 ├── uart.c / uart.h # Serial communication
 ├── i2c.c / i2c.h   # I2C protocol
 ├── ds1307.c / .h   # RTC module
 ├── eeprom.c / .h   # Internal EEPROM
 ├── ext_eeprom.c/.h # External EEPROM logging
 ├── menu.c          # Menu handling
 ├── dashboard.c     # Display logic
 ├── build/          # Build files
 ├── dist/           # Compiled output
 └── README.md       # Project documentation

▶️ Usage

Open the project in MPLAB X IDE

Build the project using XC8 Compiler

Flash the firmware to the PIC microcontroller

Power the system and observe:

Real-time vehicle data

Event logging

Stored logs via menu/UART interface

📚 Learning Outcomes

Understanding automotive Black Box concepts

Real-time embedded system design

EEPROM-based data logging

RTC-based time stamping

Peripheral interfacing (ADC, UART, I2C)

Modular firmware development

🚧 Limitations

Simulated vehicle environment

Limited number of logged parameters

No wireless/cloud data transmission

No advanced fault diagnostics

👨‍💻 Author

Shubham Shinde

📜 License

Open-source and available for educational purposes
