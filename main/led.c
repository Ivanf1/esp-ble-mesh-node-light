#include <stdio.h>

#include "esp_log.h"

#include "led_strip.h"

#include "led.h"

#define LED_RING_DI_PIN 33
#define NUM_LED 8

static const char *TAG = "LED";

led_strip_t led_strip = {
    .type = LED_STRIP_WS2812,
    .length = NUM_LED,
    .gpio = LED_RING_DI_PIN,
    .buf = NULL,
    .brightness = 10,
};

static const rgb_t colors[] = {
    {.r = 0x00, .g = 0x00, .b = 0x00},
    {.r = 0xff, .g = 0xff, .b = 0xff},
};

void configure_led(void) {
  ESP_LOGI(TAG, "Configuring led");

  led_strip_install();
  ESP_ERROR_CHECK(led_strip_init(&led_strip));
}

void set_led(led_status_t status) {
  led_strip_fill(&led_strip, 0, NUM_LED, colors[status]);
  led_strip_flush(&led_strip);
}