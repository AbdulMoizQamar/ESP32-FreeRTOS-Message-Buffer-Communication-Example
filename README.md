# ESP32-FreeRTOS-Message-Buffer-Communication-Example
This project demonstrates inter-task communication on an ESP32 using FreeRTOS.
📝 Description:
This project demonstrates inter-task communication on an ESP32 using FreeRTOS Message Buffers. It includes two tasks:
Sender Task: Periodically sends temperature messages to the buffer.
Receiver Task: Receives and prints the messages using xMessageBufferReceive.
It showcases how FreeRTOS message buffers can be used for safe and efficient data exchange between concurrent tasks in embedded systems using the Arduino framework.

✅ Features:
FreeRTOS-based multitasking
Message buffer communication mechanism
ESP32 compatible
Arduino-style development

📦 Requirements:
ESP32 board
Arduino IDE (or PlatformIO)
FreeRTOS (comes built-in with ESP32 Arduino core)
