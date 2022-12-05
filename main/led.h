#ifndef _LED_H_
#define _LED_H_

typedef enum led_status_t {
  LED_OFF,
  LED_ON,
} led_status_t;

void configure_led(void);
void set_led(led_status_t on);

#endif // _LED_H_
