#include <iostream>
#include <filesystem>
#include "Command.h"

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
    c.execute();

    fs::path currentPath ;
    for (;;)
    {
        p.execute();
        cout << ">";
        cin >> currentPath;
    }
}
