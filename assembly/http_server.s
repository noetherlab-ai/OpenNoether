// http_server.s - Minimal TCP HTTP server in ARM64 assembly

.section __TEXT,__text,regular,pure_instructions
.globl _main
.extern _exit
.extern _write
.extern _close

_main:
    // Step 1: Create socket (syscall: socket)
    mov x0, #2          // AF_INET
    mov x1, #1          // SOCK_STREAM
    mov x2, #0          // Protocol 0
    mov x16, #97        // syscall number: socket
    svc #0
    mov x19, x0         // save socket fd in x19

    // Add the rest: bind, listen, accept, write...

    // Exit cleanly
    mov x0, #0
    mov x16, #1         // syscall: exit
    svc #0

