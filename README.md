# SpectreRoot

**SpectreRoot** is a modular macOS rootkit framework written in C++ and Objective-C++ targeting pre-SIP (System Integrity Protection) systems. It demonstrates practical techniques for stealth, persistence, and privilege escalation using kernel and userland components.

---

## 🔧 Features

- **Direct Kernel Object Manipulation (DKOM):** Hide processes by unlinking kernel structures.
- **Privilege Escalation:** Gain root via setuid, host port abuse, or legacy macOS APIs.
- **Launchd Job Tampering:** Unlink persistent agents and daemons from launchd memory.
- **Kernel Memory Access:** Read/write kernel space with Mach APIs.
- **Custom KEXT Loader:** Load unsigned kernel extensions using syscall stubs or `kextload`.
- **Stealth Techniques:** Dylib injection, log scrubbing, and file hiding utilities.

---

## 📁 Project Layout

```
SpectreRoot/
├── build/                  # Output KEXTs and compiled binaries
├── dkom/                   # Process hiding via kernel list manipulation
├── docs/                   # Internal documentation and architecture
├── kernel_access/          # task ports and remote memory primitives
├── kext/                   # KEXT source and Makefile
├── launchd/                # launchd job unlinking logic
├── loader/                 # Userland loader and syscall trampolines
├── privilege/              # Escalation logic and host port tools
├── root_escalation/        # Authorization-based root gain
├── stealth/                # File concealment and log cleanup
├── utils/                  # Dylib injection and kernel symbol resolution
└── README.md               # You are here
```

---

## 💻 Requirements

- macOS 10.9–10.14 (x86_64, SIP disabled)
- Xcode CLI tools
- Root access
- `task_for_pid` entitlement or AMFI bypass
- Knowledge of Mach APIs and macOS internals

---

## ⚠️ Disclaimer

This tool is provided for educational use only. Do **not** deploy it on any system without explicit permission. The author disclaims all liability for misuse or damage resulting from this project.

---

## 📚 References

- Jonathan Levin – *OS X and iOS Internals*
- Apple's XNU Source
- Research on DKOM and launchd persistence
