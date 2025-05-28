/*#include "stm32f4xx.h" // Device header

int main() {
    RCC->AHB1ENR |= 2; // enable clock
    GPIOB->MODER |= 0x10004000; // mode register for PB7 & PB14
    GPIOB->ODR = 0x0; // outout data register for PB7 & PB14
    SysTick->LOAD = 16000000; // Time period of one clock cycle *Load value
    SysTick->VAL = 0;
    SysTick->CTRL = 0x5;
		int c =0;
	
    while (1) {
        if (SysTick->CTRL & 0x00001000) {
            c++;
						if (c%10 == 0) {
							GPIOB->ODR ^= 0x4080;
						}
    }
	}   
    return 1;
}
*/

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
}