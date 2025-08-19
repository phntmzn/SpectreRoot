

#include <iostream>
#include <unistd.h>
#include <string>

// Attempt to hide a file by renaming it to a dotfile
bool hide_file(const std::string& path) {
    std::string hidden_path = path;
    size_t last_slash = path.find_last_of('/');
    if (last_slash != std::string::npos && last_slash + 1 < path.size()) {
        hidden_path = path.substr(0, last_slash + 1) + "." + path.substr(last_slash + 1);
    } else {
        hidden_path = "." + path;
    }

    if (rename(path.c_str(), hidden_path.c_str()) == 0) {
        std::cout << "[SpectreRoot] File hidden: " << hidden_path << std::endl;
        return true;
    } else {
        perror("[SpectreRoot] Failed to hide file");
        return false;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <file_path>" << std::endl;
        return 1;
    }

    hide_file(argv[1]);
    return 0;
}