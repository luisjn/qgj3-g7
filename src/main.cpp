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

    return 0;
}
