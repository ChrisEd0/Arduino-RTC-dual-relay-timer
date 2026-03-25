A cyclic timer module based on Arduino and DS3231 RTC, featuring dual opto-isolated relay outputs for time-based automation.

📌 Overview

This project implements a reliable and flexible cyclic timer system using an Arduino and a DS3231 real-time clock (RTC). It is designed for applications requiring precise periodic control with configurable timing parameters.

The system operates in cyclic intervals, activating outputs based on time windows and pre-trigger conditions.

✨ Features
Dual relay outputs (opto-isolated)
High-accuracy timing using DS3231 RTC
Configurable working hours (start / end time)
Cyclic operation with adjustable interval
Adjustable ON time for main load (Relay 1)
Pre-trigger output (Relay 2) before cycle end
Simple and efficient logic (no complex timers required)
Industrial-style behavior
🧠 Operating Modes

This project includes two different firmware modes:

1. RTC Setup Mode

This mode allows setting the date and time of the RTC via Serial communication.

Input format:

day,month,year,hour,minute,second

Example:

17,3,2026,19,25,00
The RTC updates automatically when valid data is received.
2. Operation Mode

This is the main working mode of the system.

Executes cyclic timing logic
Controls both relays automatically
Uses RTC as time reference
No Serial interaction required

⚠️ Important:
The RTC must be configured before uploading the operation firmware.

⚙️ Configuration Parameters

The system behavior can be easily adjusted in the code:

horaInicio → System start hour (24h format)
horaFin → System stop hour
tiempoEspera → Cycle interval (minutes)
tiempoCarga → Relay 1 ON time (minutes)
tiempoHumo → Relay 2 activation time before shutdown (seconds)
🔁 Operation Logic

Example configuration:

Cycle interval: 15 minutes
Relay 1 ON time: 10 minutes
Relay 2 pre-trigger: 10 seconds

Cycle behavior:

[ Relay 1 ON (10 min) ]
        ↓
[ Relay 2 ON (last 10s) ]
        ↓
[ OFF until next cycle ]
        ↓
Repeat...
🚀 Usage
Upload the RTC Setup Mode firmware
Open Serial Monitor
Send current date and time
Upload the Operation Mode firmware
System runs automatically
🔌 Hardware
Arduino Nano
DS3231 RTC module
Opto-isolated relay driver
Transistor (2N2222A)
Flyback diode (1N4148 or 1N4007)
⚡ Circuit Notes
Relays are driven using a transistor (2N2222A)
Optocoupler provides electrical isolation
Flyback diode protects against voltage spikes
Pull-down resistor ensures stable OFF state
📷 Project Images

(Add photos of your hardware here)

📊 Timing Diagram
Time →
|---- Relay 1 ON ----|-- OFF --|
                |-- Relay 2 --|
🧪 Applications
Smoke machines
Industrial cyclic processes
Automation systems
Timed control of loads
DIY control modules
⚠️ Important Notes
RTC keeps time using backup battery
No need to reset time unless battery is removed
Ensure correct time before operation
Verify relay ratings for your load (especially AC)
📦 Future Improvements
Serial configuration in operation mode
EEPROM parameter storage
LCD/OLED interface
Multiple independent channels
millis() based control (non-blocking)
📜 License

This project is licensed under the MIT License.

👨‍💻 Author

Developed by Cristian E. Guerrero

⭐ Contributions

Feel free to fork, improve, and contribute to this project!
