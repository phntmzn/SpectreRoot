

#include <mach/mach.h>
#include <iostream>
#include <unistd.h>

// Acquire the Mach task port for the target PID using task_for_pid.
// This function is for controlled testing environments and logs the outcome.
mach_port_t get_task_port(pid_t pid) {
    mach_port_t task = MACH_PORT_NULL;
    kern_return_t kr = task_for_pid(mach_task_self(), pid, &task);

    if (kr != KERN_SUCCESS) {
        std::cerr << "[SpectreRoot] Failed to get task port for PID " << pid
                  << ": " << mach_error_string(kr) << std::endl;
        return MACH_PORT_NULL;
    }

    std::cout << "[SpectreRoot] Obtained task port for PID " << pid << ": 0x"
              << std::hex << task << std::dec << std::endl;
    return task;
}