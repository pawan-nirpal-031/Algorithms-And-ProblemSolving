

global _start
_start:
    mov eax,1
    mov ebx,42
    int 0x80  # system call interupt(int) 0x80 is interupt for sys call 
    
