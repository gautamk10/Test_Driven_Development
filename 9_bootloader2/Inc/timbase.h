
#ifndef TIMBASE_H_
#define TIMBASE_H_
#include <stdint.h>

uint32_t get_tick(void);
void delay(uint32_t delay);
void timbase_init(void);

#endif /* TIMBASE_H_ */
