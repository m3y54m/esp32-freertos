/**
 * Hello World!
 *
 * Prints "Hello, World" to console
 */

// Include FreeRTOS for delay and task functionality
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
// Include UART driver
#include "driver/uart.h"
// For strlen()
#include <string.h>

// Use only core 0 for demo purposes
// CONFIG_FREERTOS_UNICORE=y

// Setup UART buffered IO with event queue
#define BUF_SIZE (1024)

// Our task: print Hello, World!
void printHelloWorld(void *parameter)
{
  // Write data to UART.
  char *test_str = "Hello, World!\n";
  uart_write_bytes(UART_NUM_0, (const char *)test_str, strlen(test_str));

  while (1)
  {
    vTaskDelay(10 / portTICK_RATE_MS);
  }
}

void app_main()
{
  // Create UART0 configuration variable
  uart_config_t uart_config = {
      .baud_rate = 115200,
      .data_bits = UART_DATA_8_BITS,
      .parity = UART_PARITY_DISABLE,
      .stop_bits = UART_STOP_BITS_1,
      .flow_ctrl = UART_HW_FLOWCTRL_DISABLE};
  // Configure UART0
  uart_param_config(UART_NUM_0, &uart_config);
  // Set UART0 pins (using UART0 default pins ie no changes)
  uart_set_pin(UART_NUM_0, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
  // Install UART driver
  uart_driver_install(UART_NUM_0, BUF_SIZE * 2, 0, 0, NULL, 0);

  // Task to run forever
  xTaskCreate(
      printHelloWorld,     // Function to be called
      "Print Hello World", // Name of task
      1024,                // Stack size (bytes in ESP32, words in FreeRTOS)
      NULL,                // Parameter to pass to function
      1,                   // Task priority (0 to configMAX_PRIORITIES - 1)
      NULL                 // Task handle
  );
}
