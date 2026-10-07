#include "LED7.h"
LED7_HANDLE hled ;
static uint8_t seg[10]={
		0x3F, //0
		0x06,//1
		0x5B,//2
		0x4F,//3
		0x66,//4
		0x6D,//5
		0x7D,//6
		0x07,//7
		0x7F,//8
		0x6F//9
};
LED_GPIO pin[7] ={{GPIOB, GPIO_PIN_0},
	{GPIOB, GPIO_PIN_1},
		  {GPIOB, GPIO_PIN_2},
		 {GPIOB, GPIO_PIN_3},
		 {GPIOB, GPIO_PIN_4},
		{GPIOB, GPIO_PIN_5},
		 {GPIOB, GPIO_PIN_6}} ;
void LED7_Init(){
	for(int i= 0 ; i< 7 ; i++){
		hled.seg[i] = pin[i] ;
	}

}
void LED7_Display(uint8_t num){
	if(num >9 ) return ;
	uint8_t data = seg[num];
	uint8_t bit ;
	GPIO_PinState state ;
	for (int i  =0 ; i< 7; i++){
	 bit = (data >> i ) & 0x01 ;
	 state = (bit)? 0: 1 ; // anode
	 HAL_GPIO_WritePin(hled.seg[i].Port , hled.seg[i].pin , state) ;
	}
}

