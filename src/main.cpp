#include "Engine.hpp"

int main()
{
    Engine* e = new Engine();

    bool initSucceeded = e->Initialize();

    if (initSucceeded)
    {
        e->Run();
    }

    e->Shutdown();

    delete e;

    return 0;
}

