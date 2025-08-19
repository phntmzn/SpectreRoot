#ifndef SPECTREROOT_LAUNCHD_MEM_HPP
#define SPECTREROOT_LAUNCHD_MEM_HPP

#include <mach/mach.h>
#include <string>
#include <vector>

// Represents a found job label and its address
struct LaunchdJob {
    std::string label;
    uintptr_t address;
};

// Parses launchd's in-memory job dictionary to find hidden or rogue jobs
std::vector<LaunchdJob> find_launchd_jobs(mach_port_t task);

// Unlinks a job from launchd's internal linked list
bool unlink_launchd_job(mach_port_t task, const std::string& label);

#endif // SPECTREROOT_LAUNCHD_MEM_HPP