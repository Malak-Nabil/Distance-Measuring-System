

# Distance Measuring System
This project implements a distance measurement system using an ultrasonic sensor (HC-SR04) and an ATmega32 microcontroller. The measured distance is displayed on an LCD.

## Introduction
This project uses an ATmega32 microcontroller to measure the distance to an object using the HC-SR04 ultrasonic sensor. The distance is calculated based on the time it takes for an ultrasonic pulse to travel to the object and back. The result is displayed on a 16x2 LCD screen.

## Functionalities
• Distance Measurement: The HC-SR04 sensor sends an ultrasonic pulse and measures the time taken for the echo to return.

• Distance Calculation: The ATmega32 microcontroller calculates the distance based on the time measured.

• LCD Display: The calculated distance is displayed on a 16x2 LCD.


## Hardware Requirements

• ATmega32 Microcontroller

• HC-SR04 Ultrasonic Sensor

• 16x2 LCD Display


• Breadboard or PCB for assembly

• Connecting wires

• Power supply (5V for ATmega32 and sensor)

## Schematic
![Schematic](https://github.com/Malak-Nabil/Distance-Measuring-System/assets/112269807/4bd3f19c-6be5-413b-8794-d5a27701520f)

## Setting Up the Simulation

• Open Proteus: Launch the Proteus design software.

• Load Project: Open the project(4)_proteus.pdsprj file from the repository.

• Run Simulation: Start the simulation to see the Ultrasonic Distance Measurement System in action.

• Interact: Use the virtual ultrasonic sensor to simulate different distances and observe the LCD display updates.
