

.section __TEXT,__text,regular,pure_instructions
.globl _kext_request_stub
.align 4

_kext_request_stub:
    # Inputs:
    #   rdi = request code
    #   rsi = pointer to data
    #   rdx = data size
    #   rcx = flags
    # Output:
    #   rax = syscall return

    mov     rax, 0x2000010      # syscall number (placeholder, replace with actual)
    syscall
    ret