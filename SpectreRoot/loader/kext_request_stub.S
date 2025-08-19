.section __TEXT,__text,regular,pure_instructions
.globl _kext_request_stub
.align 4

_kext_request_stub:
    # System Extensions (SysExts) do not use syscalls like KEXTs.
    # This stub exists only for compatibility with legacy interfaces.
    # For macOS 11+, register SysExts using `systemextensionsctl`.

    xor     rax, rax     # Return 0 to indicate no-op
    ret