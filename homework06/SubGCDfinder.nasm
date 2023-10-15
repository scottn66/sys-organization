;-----------------------------
;          CalcGCD
; calculate the greatest common divisor
; receive a in rax (integer 1), b in rcx (integer 2)
; returns the GCD of two ints   64, 24    gcd:8
;-----------------------------
    global   _main
    extern   _printf
    extern   _scanf
    default  rel

    SECTION  .text            ; telling this is the actual program section
_main:
     sub  rsp, 8
                              ; put up prompt, read number, repeat for second number
     lea  rdi, [intreqstr]    ; load effective address of string to print
     call _printf

     mov  rsi, num1           ; &num1 is the second argument for scanf
     lea  rdi, [format]       ; first argument
     call _scanf              ;

     lea  rdi, [intreqstr]
     call _printf

     mov  rsi, num2
     lea  rdi, [format]
     call _scanf

DO: 
    mov  rax, 0       ; error value
    mov  rcx, [num1]
    mov  rdx, [num2]
    cmp  rcx, 0       ; values passed in through rcx and rdx
    je   PA
    cmp  rdx, 0
    je   PA           ; if rcx or rdx is 0, then we print out whatever idc

    push rbx
    mov  rbx, rdx    ; free rdx so we can use DIV 64b operands, if somethings in rdx -> overflow

LoopHead:
    xor  rdx, rdx    ; clear rdx/ zero rdx
    mov  rax, rcx    ; move lower 64 bits (we want to divide) of dividend into rax  ( rcx is the Y value! = 24)
    div  rbx         ;  rdx will be the remainder
    mov  rcx, rbx    ; copy x to y
    mov  rbx, rdx    ; copy remainder to rbx

    cmp  rdx, 0      ; check if r=0, numbers evenly divisible
    jne  LoopHead

    mov  rax, rcx    ; result is in rcx, so move to rax
    pop  rbx

PA:
     mov  rsi, rax             ; result (remainder) is in rax and should print
     lea  rdi, [ansstr]
     call _printf
     jmp END
     
END:
     add  rsp, 8
     mov  rax, 0
     ret

     SECTION .data
intreqstr:   db "Enter integer: ", 0    ; labels are defining messages
ansstr:      db "GCD is: %d", 0xA, 0     ; byte might be db
format:      db "%d", 0
formatout:   db "%d", 0xA, 0

     SECTION .bss
num1: resb 8                  ; changed 8 --> 1 byte of storage
num2: resb 8                  ;reserving 8 bytes of data
