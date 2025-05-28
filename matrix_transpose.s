	;PRESERVE8
	;TTL TEST
	;global __main
		
	AREA mtx_data, DATA;, READWRITE
	ALIGN
size
	DCD 3,3
mtx
    DCD 1,2,3,4,5,6,7,8,9;,10,11,12
mtx_t
    DCD 0,0,0,0,0,0,0,0,0;,0,0,0
	
	AREA mtx_code, CODE;, READONLY
	EXPORT main
	ALIGN
	ENTRY

main PROC
    LDR R0, =mtx  ; Load the base address of the matrix
    LDR R1, =mtx_t  ; Load the base address of the transpose matrix (same location for in-place transpose)
    LDR R2, =size            ; Set the number of rows (change as needed)
    LDR R2, [R2]
	LDR R3, =size            ; Set the number of columns (change as needed)
	LDR R3, [R3, #4]

    BL transpose_matrix   ; Call the function to transpose the matrix

    ; Infinite loop to keep the program running
    B stop

transpose_matrix
	MOV R5, #0            ; Initialize column index
col_loop
	MOV R4, #0            ; Initialize row index
	MOV R7, R5
row_loop
	LDR R6, [R0, R7, LSL #2] ; Load the current element (matrix[R4][R5])
	STR R6, [R1], #4	  ; Store it in the transposed position (matrix[R5][R4])
	ADD R7, R7, R3
	
    ADD R4, R4, #1        ; Increment row index
    CMP R4, R2            ; Compare with the number of rows
    BLT row_loop          ; If less than, continue the loop

    ADD R5, R5, #1        ; Increment col index
    CMP R5, R3            ; Compare with the number of colms
    BLT col_loop          ; If less than, continue the loop

    BX LR                 ; Return from the function

stop
    B stop                ; Infinite loop to halt the program
	ENDP
	END
