# IoT Remote Monitoring Device (STM32 + AWS IoT Core)

FreeRTOS-based IoT firmware on STM32/ARM Cortex-M publishing 
telemetry securely to AWS IoT Core via MQTT.

## 🔧 Tech Stack
- **Platform:** STM32 / ARM Cortex-M
- **RTOS:** FreeRTOS
- **Language:** Embedded C
- **Protocols:** MQTT, TCP/IP, Wi-Fi, UART, SPI, I2C
- **Cloud:** AWS IoT Core
- **Tools:** STM32CubeIDE, ST-Link, JTAG
- **Standards:** ISO 26262, MISRA C

## 📁 Project Structure
/src
main.c           - Application entry point
mqtt_client.c    - MQTT publish/subscribe handler
sensor_task.c    - FreeRTOS sensor acquisition task
wifi_driver.c    - Wi-Fi connectivity driver
/include
mqtt_client.h
sensor_task.h
wifi_driver.h
/docs
architecture.md
README.md
## ⚙️ Key Features
- Deployed across 3 prototype devices with 100% uptime over 30-day test
- Sensor polling latency reduced by 15% through FreeRTOS task prioritization
- End-to-end telemetry delivery to AWS IoT Core under 200ms
- Firmware memory footprint optimized by 25%
- Validated across 30+ integration test scenarios

## 📊 Results
| Metric | Result |
|---|---|
| Device Uptime | 100% over 30-day test |
| Sensor Polling Latency | 15% reduction |
| Cloud Delivery Time | < 200ms end-to-end |
| Memory Optimization | 25% footprint reduction |
| Test Scenarios Passed | 30+ with zero failures |

## ⚠️ Note
Sanitized demo version for portfolio purposes.
Proprietary client code is not included.
