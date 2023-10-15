      global   _main
      extern   _printf
      extern   _makeNBOC
      default  rel


          section  .text
_main:
          mov      rdi, [tester]
          push     rdi
          call     _makeNBOC
;          pop      rdi
;          xor      rdi, rdi
          lea      rdi, [format]
          call     _printf


          section .data
tester:   dd      67895632
format:   db      "%llx", 0xA, 0

          ret
