#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

/* LEDs na nRF52832 DK (PCA10040): ACTIVE_LOW */
#define LED1_PIN 17  /* P0.17 */
#define LED2_PIN 18  /* P0.18 */
#define LED3_PIN 19  /* P0.19 */
#define LED4_PIN 20  /* P0.20 */

#define BLINK_DELAY_MS 500

int main(void)
{
    const struct device *gpio_dev = DEVICE_DT_GET(DT_NODELABEL(gpio0));

    if (!device_is_ready(gpio_dev)) {
        return -1;
    }

    /* Configura os 4 LEDs como saída (inicialmente desligados) */
    gpio_pin_configure(gpio_dev, LED1_PIN, GPIO_OUTPUT_INACTIVE);
    gpio_pin_configure(gpio_dev, LED2_PIN, GPIO_OUTPUT_INACTIVE);
    gpio_pin_configure(gpio_dev, LED3_PIN, GPIO_OUTPUT_INACTIVE);
    gpio_pin_configure(gpio_dev, LED4_PIN, GPIO_OUTPUT_INACTIVE);

    while (1) {
        /* Liga todos os LEDs */
        gpio_pin_set(gpio_dev, LED1_PIN, 1);
        gpio_pin_set(gpio_dev, LED2_PIN, 1);
        gpio_pin_set(gpio_dev, LED3_PIN, 1);
        gpio_pin_set(gpio_dev, LED4_PIN, 1);

        k_msleep(BLINK_DELAY_MS);

        /* Desliga todos os LEDs */
        gpio_pin_set(gpio_dev, LED1_PIN, 0);
        gpio_pin_set(gpio_dev, LED2_PIN, 0);
        gpio_pin_set(gpio_dev, LED3_PIN, 0);
        gpio_pin_set(gpio_dev, LED4_PIN, 0);

        k_msleep(BLINK_DELAY_MS);
    }

    return 0;
}
