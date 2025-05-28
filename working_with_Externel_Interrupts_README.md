# STM32F4 External Interrupt with LED Toggle Example

## Overview

This project demonstrates how to configure and handle an external interrupt on the STM32F4 microcontroller. It sets up a button connected to **PC13** to trigger an interrupt on the rising edge, and toggles an LED connected to **PB7** inside the interrupt service routine (ISR). Two delay methods are provided: a simple busy-wait loop and a timer-based delay.

---

## Code Approach

- **Clock Setup:**  
  Enables the necessary peripheral clocks for GPIO ports B and C, and the SYSCFG module required for external interrupt configuration.

- **GPIO Configuration:**  
  - **PC13** is configured as input for the external interrupt (typically connected to a user button).  
  - **PB7** is configured as an output pin for the LED.

- **External Interrupt Configuration:**  
  - Configures EXTI line 13 to monitor pin PC13 for rising edge events.  
  - Unmasks the interrupt line and enables it in the NVIC.

- **Interrupt Service Routine (ISR):**  
  - When the button on PC13 is pressed, the ISR toggles the LED on PB7 twice with delay intervals.  
  - Clears the interrupt pending flag to allow future interrupts.

- **Delays:**  
  - A simple software busy-wait delay function (`delay`) for short pauses.  
  - A timer-based delay function (`delay_by_counter`) implemented using TIM2 for more precise timing (optional).

- **Main Loop:**  
  - The main program enters an infinite loop, with all functionality driven by the external interrupt.

---

## No Manual Modification Required

- All clock and GPIO configurations are handled in the code.  
- Interrupt lines and priorities are set automatically.  
- No user modifications or external hardware settings (besides the physical connection of button and LED) are needed for the code to run as intended.

---

## Usage

- Connect a button to **PC13** (usually onboard user button).  
- Connect an LED to **PB7** with proper current limiting resistor.  
- Build and flash the firmware onto the STM32F4 device.  
- Pressing the button will cause the LED to blink twice, demonstrating the interrupt handling.

---
