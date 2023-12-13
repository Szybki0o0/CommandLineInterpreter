#pragma once

#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

class ICommand {
public:
    virtual ~ICommand() {}
    virtual void execute() = 0;
};

class PrintPath : public ICommand {
public:
    void execute() override;
};

class ChangeDirectory : public ICommand {
private:
    fs::path newDirectory;

public:
    ChangeDirectory(const fs::path& dir);

    void setDir(fs::path dir);

    void execute() override;
};