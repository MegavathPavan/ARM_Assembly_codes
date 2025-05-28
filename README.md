## Overview

This repository contains a series of example projects and code files demonstrating various fundamental concepts and peripheral interfaces on the STM32F4 microcontroller platform. Each project focuses on a specific embedded system feature or technique, ranging from assembly-level matrix operations to interrupt-driven UART communication.

>A collection of bare-metal STM32F4 examples demonstrating core embedded systems concepts—ARM assembly, GPIO, timers, ADC, UART, interrupts—designed for hands-on learning and low-level programming

---

## Project List and Descriptions

1. **matrix_transpose.s**  
   This ARM assembly program transposes a 2D matrix stored in memory.
   
2. **matrix_transpose_simple.s**  
   This ARM assembly program transposes a fixed 3x3 matrix. The original matrix is stored in memory, and the result is written to a separate memory block called `transpose`. The approach uses nested loops via register-based index manipulation.

3. **sum_natural_numbers.s**  
   This ARM assembly program calculates the sum of the first `n` natural numbers using a loop-based approach.

4. **reverse_strcpy.c**  
   This ARM assembly function `your_strcpy` copies a null-terminated string from source (`src`) to destination (`dst`) **in reverse order**.

5. **string_utilities.c**  
   Collection of string manipulation functions implemented partly in assembly (copy, capitalize, reverse).

6. **led_blink_pb14.c**  
   This program blinks an LED connected to GPIO pin PB14 using direct register manipulation on an STM32F412 microcontroller (bare-metal, no HAL/LL libraries).

7. **systick_toggle_pb7_pb14.c**  
   This program blinks **GPIO pins PB7 and PB14** using the **SysTick timer** on an STM32F412 microcontroller. The blinking is achieved by toggling the pins every ~1 second (based on a 16 MHz system clock).

8. **tim2_toggle_pb7_pb14.c**  
   This bare-metal program toggles **GPIO pins PB7 and PB14** on the STM32F4 microcontroller using **TIM2**, a general-purpose timer. It eliminates the need for software delays by using hardware timers to generate periodic toggles.

9. **working_with_ADC.c**  
   This program reads analog voltage input from pin **PA0** using **ADC1**, and toggles two LEDs on **PB7** and **PB14** based on the voltage level. If the voltage is less than **1.78V**, LED on PB7 blinks; otherwise, LED on PB14 blinks.

10. **working_with_UART_Interrupt.c**  
    This project configures **USART2**, **Timer2**, **GPIO**, and **External Interrupts** on the STM32F4 microcontroller. It aims to:
- Initialize UART1 for serial communication.
- Configure **Timer2** for precise microsecond-level timing.
- Toggle LEDs using Timer2.
- Set up **external interrupts** (e.g., on **PA2**) using **EXTI line**.

11. **counter_display_7segment.c**  
    This program counts from 0 to 9 repeatedly and displays the corresponding digit on a 7-segment display connected to GPIOA pins PA0 to PA6. The counting speed is controlled by TIM2 timer interrupts to create a visible delay.

12. **working_with_External_Interrupts.c**  
    This project demonstrates how to configure and handle an external interrupt on the STM32F4 microcontroller. It sets up a button connected to **PC13** to trigger an interrupt on the rising edge, and toggles an LED connected to **PB7** inside the interrupt service routine (ISR). Two delay methods are provided: a simple busy-wait loop and a timer-based delay.

---

## General Code Approach

- **Hardware Initialization:**  
  Each example enables and configures clocks for required GPIO ports and peripherals (ADC, UART, TIM, SysTick, EXTI) following STM32F4 register programming conventions.

- **GPIO Setup:**  
  Pins are configured as input, output, or alternate function mode depending on the peripheral or function being demonstrated.

- **Peripheral Configuration:**  
  Timers, ADC, UART, and interrupt controllers are set up via direct register access for precise control and low-level learning.

- **Interrupt Handling:**  
  Several examples employ NVIC and EXTI interrupt configurations to demonstrate event-driven programming.

- **Assembly Integration:**  
  Select string and mathematical operations are implemented in ARM assembly to provide insight into low-level programming and optimization.

---

## Usage and Building

- Each source file can be compiled and flashed to an STM32F4 device with minimal or no modification.  
- Ensure correct pin connections as per the example requirements (LEDs, buttons, ADC inputs, UART lines).  
- For assembly files, use an ARM-compatible assembler and linker or integrate with your C project toolchain.  
- C examples rely on STM32 standard peripheral register definitions (stm32f4xx.h or device-specific headers).

---

## Notes

- This collection is ideal for students and developers learning STM32F4 programming at the register level.  
- The examples provide foundational building blocks to be extended into larger embedded applications.  

---

## Contribution

For questions or contributions, please open issues or pull requests in the repository.
- LinkedIn: [Megavath Pavan](https://www.linkedin.com/in/megavath-pavan-1a4724262/)

---
