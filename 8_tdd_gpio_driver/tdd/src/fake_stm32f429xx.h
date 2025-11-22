#ifndef FAKE_STM32F429XX_H
#define FAKE_STM32F429XX_H
#include <stdint.h>

/* Minimal RCC and GPIO models for host tests*/
typedef struct
{
	volatile uint32_t AHB1ENR;

}RCC_TypeDef;

typedef struct {
	volatile uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
	volatile uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04      */
	volatile uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
	volatile uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
	volatile uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10      */
	volatile uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */
	volatile uint32_t BSRR;     /*!< GPIO port bit set/reset register,      Address offset: 0x18      */

}GPIO_TypeDef;

/* Globals that simulate the cmsis style singleton*/
extern RCC_TypeDef RCC_;
extern GPIO_TypeDef GPIOG_;


#define RCC (&RCC_)
#define GPIOG (&GPIOG_)


#endif