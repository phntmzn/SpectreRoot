


#import <Foundation/Foundation.h>
#import <mach/mach.h>
#import <mach/mach_vm.h>
#import <unistd.h>
#import <string.h>
#import <dlfcn.h>
#import <sys/types.h>
#import <sys/stat.h>
#import <fcntl.h>

bool inject_dylib(pid_t pid, const char* dylib_path) {
    task_t remoteTask;
    kern_return_t kr = task_for_pid(mach_task_self(), pid, &remoteTask);
    if (kr != KERN_SUCCESS) {
        NSLog(@"[SpectreRoot] task_for_pid failed: %s", mach_error_string(kr));
        return false;
    }

    mach_vm_address_t remote_path_addr = 0;
    size_t path_len = strlen(dylib_path) + 1;

    kr = mach_vm_allocate(remoteTask, &remote_path_addr, path_len, VM_FLAGS_ANYWHERE);
    if (kr != KERN_SUCCESS) {
        NSLog(@"[SpectreRoot] mach_vm_allocate failed: %s", mach_error_string(kr));
        return false;
    }

    kr = mach_vm_write(remoteTask, remote_path_addr, (vm_offset_t)dylib_path, (mach_msg_type_number_t)path_len);
    if (kr != KERN_SUCCESS) {
        NSLog(@"[SpectreRoot] mach_vm_write failed: %s", mach_error_string(kr));
        return false;
    }

    NSLog(@"[SpectreRoot] Injected dylib path to remote address: 0x%llx", remote_path_addr);

    // At this point you would create a remote thread to call dlopen()
    // On macOS, this typically requires a trampoline + assembly stub

    NSLog(@"[SpectreRoot] Stub: dylib path written, no thread created.");
    return true;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        NSLog(@"Usage: %s <pid> <dylib_path>", argv[0]);
        return 1;
    }

    pid_t pid = atoi(argv[1]);
    const char* dylib_path = argv[2];

    if (!inject_dylib(pid, dylib_path)) {
        NSLog(@"[SpectreRoot] Injection failed.");
        return 1;
    }

    NSLog(@"[SpectreRoot] Injection succeeded.");
    return 0;
}