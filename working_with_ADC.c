#include "stm32f412Zx.h" // Device header

int adc_value; // Defining variable to watch ADC values
void delay(dd) {
	for (; dd>0; dd--) {
		for (int i = 0; i<1000; i++);
	}
}
int main() {
    RCC->APB2ENR |= 0x100; // Enable clock for ADC1
    RCC->AHB1ENR |= 0x1;   // Enable clock for GPIOA (PA0 is internally connected to IN0)
    RCC->AHB1ENR |= 0x2;	 // Enable clock for GPIOB
    ADC1->CR2 |= 0x2;      // Enable continuous conversion mode
    ADC1->CR2 |= 0x400;    // End of conversion after each conversion
    ADC1->CR2 |= 0x1;      // ADON = 1 enable ADC1
    ADC1->SQR3 |= 0;       // Conversion in regular sequence
		ADC1->CR1 |= (1<<8);		 // Scan mode enabled
	
    GPIOA->MODER |= 0x3;   // Analog mode for PA0
    GPIOB->MODER |= 0x3;   // Analog mode for PB0
    GPIOB->MODER |= 0x10000000;   // Outpu mode for PB7 and PB14
		GPIOB -> ODR = 0x480;  		 // initially LED at PB7 and PB14 blinks

    while (1) {
        ADC1->SR = 0;                  // Clear the status register
        ADC1->CR2 |= (0x40000000);     // Start conversion by SWSTART
        while (ADC1->SR & (0x2)) {     // Check until conversion completes
            adc_value = ADC1->DR;      // Update ADC value to defined variable
					if (3.3 * adc_value / 4095 < 1.78) {
							GPIOB -> ODR = 0x80;			 // turn on LED at PB7 for <1.78
							delay(200);
							GPIOB -> ODR = 0x400;			 // turn off LED at PB14 for >= 1.78
							delay(200);
						}
				}
		}
}
