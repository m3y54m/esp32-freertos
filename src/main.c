/**
 * Demo for 02 - Blinky
 *
 * Toggles the LED on and off in its own task/thread.
 */


// Include FreeRTOS for delay and task functionality
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
// Include the GPIO driver for the LED
#include <driver/gpio.h>

// Use only core 1 for demo purposes
#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu = 0;
#else
static const BaseType_t app_cpu = 1;
#endif

#define LED_PIN 5 // LED connected to GPIO5 (On-board LED)

// Our task: blink an LED
void toggleLED(void *parameter)
{
  while (1)
  {
    gpio_set_level(LED_PIN, 1);
    vTaskDelay(500 / portTICK_RATE_MS);
    gpio_set_level(LED_PIN, 0);
    vTaskDelay(500 / portTICK_RATE_MS);
  }
}

int app_main()
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
  xTaskCreatePinnedToCore( // Use xTaskCreate() in vanilla FreeRTOS
      toggleLED,           // Function to be called
      "Toggle LED",        // Name of task
      1024,                // Stack size (bytes in ESP32, words in FreeRTOS)
      NULL,                // Parameter to pass to function
      1,                   // Task priority (0 to configMAX_PRIORITIES - 1)
      NULL,                // Task handle
      app_cpu);            // Run on one core for demo purposes (ESP32 only)

  // If this was vanilla FreeRTOS, you'd want to call vTaskStartScheduler() in
  // main after setting up your tasks.

  // Main loop
  while (1)
  {
    // Do nothing
  }
}
