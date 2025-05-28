__asm void your_strcpy(const char *src , char *dst)
{
    mov     r3, #0      // Counter
    mov     r0, r0    // Load src address
    mov     r1, r1    // Load dst address

loop
    ldrb    r2, [r0, r3] // Load character from src at offset r3
    cmp     r2, #0        // Check for null terminator
    beq     done          // If null terminator found, exit loop
    adds    r3, #1        // Increment counter
    b       loop          // Continue looping

done
    subs    r3, #1        // Move back to last valid character
    cmp     r3, #-1       // Check if r3 is -1 (no characters found)
    blt     end           // If no characters found, exit

copy_loop
    ldrb    r2, [r0, r3] // Load character from src at offset r3
    strb    r2, [r1], #1  // Store character to dst and increment dst pointer
    subs    r3, #1        // Decrement counter
    cmp     r3, #-1       // Check if reached the beginning of the string
    bge     copy_loop     // If not, continue copying

end
    bx      lr            // Return
}

int main (void)
{
    const char a[] = "Hello world!";
    char b[20];
    your_strcpy(a, b);
    while(1);
}