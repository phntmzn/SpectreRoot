#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <path_to_kext>" << std::endl;
        return 1;
    }

    std::string kext_path = argv[1];
    std::string cmd = "sudo kextload " + kext_path;

    std::cout << "[SpectreRoot] Executing: " << cmd << std::endl;
    int result = std::system(cmd.c_str());

    if (result != 0) {
        std::cerr << "[SpectreRoot] Failed to load kext. Error code: " << result << std::endl;
        return 1;
    }

    std::cout << "[SpectreRoot] Kext loaded successfully." << std::endl;
    return 0;
}