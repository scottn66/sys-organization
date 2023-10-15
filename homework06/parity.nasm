    global   _main
    extern   _printf
    default  rel 

    section  .text

_main
    sub      rsp, 8

top1:
    move     rax, [number]
    mov      rbx, 0x00000001
    mov      rcx, 0x00000020
    xor      rdx, rdx
    and      rax, rbx
    cmp      rax, 0x00000000
    jne      count

top2:
    mov      rax, [number]
    shl      rbx, 1
    and      rax, rbx
    cmp      rax, 0x00000000
    jne      count
    dec      rcx
    cmp      rcx, 0x00000000
    jne      top2
    jmp      result

count:
    inc      rdx
    dec      rcx
    cmp      rcx, 0x00000000
    jne      top2

result:
    and      rdx, 0x00000001
    cmp      rdx, 0x00000001
    jne      print1

print0:
    
print1:

        section  .data
counter    db      32
number     dw      1235    