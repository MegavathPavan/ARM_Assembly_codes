## `string_utilities.s` — Basic String Operations in ARM Assembly

### Overview
This ARM assembly source provides implementations of basic string manipulation functions:
- `your_strcpy`: Copies a string.
- `your_capitalize`: Converts lowercase letters to uppercase in-place.
- `your_reverse`: Reverses a string from `src` to `dst`.

### 1. `your_reverse(const char *src, char *dst)`
Reverses a null-terminated input string `src` and stores the result in `dst`.

#### Approach
1. **Find the end** of the string by incrementing `src` until the null terminator (`\0`) is found.
2. **Step back one character** to skip the null byte.
3. **Copy characters in reverse** from the end of `src` to the beginning of `dst`.
4. Terminates after copying all characters (including the null terminator).

#### Registers Used
- `R0`: Pointer to `src` (moved during traversal)
- `R1`: Pointer to `dst`
- `R2`: Temporary byte storage

---

### 2. `your_strcpy(const char *src, char *dst)` *(commented out in code)*
Copies a null-terminated string from `src` to `dst`.

#### Logic
- Reads each character from `src` and writes it to `dst`.
- Stops when the null character (`\0`) is copied.

---

### 3. `your_capitalize(char *src)` *(commented out in code)*
Modifies the string in-place to convert all lowercase alphabet characters to uppercase.

#### Logic
- Iterates through each character.
- Checks if it's in the ASCII range `'a'` to `'z'`.
- If so, subtracts 32 (`0x20`) to convert to uppercase.

---

### Example
```c
const char a[] = "Hello pavan!";
char b[20];
your_reverse(a, b);  // Result in b: "!navap olleH"
```

### Notes
- Ensure `dst` is large enough to hold the result including the null terminator.
- Results must be inspected via debugger or memory viewer.
- Only `your_reverse` is active by default — uncomment other function calls to use them.

```

Let me know if you'd like individual readmes per function or a combined one like above!
