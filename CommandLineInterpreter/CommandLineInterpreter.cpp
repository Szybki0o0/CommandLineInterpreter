#include <iostream>
#include <filesystem>
#include "Command.h"
#include "Parser.h"

using namespace std;
namespace fs = std::filesystem;

int main()
{


    cout << "Mikroopro Okna [Version 1.2137.420]" << endl;
    cout << "(c) Bill Gates Corporation. All rights reserved." << "\n\n";
    fs::path dP = "C:\\Users\\konio";
    fs::path test = "C:\\Games";
    PrintPath p;
    ChangeDirectory c(dP);
    Parser par("test"); 
    c.execute();
    //string test;
    string comm = par.getCommand();
    string currentCommand;
    //cout << par.getKeyWord(comm);
    //cout << par.isACommand("cdasda");
    for (;;)
    {
        p.execute();
        cout << ">";
        getline(cin, currentCommand);
        //par.setCommand(currentCommand);
        string keyWord = par.getKeyWord(currentCommand);
        fs::path content = par.getContent(currentCommand);
        //cout << par.getCommand();
        if (par.isACommand(keyWord))
        {          
            if (keyWord == "cd") { 
                c.setDir(content);
                c.execute(); 
            }
        }
        else if (!currentCommand.empty())
        {
             cout << "'" << par.getKeyWord(currentCommand) << "' is not recognized as an internal or external command,\n operable program or batch file.\n";       
        }
    }
    //cout << par.getContent("cd jdjdjd");
    //cout << par.isACommand("cda jdjdjd");
}
