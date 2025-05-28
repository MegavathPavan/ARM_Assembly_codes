## `systick_toggle_pb7_pb14.c` — GPIO Toggle Using SysTick Timer on STM32F412

### Overview
This program blinks **GPIO pins PB7 and PB14** using the **SysTick timer** on an STM32F412 microcontroller. The blinking is achieved by toggling the pins every ~1 second (based on a 16 MHz system clock).

### Key Features
- Uses **SysTick** instead of software delay loops for timing.
- Toggles **PB7** and **PB14** simultaneously every 10 SysTick events.
- Bare-metal implementation (no HAL/RTOS).

---

### Registers & Configurations
- `RCC->AHB1ENR |= 0x02`: Enables the GPIOB peripheral clock.
- `GPIOB->MODER |= 0x10004000`: Sets **PB7** and **PB14** as general-purpose output.
- `GPIOB->ODR ^= 0x4080`: Toggles bits 7 and 14 (PB7 and PB14).
- `SysTick->LOAD = 16000000`: Configures a 1-second tick for a 16 MHz clock.
- `SysTick->CTRL = 0x5`: Enables SysTick with processor clock and without interrupt.

---

### Execution Flow
1. **GPIO Initialization**:
   - PB7 and PB14 set as output pins.
   - Output data register initialized to `0x0`.

2. **SysTick Timer Setup**:
   - `LOAD = 16000000`: SysTick fires every 1 second (for 16 MHz).
   - `CTRL = 0x5`: Enable timer and use system clock (no interrupts).

3. **Main Loop**:
   - Polls the `COUNTFLAG` bit (`CTRL & 0x10000`).
   - Every 10 ticks (~10 seconds), toggles PB7 and PB14.

---

### Notes
- This implementation avoids software delays and uses hardware timer polling.
- The count variable `c` tracks ticks — GPIO toggles every 10 SysTick counts.
- `#include "stm32f412Zx.h"` assumes CMSIS-compliant header with register definitions.

---

### Optional Enhancements
- Replace polling with SysTick interrupt and toggle logic in ISR.
- Parameterize delay duration or GPIO pins.

```c
// Toggles both PB7 and PB14 every ~10 seconds using XOR
GPIOB->ODR ^= 0x4080;
```

```c
while (1); // Keeps MCU in infinite loop
```
