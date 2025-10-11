
#ifndef BSP_H_
#define BSP_H_

#include <stdint.h>
#include <stdbool.h>

void led_init(void);
void led_on_green(void);
void led_on_red(void);
void led_off_green(void);
void led_off_red(void);
void button_init(void);
bool get_btn_state(void);

#endif /* BSP_H_ */
