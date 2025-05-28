	AREA sum_natural, CODE
	EXPORT __main
	ALIGN
	ENTRY

__main PROC
	LDR r0, =0x00000003	;n = 6
	MOV r1, #0	;i = 0
	MOV r2, #0	;sum = 0
	B for_loop
	
for_loop
	CMP r1, r0
	BEQ DONE
	ADD r1, r1, #1	;i = i + 1
	ADD r2, r2, r1	;sum = sum + i
	B for_loop
	
DONE
	B STOP	;end

STOP
	B STOP	;while(1)
	ENDP
	END