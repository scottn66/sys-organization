
.data
intReqStr   BYTE "Enter integer: ",0
ansStr      BYTE "GCD is: ", 0

.code
main proc
L1:
     mov edx, OFFSET intReqStr   ;display integer request
     call WriteString
     call ReadInt
     jz  QUIT
     mov  ebx, eax                ; assign to y
     call WriteString
     call ReadInt
     jz  QUIT

     call CalcGCD

     mov edx, OFFSET ansStr
     call WriteString
     call WriteDec
     call Crlf
     call Crlf
     jmp L1
     

QUIT:
     invoke ExitProcess, 0
main endp

;-----------------------------
CalcGCD
; calculate the greatest common divisor
; receive x in EAX (integer 1), y in EBX (integer 2)
; returns x in EAX = GCD
;-----------------------------
     push ebx
     push edx

     cmp  eax, 0              ; if x >= 0, 
     jge  LX                  ; jump over negate
     neg  eax                 ; x was negative so negate
LX:
     cmp  ebx, 0              ; if x >= 0, 
     jge  LY                  ; jump over negate
     neg  ebx                 ; x was negative so negate
     pop edx
     pop EBX
     ret
LY:
DO:  mov  edx, 0
     DIV  ebx                 ; edx = eax % ebx (r = x % y)
     mov  eax, ebx            ; eax = ebx (x = y)
     mov  ebx, edx            ; ebx = edx (y = r)

     cmp  ebx, 0              ; while ebx > 0
     jg   DO                  ; jump to DO if ebx is greater
                              ; value to be returned is in eax

     pop edx
     pop EbX
     ret
CalcGCD ENDP

end main