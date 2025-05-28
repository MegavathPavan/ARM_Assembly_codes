## `working_with_ADC.c` — LED Control via Analog Input on STM32F4

### Overview
This bare-metal program reads analog voltage input from pin **PA0** using **ADC1**, and toggles two LEDs on **PB7** and **PB14** based on the voltage level. If the voltage is less than **1.78V**, LED on PB7 blinks; otherwise, LED on PB14 blinks.

---

### Key Features
- **ADC1** configured in **continuous + scan mode**.
- **Analog input** taken from **PA0 (ADC_IN0)**.
- Uses **GPIOB pins PB7 and PB14** to toggle LEDs.
- LED toggle based on analog voltage threshold of **1.78V**.

---

### Register Configuration Summary

#### Clocks
- `RCC->APB2ENR |= 0x100`: Enables ADC1 clock.
- `RCC->AHB1ENR |= 0x1`: Enables GPIOA clock.
- `RCC->AHB1ENR |= 0x2`: Enables GPIOB clock.

#### GPIO Configuration
- `GPIOA->MODER |= 0x3`: PA0 set to **Analog mode** (for ADC).
- `GPIOB->MODER |= 0x3`: PB0 set to **Analog mode** (not used in logic).
- `GPIOB->MODER |= 0x10000000`: PB7 and PB14 configured as **Output**.
- `GPIOB->ODR = 0x480`: Initially set PB7 and PB14 high.

#### ADC1 Configuration
- `ADC1->CR1 |= (1 << 8)`: Enables **scan mode**.
- `ADC1->CR2 |= 0x2`: Enables **continuous conversion**.
- `ADC1->CR2 |= 0x400`: Enables **end-of-conversion (EOC)**.
- `ADC1->CR2 |= 0x1`: Turns ADC **ON (ADON)**.
- `ADC1->SQR3 |= 0`: First in regular conversion sequence is channel 0 (PA0).

---

### Main Loop Logic
1. Clears ADC status register.
2. Starts conversion using `SWSTART`.
3. Waits for EOC flag (bit 1 of `ADC1->SR`) to be set.
4. Reads digital value from `ADC1->DR`.
5. Converts to voltage using:
   ```c
   voltage = 3.3 * adc_value / 4095;
   ```
6. If voltage < **1.78V**, blinks LED on **PB7**. Otherwise, blinks LED on **PB14**.

---

### Timing
- Delay function implemented as nested loops (`delay(int dd)`).
- Change the `delay` parameter to adjust blink speed.

---

### Notes
- Assumes 12-bit ADC resolution (0–4095).
- `stm32f412Zx.h` must define the relevant register structures.
- Ensure **PA0 is connected to a valid analog source** for meaningful results.

---

### Potential Improvements
- Use **ADC interrupt** instead of polling.
- Add **debouncing** or LED fade for smoother transitions.
- Consider scaling logic for different voltage thresholds.

