#include<stdio.h>
#include<stm32f412zx.h>
void lab9(void);
void delay(int x);
void delay_by_counter(void);


int main(){
//  	lab6();
	lab9();
}

void delay_by_counter(){
		RCC->APB1ENR |= 0x01;
		TIM2->PSC = 3999; // prescalerPrevious Value 4000-1
		TIM2->ARR = 3999; 
		TIM2->CNT = 0; // set counter
		TIM2->CR1 = 1; // start timer
		while(1){
			if(TIM2->SR & 1){
					TIM2->SR = 0;
					break;
			}
		}
}

void EXTI15_10_IRQHandler( void ) {
		// part 1
    GPIOB->ODR = 0x80; // Turn on LED
		delay(500000);
		GPIOB->ODR = 0x00;
		delay(500000);
		GPIOB->ODR = 0x80;
		delay(500000);
		GPIOB->ODR = 0x00;
    EXTI->PR = 0x2000;
	
		//part 2
    //GPIOB->ODR = 0x00; // Turn on LED
		//delay_by_counter();
		//GPIOB->ODR = 0x80;
		//delay_by_counter();
		//GPIOB->ODR = 0x00;
		//delay_by_counter();
		//GPIOB->ODR = 0x80;
		//delay_by_counter();
		//GPIOB->ODR = 0x00;
    //EXTI->PR = 0x2000;
		
}


void lab9(){
		__disable_irq();
    RCC->AHB1ENR |= 0x02; // Enable Clock Port B
    RCC->AHB1ENR |= 0x4; // Enable Clock Port C PB connected to PC13
    RCC->APB2ENR |= 0X4000; // Enable clock to SYSCFG
    GPIOB->MODER |= 0x00004000; // Mode R e g i s t e r f o r PB7
    SYSCFG->EXTICR [3 ] = 0X0020; // Port C for EXT 13 INTERRUPT
    EXTI->IMR |= 0x2000; // Unmask interrupt
    EXTI->RTSR |= 0x2000; // Rising edge
    NVIC_EnableIRQ(EXTI15_10_IRQn);
    __enable_irq ();
    while ( 1 ) {}

}

void delay(int x){
	int i=0;
	while(i<x){
		i++;
	}
}