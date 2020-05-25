#include <FreeRTOS.h>
#include <task.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

extern void vApplicationStackOverflowHook(xTaskHandle *pxTask,signed portCHAR *pcTaskName);

void
vApplicationStackOverflowHook(xTaskHandle *pxTask,signed portCHAR *pcTaskName)\
{
  (void)pxTask;
  (void)pcTaskName;
  for(;;);
}

static void clock_setup(void)
{
  rcc_clock_setup_pll(&rcc_hse_8mhz_3v3[RCC_CLOCK_3V3_168MHZ]);
  rcc_periph_clock_enable(RCC_GPIOD);
}

static void gpio_setup(void)
{
  gpio_mode_setup(GPIOD, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO12 | GPIO13 | GPIO14 | GPIO15);
}

static void myTask1(void *args) {
  const portTickType xDelay = 500 / portTICK_RATE_MS;
  while (1) {
    gpio_clear(GPIOD, GPIO15);
    gpio_set(GPIOD, GPIO12);
    vTaskDelay( xDelay );
    gpio_clear(GPIOD, GPIO12);
    gpio_set(GPIOD, GPIO13);
    vTaskDelay( xDelay );
    gpio_clear(GPIOD, GPIO13);
    gpio_set(GPIOD, GPIO14);
    vTaskDelay( xDelay );
    gpio_clear(GPIOD, GPIO14);
    gpio_set(GPIOD, GPIO15);
    vTaskDelay( xDelay );
  }
}

int main(void)
{
  clock_setup();
  gpio_setup();

  xTaskCreate(myTask1, "blink", 512, NULL, configMAX_PRIORITIES-1, NULL);
  vTaskStartScheduler();
  while(1);
  return 0;
}
