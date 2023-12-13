#include "Command.h"

void PrintPath::execute() {
    fs::path currentPath = fs::current_path();
    std::cout << currentPath.string();
}

ChangeDirectory::ChangeDirectory(const fs::path& dir) : newDirectory(dir) {}

void ChangeDirectory::setDir(fs::path dir) { newDirectory = dir;}

void ChangeDirectory::execute() {
    if (fs::exists(newDirectory) && fs::is_directory(newDirectory)) {
        fs::current_path(newDirectory);
    }
    else {
        std::cout << "The specified directory does not exist or is not a directory." << std::endl;
    }
}