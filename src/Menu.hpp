#pragma once
// External libs required: -------------------------------------------------------------------------------------------

#include <iostream>

// Class declare: ----------------------------------------------------------------------------------------------------

class MenuBasic
{
private:
    char** imgASCII;
public:
    void Run();
    char** GetImgASCII();
    MenuBasic();
    ~MenuBasic();
};