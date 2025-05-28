# Matrix Transpose in ARM Assembly

## Description
This ARM assembly program transposes a 2D matrix stored in memory.  
- The input matrix `mtx` is a 3x3 matrix of integers.
- The transposed matrix is stored in `mtx_t`.
- The dimensions of the matrix (rows and columns) are stored in the `size` array.
- The program uses simple nested loops in assembly to transpose the matrix.
- After the transpose operation, the program enters an infinite loop to halt execution.

## Memory Layout
- `size` holds two integers: number of rows and number of columns (currently both 3).
- `mtx` is the original matrix (3x3).
- `mtx_t` is the matrix to hold the transpose result (initialized to zeros).

## Registers Used
- R0: Base address of input matrix (`mtx`)
- R1: Base address of output matrix (`mtx_t`)
- R2: Number of rows
- R3: Number of columns
- R4: Row index in loops
- R5: Column index in loops
- R6: Temporary storage for matrix element
- R7: Calculated offset inside the matrix

## How to Use
- Assemble and link with an ARM toolchain.
- Load the binary onto a compatible ARM device or emulator.
- The transpose function is called in `main`.
- Modify `size` if you want to transpose matrices of different dimensions.

## Notes
- This implementation assumes a 2D matrix stored in row-major order.
- The transpose stores output in a separate matrix (`mtx_t`).
- To perform in-place transpose, significant changes are needed.
- The matrix size is currently fixed (3x3) but can be changed by updating the `size` array.

## Code Structure
- `main`: loads addresses and sizes, calls `transpose_matrix`.
- `transpose_matrix`: nested loops to read and write transposed elements.
- `stop`: infinite loop to halt the program.

---

## Possible Improvements
- Add comments for each instruction for better readability.
- Consider parameterizing matrix size via input registers or memory.
- Implement in-place transpose (more complex due to data overwriting).
- Add error checking for matrix size consistency.

