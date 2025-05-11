##🔥 Heater Control System using ESP32 and NTC Thermistor
This project simulates a basic heater control system using an ESP32 and an NTC temperature sensor. The system reads temperature via the ESP32's ADC and controls a simulated heater based on configurable thresholds.

##🧩 Features
Temperature sensing using an NTC analog thermistor

Accurate temperature calculation using the B-parameter equation

Heater control logic based on temperature thresholds

#Serial logging of:

Raw ADC readings

Voltage

Calculated resistance

Temperature in °C

Designed for simulation on Wokwi using ESP-IDF

##📦 Hardware (Simulated in Wokwi)
ESP32 DevKit V1

Wokwi NTC Temperature Sensor

GPIO Pin Used: GPIO34 (ADC1_CHANNEL_6)

##🔗 Wokwi Simulation
Click to open the project in Wokwi:
📎https://wokwi.com/projects/430656284952912897


##🛠️ Usage
Open the Wokwi link.

Adjust the NTC sensor temperature slider.

Monitor serial output for:

Real-time temperature

Heater status

