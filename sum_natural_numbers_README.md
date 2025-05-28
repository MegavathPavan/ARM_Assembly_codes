## `sum_natural_numbers.s` — Sum of First N Natural Numbers in ARM Assembly

### Overview
This ARM assembly program calculates the sum of the first `n` natural numbers using a loop-based approach.

### Approach
- The program uses a simple iterative method to compute the sum:
  ```
  sum = 1 + 2 + 3 + ... + n
  ```
- The loop runs from `i = 1` to `i = n`, incrementing `sum` by `i` in each iteration.

### Execution Flow
1. Load `n = 3` into `r0`. (Change this value to sum up to a different `n`.)
2. Initialize `i = 0` in `r1` and `sum = 0` in `r2`.
3. Loop until `i == n`:
   - Increment `i` by 1.
   - Add `i` to `sum`.
4. Exit loop and halt execution with an infinite loop (`STOP`).

### Registers Used
- `R0`: Upper limit `n`
- `R1`: Loop counter `i`
- `R2`: Accumulator for the result `sum`

### Result
- After execution, `R2` holds the final sum of the first `n` natural numbers.

### Notes
- Modify `R0` to change the value of `n`.
- Result is not printed or stored to memory — observe `R2` in a debugger or register viewer.
- The program halts via a permanent infinite loop (`B STOP`).
