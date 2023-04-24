#pragma once
// External libs required: -------------------------------------------------------------------------------------------

#include <iostream>

// Class declare: ----------------------------------------------------------------------------------------------------

class MenuBasic
{
private:
    char** imgASCII;
public:
    bool EndMenu();
    void Run();
    char** GetImgASCII();
    MenuBasic();
    ~MenuBasic();
};