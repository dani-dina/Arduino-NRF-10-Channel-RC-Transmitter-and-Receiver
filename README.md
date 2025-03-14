# NRF24L01 10-Channel Transmitter and Receiver

This project is a wireless transmitter and receiver system using **nRF24L01**, **Arduino**, and **Servo motors**. It supports **10 channels** and can be used for **RC planes, drones, and robotics applications**.

## Features
- **10-Channel Communication** via nRF24L01
- **Analog & Digital Input Handling**
- **PWM Output for Servos**
- **Failsafe Mechanism** when the signal is lost
- **Lightweight & Efficient Code**

## Hardware Requirements
- **Arduino UNO/Nano** (or compatible)
- **nRF24L01 Module** (with or without PA/LNA)
- **Joysticks/Potentiometers** (for analog input)
- **Push Buttons/Switches** (for digital channels)
- **Servo Motors** (for testing output)
- **Power Supply** (based on components used)

## Wiring Diagram
### Transmitter
| Component    | Arduino Pin |
|-------------|------------|
| nRF24L01 CE | D9         |
| nRF24L01 CSN| D10        |
| MOSI        | D11        |
| MISO        | D12        |
| SCK         | D13        |
| Joystick X1 | A0         |
| Joystick Y1 | A1         |
| Joystick X2 | A2         |
| Joystick Y2 | A3         |
| Switch 1    | D2         |
| Switch 2    | D3         |
| Extra Analog| A4, A5, A6, A7 |

### Receiver
| Component    | Arduino Pin |
|-------------|------------|
| nRF24L01 CE | D9         |
| nRF24L01 CSN| D10        |
| MOSI        | D11        |
| MISO        | D12        |
| SCK         | D13        |
| Servo 1     | D2         |
| Servo 2     | D3         |
| Servo 3     | D4         |
| Servo 4     | D5         |
| Servo 5     | D6         |
| Servo 6     | D7         |
| Servo 7     | D8         |
| Servo 8     | D9         |
| Servo 9     | D10        |
| Servo 10    | D11        |

## Installation
1. Clone this repository:
   ```sh
   git clone https://github.com/dani-dina/Arduino-NRF-10-Channel-RC-Transmitter-and-Receiver.git
   ```
2. Open the **Arduino IDE**.
3. Install the required libraries:
   - **RF24** (for nRF24L01 communication)
   - **Servo** (for controlling servos)
4. Upload the **Transmitter Code** to one Arduino.
5. Upload the **Receiver Code** to another Arduino.
6. Connect the hardware and power it up!

## Usage
- Move the **joysticks** to control servos.
- Toggle **switches** to activate digital channels.
- The receiver automatically resets if the signal is lost for 1 second.

## Troubleshooting
- **No Signal?** Check wiring and power supply for the **nRF24L01**.
- **Delay in Response?** Reduce `delay(50);` in the **transmitter code**.
- **Servo Not Moving?** Ensure correct pin assignments in the receiver.

## License
This project is open-source under the **MIT License**.

## Author
Developed by **Daniel Abera** 🚀

