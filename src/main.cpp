// #include <conio.h>
// #include <iostream>

#include "Engine.hpp"

int main()
{
    Engine e;

    bool initSucceeded = e.Initialize();

    if (initSucceeded)
    {
        e.Run();
    }

    e.Shutdown();

    // getch();

    return 0;
}
