#pragma once

#include <iostream>
#include <filesystem>
//#include <string>

//using namespace std;
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

class PrintDirectory : public ICommand {
public:
    void execute() override;
};

class CreateDirectory : public ICommand {
private:
    fs::path fname;
public:
    CreateDirectory(const fs::path& name);

    void setName(fs::path name);

    void execute() override;
};

class CopyDirectory : public ICommand {
private:
    fs::path fsourceName, fdestinationName;
public:
    CopyDirectory(const fs::path& sourceName, const fs::path& destinationName);

    void setSourceName(fs::path sourceName);

    void setDestinationName(fs::path destinationeName);

    void execute() override;
};

class RemoveDirectory : public ICommand {
private:
    fs::path fname;
public:
    RemoveDirectory(const fs::path& name);

    void setName(fs::path name);

    void execute() override;
};