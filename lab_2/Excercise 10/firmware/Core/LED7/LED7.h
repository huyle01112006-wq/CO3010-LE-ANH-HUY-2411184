#ifndef LED7_H
#define LED7_H
#include "stm32f1xx_hal.h"
typedef struct{
	GPIO_TypeDef* Port;
	uint16_t pin ;
} LED_GPIO;
typedef struct{
	LED_GPIO seg[7] ;
}LED7_HANDLE;
extern LED7_HANDLE hled ;
void LED7_Init() ;
void LED7_Display(uint8_t num);
void set_up_enable() ;
#endif
