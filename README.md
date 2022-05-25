# FreeRTOS on ESP32 (LOLIN32)

## Project Initialization

Create a new project using PlatformIO with the following settings:

- Board: WeMos LOLIN32
- Framework: ESP-IDF (Espressif IoT Development Framework)

## Notes

### Use only core 0 for demo purposes

Set `CONFIG_FREERTOS_UNICORE=y` in `sdkconfig.lolin32` to use only core 0 for demo purposes.

### Prevent `Task watchdog got triggered` warning

Add a small delay (10ms) to infinite loops to prevent `Task watchdog got triggered` warning.

- [Task watchdog got triggered - it is fixed with a vTaskDelay of 10ms but is this a bug? (IDFGH-5818) #1646](https://github.com/espressif/esp-idf/issues/1646)

## Board Pinout

![](assets/esp32-lolin32.png)


## Resources

- [Introduction to RTOS (YouTube)](https://www.youtube.com/watch?v=F321087yYy4&list=PLEBQazB0HUyQ4hAPU1cJED6t3DU0h34bz)
- [Introduction to RTOS (GitHub)](https://github.com/ShawnHymel/introduction-to-rtos)
- [Watchdogs](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/system/wdts.html)
- [Universal Asynchronous Receiver/Transmitter (UART)](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/uart.html)
- [UART Echo Example](https://github.com/espressif/esp-idf/tree/master/examples/peripherals/uart/uart_echo)
- [Hello World with ESP32 Explained](https://exploreembedded.com/wiki/Hello_World_with_ESP32_Explained)