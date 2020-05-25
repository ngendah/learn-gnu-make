#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

static void clock_setup(void)
{
  rcc_clock_setup_pll(&rcc_hse_8mhz_3v3[RCC_CLOCK_3V3_168MHZ]);
  rcc_periph_clock_enable(RCC_GPIOD);
}

static void gpio_setup(void)
{
  gpio_mode_setup(GPIOD, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO12 | GPIO13 | GPIO14 | GPIO15);
}

static void wait(void) {
  int i;
  for (i = 0; i < 60000000; i++) {
    __asm__("nop");
  }
}

int main(void)
{
  clock_setup();
  gpio_setup();
  gpio_set(GPIOD, GPIO12);
  while (1) {
    wait();
    gpio_clear(GPIOD, GPIO12);
    gpio_set(GPIOD, GPIO13);
    wait();
    gpio_clear(GPIOD, GPIO13);
    gpio_set(GPIOD, GPIO14);
    wait();
    gpio_clear(GPIOD, GPIO14);
    gpio_set(GPIOD, GPIO15);
    wait();
    gpio_clear(GPIOD, GPIO15);
    gpio_set(GPIOD, GPIO12);
  }
  return 0;
}
