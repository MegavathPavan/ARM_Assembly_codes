## `matrix_transpose_simple.s` — Transposing a 3x3 Matrix in ARM Assembly

### Overview
This ARM assembly program transposes a fixed 3x3 matrix. The original matrix is stored in memory, and the result is written to a separate memory block called `transpose`. The approach uses nested loops via register-based index manipulation.

### Approach
- The matrix is stored in **row-major order** as a flat array (`matrix`).
- The **transpose** operation places element `matrix[i][j]` into `transpose[j][i]`.
- Indexing is achieved by converting `(i, j)` and `(j, i)` into 1D offsets using:
  - `offset = 3 * i + j` for `matrix[i][j]`
  - `offset = 3 * j + i` for `transpose[j][i]`
- The program uses two loops:
  - Outer loop over rows (`i` from 0 to 2)
  - Inner loop over columns (`j` from 0 to 2)

### Registers Used
- `R0`: Base address of `matrix`
- `R1`: Base address of `transpose`
- `R2`: Matrix size (fixed to 3)
- `R3`: Row index (`i`)
- `R4`: Column index (`j`)
- `R5`: Intermediate offset calculation
- `R6`: Data holder for value being moved

### Execution Flow
1. Initialize base addresses and loop counters.
2. For each element:
   - Compute `3*i + j` → read from `matrix`
   - Compute `3*j + i` → write to `transpose`
3. Repeat until all elements are transposed.
4. Halt with an infinite loop (`stop`).

### Matrix Example
```
Input matrix (matrix):
1 2 3
4 5 6
7 8 9

Output (transpose):
1 4 7
2 5 8
3 6 9
```

### Notes
- Matrix size is fixed at 3×3. Modify only the data and `R2` value to change size.
- The program stops with a loop (`B stop`) after transposing.
