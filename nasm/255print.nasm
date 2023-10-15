        
count:  0
Max:    255
Start:  LOAD count
        ADD 1
        STORE count
        LOAD max
        SUB 1
        STORE max
        JLZ    write:
        JZ    end
write:  LOAD count
        WRITE 0x8
        JMP start
End:    JMP end
