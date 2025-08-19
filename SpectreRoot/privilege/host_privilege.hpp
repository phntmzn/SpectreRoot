

#ifndef SPECTREROOT_HOST_PRIVILEGE_HPP
#define SPECTREROOT_HOST_PRIVILEGE_HPP

#include <mach/mach.h>

// Retrieve the special host privilege port
mach_port_t get_host_priv_port();

// Replace current task's special ports with privileged ones
bool swap_host_priv_port(task_t target_task, mach_port_t priv_port);

#endif // SPECTREROOT_HOST_PRIVILEGE_HPP