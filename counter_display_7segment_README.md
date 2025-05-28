# STM32F4 7-Segment Display Counter

## Overview

This program counts from 0 to 9 repeatedly and displays the corresponding digit on a 7-segment display connected to GPIOA pins PA0 to PA6. The counting speed is controlled by TIM2 timer interrupts to create a visible delay.

---

## Hardware Setup

- **7-segment display** connected to GPIOA pins PA0-PA6.
- Assumes common-cathode display (or wiring matching segment bits).

---

## Code Description

- **Clock Setup:**
  - Enables GPIOA clock via `RCC->AHB1ENR`.
  - Enables TIM2 clock via `RCC->APB1ENR`.

- **GPIO Configuration:**
  - Sets GPIOA pins 0 to 6 as output mode (`GPIOA->MODER = 0x1555`).
  - Initially sets all segments ON (`GPIOA->ODR |= 0xffff`).

- **Timer Configuration:**
  - TIM2 auto-reload register set to 15,999,999 for 1-second delay at 16 MHz clock.
  - Timer started by setting `TIM2->CR1 = 1`.

- **Display Logic:**
  - `display(int num)` function writes segment bit patterns to `GPIOA->ODR` based on input digit.
  - Main loop waits for timer update event (`TIM2->SR & 1`), clears it, increments and displays next digit modulo 10.

---
