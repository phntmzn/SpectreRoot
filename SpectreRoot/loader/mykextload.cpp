#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "[SpectreRoot] KEXT loading is deprecated on macOS 11+." << std::endl;
    std::cout << "[SpectreRoot] Please implement a System Extension (SysExt) and use systemextensionsctl." << std::endl;
    std::cout << "[SpectreRoot] For development, enable reduced security and manage SysExts with:" << std::endl;
    std::cout << "    systemextensionsctl developer on" << std::endl;
    return 0;
}