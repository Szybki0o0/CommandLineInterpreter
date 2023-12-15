#include "Command.h"

void PrintPath::execute() {
    fs::path currentPath = fs::current_path();
    std::cout << currentPath.string();
}

ChangeDirectory::ChangeDirectory(const fs::path& dir) : newDirectory(dir) {}

CreateDirectory::CreateDirectory(const fs::path& name) : fname(name) {}

CopyDirectory::CopyDirectory(const fs::path& sourceName, const fs::path& destinationName) : fsourceName(sourceName), fdestinationName(destinationName) {}

RemoveDirectory::RemoveDirectory(const fs::path& name) : fname(name) {}

void ChangeDirectory::setDir(fs::path dir) { newDirectory = dir;}

void CreateDirectory::setName(fs::path name) { fname = name; }

void RemoveDirectory::setName(fs::path name) { fname = name; }

void CopyDirectory::setSourceName(fs::path sourceName) { fsourceName = sourceName; }

void CopyDirectory::setDestinationName(fs::path destinationName) { fdestinationName = destinationName; }

void ChangeDirectory::execute() {
    if (fs::exists(newDirectory) && fs::is_directory(newDirectory)) {
        fs::current_path(newDirectory);
    }
    else {
        std::cout << "The system cannot find the file specified.." << std::endl;
    }
}

void PrintDirectory::execute() {
    fs::path currentPath = fs::current_path();
    for (const auto& entry : fs::directory_iterator(currentPath))
        std::cout << entry.path().filename().string() << std::endl;
}

void CreateDirectory::execute() {
    fs::create_directory(fname);
}

void CopyDirectory::execute() {
    if (fs::exists(fdestinationName) && is_directory(fdestinationName))
    {
        if (fs::exists(fsourceName) && fs::is_regular_file(fsourceName) ) {
            fs::copy_file(fsourceName, fdestinationName);
        }
        else if (fs::exists(fsourceName) && fs::is_directory(fsourceName))
        {
            fs::copy(fsourceName, fdestinationName);
        }  
        else
        {
            //std::cout << "The system cannot find the file specified." << std::endl;
            std::cout << "fasfsa";
        }
    }
    else
    {
        //std::cout << "The system cannot find the file specified." << std::endl;
    }
}

void RemoveDirectory::execute() {
    fs::remove_all(fname);
}