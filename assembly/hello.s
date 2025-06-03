// hello.s - simple ARM64 assembly program to print "Hello, world!\n"

.section __TEXT,__text,regular,pure_instructions
.globl _main
.extern _printf

_main:
    // Load the address of the format string into x0 (1st argument)
    adrp x0, fmt@PAGE
    add  x0, x0, fmt@PAGEOFF

    // Call printf
    bl  _printf

    // Return 0
    mov x0, #0
    ret

.section __TEXT,__cstring,cstring_literals
fmt:
    .asciz "Hello, world!\n"
