#include "stm32f4xx.h"

void delayMS(int delay);
void USART2_Init(void);

char USART2_Read(void);


void UART1_Init(void) {
    // Enable UART and GPIO clock
    RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
    
    // Configure UART1 pins (PB6 as TX, PB7 as RX)
    GPIOA->MODER |= 0x400;
    GPIOA->AFR[0] |= 0x7000;
    
    // Configure UART1
    USART1->BRR = 1667; // For 9600 baud rate with 16MHz clock
    USART1->CR1 |= 0x200C; // 13th, 3rd, 2nd bit  0010 0000 0000 1100  
}

void timer2initialize( )
{
		RCC->AHB1ENR |= 0x02 ; 
		GPIOB->MODER |= 0x10004000 ; 
		GPIOB->ODR = 0x0 ; 
		RCC->APB1ENR |= 0x01 ;
	
		TIM2->PSC = 15 ; 
		TIM2->ARR = 9 ; //for 10microseconds
		TIM2->CNT = 0 ; 
		TIM2->CR1 = 1 ;
}

int main(void)
{
		RCC->AHB1ENR |= 0x10;	 // Enable clock for GPIOE
		GPIOE->MODER |= 0x400; // Configure Trig pin (PE4) as output
		GPIOA->ODR |= 0x00; //1<<10 => 0000 0100 0000 0000
		RCC->AHB1ENR |= 1;
		GPIOA->MODER |= 0x400; //1<<10 => 0000 0100 0000 0000
		USART2_Init();

		/*timer2initialize();
		while(1)
		{
				
        while (!(TIM2->SR & TIM_SR_UIF)) {}
        
					TIM2->SR &= ~TIM_SR_UIF; //TIM2->SR =TIM2->SR & ~TIM_SR_UIF
					GPIOB->ODR ^= 0x4080;
					
		}
		*/
		while(1)
		{
				RCC->AHB1ENR |= 0x01;
				RCC->APB1ENR |= 0x1;
				RCC->APB2ENR |= 0x2;
				GPIOA->MODER |= 0x0001; //0000 0000 0000 0001
				SYSCFG->EXTICR[1]= 0x0001; //0000 0000 0000 0001
				EXTI->IMR |=0x04; //unmask interrupt
				NVIC_EnableIRQ(EXTI15_10_IRQn);
				__enable_irq();
				

		}	
		
	
		
	
}