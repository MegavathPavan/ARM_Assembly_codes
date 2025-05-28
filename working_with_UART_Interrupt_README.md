# STM32F4 - UART, Timer2, and External Interrupt Demo

### Overview

This project configures **USART2**, **Timer2**, **GPIO**, and **External Interrupts** on the STM32F4 microcontroller. It aims to:
- Initialize UART1 for serial communication.
- Configure **Timer2** for precise microsecond-level timing.
- Toggle LEDs using Timer2.
- Set up **external interrupts** (e.g., on **PA2**) using **EXTI line**.

---

### Peripherals Used

| Peripheral | Purpose |
|-----------|---------|
| **GPIOA/B/E** | For LED control, UART pins, trigger pin |
| **USART1 / USART2** | Serial communication (configured, not actively used in main loop) |
| **TIM2** | Microsecond delay generation and LED toggling |
| **EXTI / NVIC** | External interrupt setup on PA2 |

---

### Code Modules

#### `UART1_Init()`
- Enables USART1 and GPIOB clocks.
- Configures **PB6 (TX)** and **PB7 (RX)** for UART.
- Sets baud rate to **9600** (BRR = 1667 for 16 MHz).
- Enables UART transmission and reception.

---

#### `timer2initialize()`
- Enables Timer2 and configures prescaler & auto-reload:
  - `PSC = 15`, `ARR = 9` for **10 µs** period.
- Toggles `PB7` and `PB14` every timer overflow using UIF flag.

---

#### `main()`
- Configures:
  - `PE4` as output (Trigger pin).
  - `PA5` as output.
- Initializes `USART2`
- Initializes `Timer2` in commented section.
- Sets up **EXTI interrupt on PA2**:
  - `SYSCFG->EXTICR[1] = 0x0001`: Routes EXTI2 to PA2.
  - `EXTI->IMR |= 0x04`: Unmasks interrupt line 2.
  - `NVIC_EnableIRQ(EXTI15_10_IRQn)`: Enables interrupt handler in NVIC.
  - `__enable_irq()`: Globally enables IRQs.

---


### Example Use Case
This setup is useful as a base for:
- Reading an ultrasonic sensor (trigger via PE4, capture echo via PA2 interrupt).
- Sending distance over UART.
- Debugging LED toggling using a timer.

---

```c
// Basic EXTI Handler Example
void EXTI15_10_IRQHandler(void) {
    if (EXTI->PR & 0x04) {
        // Handle interrupt
        GPIOB->ODR ^= 0x4080;
        EXTI->PR = 0x04; // Clear pending bit
    }
}
```
