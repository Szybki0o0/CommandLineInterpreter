#include "Command.h"

void PrintPath::execute() {
    fs::path currentPath = fs::current_path();
    std::cout << currentPath.string();
}

ChangeDirectory::ChangeDirectory(const fs::path& dir) : newDirectory(dir) {}

CreateDirectory::CreateDirectory(const fs::path& name) : fname(name) {}

CopyFile::CopyFile(const fs::path& sourceName, const fs::path& destinationName) : fsourceName(sourceName), fdestinationName(destinationName) {}

RemoveDirectory::RemoveDirectory(const fs::path& name) : fname(name) {}

Help::Help(const fs::path& name) : fname(name) {}

void ChangeDirectory::setDir(fs::path dir) { newDirectory = dir;}

void CreateDirectory::setName(fs::path name) { fname = name; }

void CopyFile::setSourceName(fs::path sourceName) { fsourceName = sourceName; }

void CopyFile::setDestinationName(fs::path destinationName) { fdestinationName = destinationName; }

void RemoveDirectory::setName(fs::path name) { fname = name; }

void Help::setName(fs::path name) { fname = name; }

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

void CopyFile::execute() {
    if (fs::exists(fdestinationName.string() + R"(\)" + fsourceName.filename().string()) && is_directory(fdestinationName))
    {
        std::cout << "Such a file already exists in this directory" << std::endl;
    }
    else if (fs::exists(fdestinationName) && is_directory(fdestinationName))
    {
        if (fs::exists(fsourceName) && fs::is_regular_file(fsourceName) ) {
            fs::copy(fsourceName, fdestinationName);
        }  
        else
        {
            std::cout << "The system cannot find the file specified." << std::endl;
        }
    }
}

void RemoveDirectory::execute() {
    fs::remove_all(fname);
}

void Help::execute() {
    if (fname.empty())
    {
        std::cout << "For more information on a specific command, type HELP command-name\n"
            "CD       Displays the name of or changes the current directory.\n"
            "MKDIR    Creates a directory.\n"
            "RMDIR    Removes a directory.\n"
            "DIR      Displays a list of files and subdirectories in a directory.\n"
            "COPY     Copies one or more files to another location.\n"
            "HELP     Provides Help information for Windows commands." << std::endl;
    }
    else if (fname == "cd")
    {
        std::cout << "Displays the name of or changes the current directory.\n\n"
            "CD [drive:][path]" << std::endl;
    }
    else if (fname == "dir")
    {
        std::cout << "Displays a list of files and subdirectories in a directory.\n";
    }
    else if (fname == "mkdir")
    {
        std::cout << "Creates a directory.\n\n"
            "MKDIR[drive:]path" << std::endl;
    }
    else if (fname == "rmdir")
    {
        std::cout << "Removes (deletes) a directory.\n\n"
            "RMDIR [drive:]path" << std::endl;
    }
    else if (fname == "copy")
    {
        std::cout << "Copies one or more files to another location.\n\n"
            "COPY [source] [destination]\n\n"
            "source       Specifies the file or files to be copied.\n"
            "destination  Specifies the directory and/or filename for the new file(s)." << std::endl;
    }
    else if (fname == "help")
    {
        std::cout << "Provides help information for Windows commands.\n\n"
            "HELP [command]\n\n"
            "   command - displays help information on that command." << std::endl;
    }
    else
    {
        std::cout << "This command is not supported by the help utility.\n";
    }
}