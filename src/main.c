/**
 * Solution to 02 - Blinky Challenge
 *
 * Toggles LED at different rates using separate tasks.
 */

// Include FreeRTOS for delay and task functionality
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
// Include the GPIO driver for the LED
#include <driver/gpio.h>

// Use only core 0 for demo purposes
// CONFIG_FREERTOS_UNICORE=y

#define LED_PIN 5 // LED connected to GPIO5 (On-board LED) which is active low

// Task 1: blink an LED every 1000ms
void toggleLED1(void *parameter)
{
  while (1)
  {
    gpio_set_level(LED_PIN, 0);
    vTaskDelay(50 / portTICK_RATE_MS);
    gpio_set_level(LED_PIN, 1);
    vTaskDelay(950 / portTICK_RATE_MS);
  }
}

// Task 2: blink an LED every 700ms
void toggleLED2(void *parameter)
{
  while (1)
  {
    gpio_set_level(LED_PIN, 0);
    vTaskDelay(50 / portTICK_RATE_MS);
    gpio_set_level(LED_PIN, 1);
    vTaskDelay(650 / portTICK_RATE_MS);
  }
}

void app_main()
{
  // Configure pin
  gpio_config_t io_conf;
  io_conf.intr_type = GPIO_PIN_INTR_DISABLE;
  io_conf.mode = GPIO_MODE_OUTPUT;
  io_conf.pin_bit_mask = (1ULL << LED_PIN);
  io_conf.pull_down_en = 0;
  io_conf.pull_up_en = 0;
  gpio_config(&io_conf);

  // Task to run forever
  xTaskCreate(
      toggleLED1,          // Function to be called
      "Toggle LED 1",      // Name of task
      1024,                // Stack size (bytes in ESP32, words in FreeRTOS)
      NULL,                // Parameter to pass to function
      1,                   // Task priority (0 to configMAX_PRIORITIES - 1)
      NULL                 // Task handle
  );

  // Task to run forever
  xTaskCreate(
      toggleLED2,          // Function to be called
      "Toggle LED 2",      // Name of task
      1024,                // Stack size (bytes in ESP32, words in FreeRTOS)
      NULL,                // Parameter to pass to function
      1,                   // Task priority (0 to configMAX_PRIORITIES - 1)
      NULL                 // Task handle
  );

  // If this was vanilla FreeRTOS, you'd want to call vTaskStartScheduler() in
  // main after setting up your tasks.
}
