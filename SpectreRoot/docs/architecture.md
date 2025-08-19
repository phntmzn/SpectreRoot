


# SpectreRoot Architecture

SpectreRoot is a modular C++ rootkit framework for macOS that demonstrates techniques in stealth, persistence, and privilege escalation. It is organized into discrete components targeting userland, kernel, and launchd manipulation on pre-SIP systems.

---

## 🧩 Components Overview

### 1. DKOM (Direct Kernel Object Manipulation)
- Hides processes by unlinking them from `allproc` and PID hash lists.
- Implemented in `dkom/hide_process.cpp`.

### 2. Privilege Escalation
- Includes userland EUID swaps (`setuid(0)`) and deprecated APIs like `AuthorizationExecuteWithPrivileges`.
- Kernel-level root escalation supported via host port spoofing.

### 3. Kernel Memory Access
- Provides read/write primitives to access kernel space via Mach APIs.
- Used for symbol resolution, credential manipulation, and code patching.

### 4. Launchd Manipulation
- Unlinks jobs and daemons from launchd’s internal table in memory.
- Helps conceal persistence mechanisms.

### 5. KEXT Loader
- Loads unsigned kernel extensions manually using syscall stubs or legacy interfaces.
- Fallback to userland `kextload` if necessary.

### 6. Stealth
- Includes:
  - File hiding (dot-prefix rename or vnode tampering).
  - Log scrubbing (`log erase`, rm logs).
  - Dylib injection via `mach_vm_write`.

---

## 🔗 Interactions

- `loader/mykextload.cpp` → Calls into `kext_request_stub.S` or external load methods.
- `kernel_access/mem_rw.cpp` → Supports `dkom`, `launchd`, and privilege modules.
- `utils/symbols.py` → Parses Mach-O symbol maps to resolve kernel function addresses.
- `stealth/hide_fs.cpp` + `clean_logs.sh` → Help cover tracks post-installation.

---

## ⚠️ Assumptions

- SIP (System Integrity Protection) must be disabled.
- Root or `task_for_pid()` entitlement is assumed.
- Tested on macOS 10.9–10.14 (non-arm64).

---

## 🧪 Notes for Research

- This project is intended for education, red team development, and malware analysis defense.
- Avoid deploying on live systems unless in isolated lab environments.