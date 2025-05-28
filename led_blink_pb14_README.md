## `led_blink_pb14.c` — STM32F412 Bare-Metal LED Blink on PB14

### Overview
This program blinks an LED connected to **GPIO pin PB14** using direct register manipulation on an STM32F412 microcontroller (bare-metal, no HAL/LL libraries).

### Approach
- Enable the clock for GPIO Port B via the RCC AHB1 peripheral.
- Configure **PB14** as a general-purpose output pin.
- Use a simple delay loop to toggle the pin state every ~200 ms.

### Key Registers Used
- `RCC->AHB1ENR`: Enables clock for GPIOB.
- `GPIOB->MODER`: Configures PB14 as output (`MODER14 = 01`).
- `GPIOB->ODR`: Sets and clears the output value on PB14.

### Execution Flow
1. Enable GPIOB clock with `RCC->AHB1ENR |= 0x02;`
2. Set PB14 as output using `GPIOB->MODER |= 0x10000000;`  
   (i.e., set bit 28 to `01`)
3. Continuously:
   - Turn on PB14 (`GPIOB->ODR = 0x4000`)
   - Delay ~200 ms
   - Turn off PB14 (`GPIOB->ODR = 0x00`)
   - Delay ~200 ms

### Delay Function
Implements a simple software delay loop:
```c
void delay(int dd) {
    for (; dd > 0; dd--) {
        for (int i = 0; i < 1000; i++);
    }
}
```

### Notes
- Assumes an LED is physically connected to PB14.
- Timing is approximate and uncalibrated — varies with system clock.
- `#include "stm32f412Zx.h"` assumes correct header file with register definitions.
- No HAL/RTOS involvement — fully bare-metal.

```c
while (1); // Keeps the MCU in infinite toggle loop
```
