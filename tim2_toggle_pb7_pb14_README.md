## `tim2_toggle_pb7_pb14.c` — Blinking GPIOs Using Timer 2 on STM32F4

### Overview
This bare-metal program toggles **GPIO pins PB7 and PB14** on the STM32F4 microcontroller using **TIM2**, a general-purpose timer. It eliminates the need for software delays by using hardware timers to generate periodic toggles.

### Key Features
- Toggles **PB7** and **PB14** simultaneously.
- Uses **TIM2** in up-counting mode.
- Runs purely on register-level configuration (no HAL, no interrupt).

---

### Register Configuration Breakdown

#### RCC (Clock Configuration)
- `RCC->AHB1ENR |= 0x02`  
  Enables the clock for **GPIOB**.
- `RCC->APB1ENR |= 0x01`  
  Enables the clock for **TIM2**.

#### GPIOB (Pin Configuration)
- `GPIOB->MODER = 0x10004000`  
  Configures **PB7** and **PB14** as output.
- `GPIOB->ODR = 0x0000`  
  Clears both pins initially.

#### TIM2 (Timer Configuration)
- `TIM2->PSC = 1599`  
  Sets prescaler: input clock / 1600 = 10 kHz (assuming 16 MHz).
- `TIM2->ARR = 49999`  
  Auto-reload value: timer overflows every 5 seconds.
- `TIM2->CNT = 0`  
  Resets counter to 0.
- `TIM2->CR1 = 0x11`  
  Enables the timer and sets it in up-counting mode with auto-reload.

---

### Main Loop Behavior
```c
while (!(TIM2->SR & 1)) {}
TIM2->SR = 0;               // Clear update interrupt flag
GPIOB->ODR ^= 0x4080;       // Toggle PB7 and PB14
```
- Polls the **update event flag** (UIF) from TIM2 status register.
- When the timer overflows, toggles PB7 and PB14 using XOR (`^= 0x4080`).

---

### Timing Calculation
- Input clock: 16 MHz (assumed)
- Timer frequency: 16 MHz / 1600 = 10,000 Hz
- Timer period: 49,999 + 1 = 50,000 ticks
- Toggle interval: 50,000 / 10,000 = **5 seconds**

---

### Notes
- Designed for **STM32F4** family, using CMSIS-compliant headers (`stm32f4xx.h`).
- Modify `PSC` and `ARR` to change blinking frequency.
- Can be extended with TIM2 interrupts for more efficient toggling.

---

### Optional Enhancements
- Use interrupt-based timer events to avoid polling.
- Use macros or CMSIS functions for better readability.
