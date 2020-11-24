#include "main.h"

void delay(int millis)
{
	while (millis-- > 0) {
		volatile int x = 5971;
		while (x-- > 0) {
			__asm("nop");
		}
	}
}

int main(void)
{

	// GPIO structure for port initialization
	GPIO_InitTypeDef GPIO_InitStructure;

	// enable clock for GPIOC
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);

	// configure port C8 for driving an LED
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; // output mode
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; // highest speed
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; // push-pull
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL; // No pullup or pulldown
	GPIO_Init(GPIOC, &GPIO_InitStructure) ; // initialize port

	// main loop
	while(1) {
		GPIO_SetBits(GPIOC, GPIO_Pin_8); // turn the LED on
		delay(DELAY);

		GPIO_ResetBits(GPIOC, GPIO_Pin_8); // turn the LED off
		delay(DELAY);
	}
}
