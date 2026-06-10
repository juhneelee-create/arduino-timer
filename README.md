# arduino-timer
 Arduino Embedded Reflex Timer & Security Controller
A lightweight embedded systems project built on the ATmega328P architecture (Elegoo/Arduino Uno platform). This project demonstrates real-time hardware control, state machine logic, and serial data communication between a host PC and a microcontroller.

 Features
Hardware-Agnostic Design: Configured to work seamlessly with on-board microchip architecture (LED_BUILTIN), removing the immediate need for external peripheral components.

State-Driven Password Authentication: Implements a security access loop that dynamically revokes system clearance if anomalous inputs are detected.

Asynchronous Reaction Timer: Utilizes the hardware's internal clock (millis()) and pseudo-random seed generation to track user reflex times down to the millisecond.

 Technical Challenges Overcome
Conquered Serial Buffer Bleed: Resolved local caching issues in the Arduino IDE serial monitor by implementing software state-checking to prevent instruction duplication.

Environment Variable Isolation: Fixed a critical compiler path failure (Compiled sketch not found) caused by cloud-sync directory locking (Microsoft OneDrive) by migrating the workspace to an isolated local directory (C:\Arduino).
