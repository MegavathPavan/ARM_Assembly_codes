/*
__asm void your_strcpy(const char *src , char *dst)
{
loop
    LDRB r2, [r0]  
    ADDS r0, #1
    STRB r2, [r1]
    ADDS r1, #1
    CMP r2, #0
    BNE loop
    BX lr
		
}

__asm void your_capitalize(const char *src)
{
loop1
    LDRB r2, [r0]    
    CMP r2, #0       
    BEQ done         
    CMP r2, #'a'     
    BLT not_lower    
    CMP r2, #'z'
    BGT not_lower
    SUBS r2, r2, #32  
    STRB r2, [r0]    
not_lower
    ADDS r0, #1      
    B loop1           
done
    BX lr
}
*/

__asm void your_reverse(const char *src, char *dst)
{
loop2
		LDRB r2, [r0]
		ADDS r0, #1
    CMP r2, #0
    BNE loop2
		SUBS r0, #1
reverse
    SUBS r0, #1
		LDRB r2, [r0]  
    STRB r2, [r1]
    ADDS r1, #1
    CMP r2, #0
    BNE reverse
    BX lr

}

int main (void)
{
const char a[] = "Hello pavan!";
char b[20];
//your_strcpy(a, b);
//your_capitalize(a);
your_reverse(a, b);
while(1);
}