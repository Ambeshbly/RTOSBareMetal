
#include<stdint.h>
#include "led.h"



void delay(uint32_t count)
{
  for(uint32_t i = 0 ; i < count ; i++);
}

// Register Definitions
#define RCC_AHB1ENR_REG  (*((volatile uint32_t *)0x40023830))
#define GPIOG_MODER_REG  (*((volatile uint32_t *)0x40021800))
#define GPIOG_BSRR_REG   (*((volatile uint32_t *)0x40021818))
#define GPIOG_ODR_REG   (*((volatile uint32_t *)0x40021814))


void led_init(void) {
    // Enable GPIOG clock
    RCC_AHB1ENR_REG |= (1U << 6);

    // Clear mode bits for PG13 and PG14
    GPIOG_MODER_REG &= ~((3U << 26) | (3U << 28));

    // Set mode to Output (01) for PG13 and PG14
    GPIOG_MODER_REG |= ((1U << 26) | (1U << 28));
}

void led_on(uint8_t led_no)
{
  uint32_t *pGpiodDataReg = (uint32_t*)GPIOG_ODR_REG;
  *pGpiodDataReg |= ( 1 << led_no);

}

void led_off(uint8_t led_no)
{
	  uint32_t *pGpiodDataReg = (uint32_t*)GPIOG_ODR_REG;
	  *pGpiodDataReg &= ~( 1 << led_no);

}


