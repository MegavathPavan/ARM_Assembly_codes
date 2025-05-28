## `reverse_strcpy.s` — Reverse Copy of a String in ARM Assembly

### Overview
This ARM assembly function `your_strcpy` copies a null-terminated string from source (`src`) to destination (`dst`) **in reverse order**.

### Behavior
Given a string like `"Hello world!"`, the function writes `"!dlrow olleH"` to the destination buffer.

### Approach
1. **Locate String End:**
   - Iterate over `src` using a counter `r3` until the null terminator (`'\0'`) is found.
   - This gives the total length of the string.

2. **Reverse Copy:**
   - Decrement the counter to point to the last valid character.
   - Copy each character from the end of `src` to the beginning of `dst`.
   - Continue until all characters are copied in reverse order.

3. **No null terminator** is added at the end of `dst`. It must be handled externally if required.

### Registers Used
- `R0`: Source string pointer (`src`)
- `R1`: Destination buffer pointer (`dst`)
- `R2`: Temporary character buffer
- `R3`: Index/counter

### Function Signature
```c
__asm void your_strcpy(const char *src, char *dst)
```

### Usage Example (C)
```c
const char a[] = "Hello world!";
char b[20];
your_strcpy(a, b);  // b will contain "!dlrow olleH"
```

### Notes
- No standard library functions are used.
- The function performs a reverse copy, not a normal `strcpy`.
- Ensure `dst` is large enough to hold the reversed string.
- Intended for ARM platforms supporting inline assembly.

```c
while (1); // Halts the program
```

Use a debugger to view the reversed result in `b`.

