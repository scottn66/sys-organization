;---------------------------------------------
; paritygen.asm
; 
; this program counts the bits in a 32 bit value
; returning "1" if a partiy bit should be set to maintain 'odd' parity,
; otherwise, it prints a "0". the Given 32 bit value will be hardcoded
;
; assemble: nasm -f macho64 paritygen.nasm
; to link:  gcc paritygen.o -o paritygen
;---------------------------------------------

      global     _main
      extern     _printf
      default    rel

      section    .text

_main:
    sub          rsp, 8

top1:
    mov          rbx,    [number]         ; load number into rbx
    mov          rbx,    0x00000001       ; load mask into rbx
    mov          rcx,    0x00000020       ; load countdown value
    xor          rdx,    rdx              ; clear rdx
    and          rax,    rbx              ; check LSB
    cmp          rax,    0x00000000       ; check if there's a '1'
    jne          count

top2: 
	mov			 rax,    [number]         ; reload number
	shl 		 rbx,    1 				  ; move mask one bit to the left
	and 		 rax,    rbx			  ; check next
	cmp          rax,    0x00000000		  ; check if there's a '1'
	jne			 count                    ; increments bit counter
	dec			 rcx					  ; 'one less position'
    cmp          rcx,    0x00000000
    jne          top2
    jmp          result

count:
    inc          rdx       				  ; counted a bit
    dec			 rcx					  ; one less position
    cmp			 rcx,   0x00000001        
    jne			 top2

result:
	and          rdx,   0x00000001
	cmp          rdx,   0x00000001
	jne		     print1

print0:
    lea			 rdi,   [format0]
    call 	   	 _printf
    add			 rsp, 8
    ret

print1:
	lea          rdi,   [format1]
	call 		 _printf
	add			 rsp, 8
	ret

        section      .data
counter: db           32
number:  dw			  2468


format0: db		      0xA, 0xA, '   Parity bit: 0', 0xA, 0xA, 0
format1: db		      0xA, 0xA, '   Parity bit: 1', 0xA, 0xA, 0



