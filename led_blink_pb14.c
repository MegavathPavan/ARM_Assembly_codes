#include "stm32f412Zx.h"

void delay(int dd);

int main() {
    RCC->AHB1ENR |= 0x02; // Enables Clock
    GPIOB->MODER |= 0x10000000; // Mode Register for PB14
    GPIOB->ODR = 0x4000; // Output Data Register for PB14
    
    while (1) {
        GPIOB->ODR = 0x4000;
        delay(200);
        GPIOB->ODR = 0x00;
        delay(200);
    }
}

void delay(int dd) {
    int i;
    for (; dd > 0; dd--) {
        for (i=0; i<1000; i++);
    }
}
