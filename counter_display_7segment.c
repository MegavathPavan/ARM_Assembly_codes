#include <stm32f4xx.h>

void display(int num){
		if(num==0){
			GPIOA->ODR = 0x3f;
		}
		if(num==1){
			GPIOA->ODR = 0x06;
		}
		if(num==2){
			GPIOA->ODR = 0x5b;
		}
		if(num==3){
			GPIOA->ODR = 0x4f;
		}
		if(num==4){
			GPIOA->ODR = 0x66;
		}
		if(num==5){
			GPIOA->ODR = 0x6d;
		}
		if(num==6){
			GPIOA->ODR = 0x7d;
		}
		if(num==7){
			GPIOA->ODR = 0x07;
		}
		if(num==8){
			GPIOA->ODR = 0x7f;
		}
		if(num==9){
			GPIOA->ODR = 0x6f;
		}
}

int main(){
	RCC->AHB1ENR |= 0x1;	// enable the clock
	GPIOA->MODER = 0x1555;	// configure the Mode register for output mode for PA0 to PA6 outputs
	GPIOA->ODR |= 0xffff;	// initially all 7 segments will glow
	int cnt = 0;	// count for displaying 0 to 9
	
	RCC->APB1ENR |= 0x1;
	TIM2->ARR = 15999999;	// reload value for 16MHz clock
	TIM2->CNT = 0;
	TIM2->CR1 = 1;
	
	while(1){
		while(!(TIM2->SR & 1)){}
			TIM2->SR = 0;
			cnt = cnt%10;	// continous display of digits 0 to 9
			display(cnt);	// calling function for respective digits
			cnt+=1;	// incriment the counter
	}
}