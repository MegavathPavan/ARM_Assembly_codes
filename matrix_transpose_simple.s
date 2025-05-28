	;PRESERVE8
	;TTL TEST
	global main
	
	AREA asectionname, DATA;, READWRITE
	ALIGN
matrix 
	DCD 1,2,3,4,5,6,7,8,9
transpose
	DCD 0,0,0,0,0,0,0,0,0

	AREA transposematrix, CODE;, READONLY
main
	LDR R0, =matrix
	LDR R1, =transpose
	MOV R2, #3
	MOV R3, #0 ;i
	MOV R4, #0 ;j
	
innerloop
	ADD R5, R3, R3, LSL #1 ; 3i
	ADD R5, R5, R4 ; 3i + j
	LDR R6, [R0, R5, LSL #2] ; matrix[0] + 
	
	ADD R5, R4, R4, LSL #1 ; 3j
	ADD R5, R5, R3 ; 3j + i
	STR R6, [R1, R5, LSL #2]
	
	ADD R4, R4, #1 ;j=j+1
	CMP R4, R2
	BEQ outerloop
	B innerloop

outerloop
	ADD R3, R3, #1
	CMP R3, R2
	BEQ stop
	MOV R4, #0 ; j=0
	B innerloop

stop
	B stop
	END
	
	