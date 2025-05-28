/*
#include "stm32f412Zx.h"

void delay(int dd);
int main() {
    RCC->AHB1ENR |= 0x02; 
    GPIOB->MODER |= 0x10004000; 
    GPIOB->ODR = 0x0; 
		SysTick -> LOAD = 16000000;
		SysTick -> VAL = 0;
		SysTick -> CTRL = 0x5;
	
		int c = 0;
    while (1) {
			if (SysTick -> CTRL & 0x00010000){
				c++;
				if (c % 10 == 0){
					GPIOB -> ODR  ^= 0x4080;
				}
    }
}
}*/

#include "stm32f4xx.h"

	int main(){
		RCC -> AHB1ENR |= 0x02;
		GPIOB -> MODER = 0x10004000;
		GPIOB -> ODR = 0x0000;
		RCC -> APB1ENR |= 1;
		TIM2 -> PSC = 1599;
		TIM2 -> ARR = 49999;
		TIM2 -> CNT = 0;
		TIM2 -> CR1 = 0X11;
		while(1){
			while(!(TIM2 -> SR & 1)){}
				TIM2 -> SR = 0;
				GPIOB -> ODR^=0x4080;
	}
}
