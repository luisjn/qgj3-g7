#include "Vector2.hpp"

class Projectile
{
public:
    Projectile(int px, int py, char d);
    void Update();
    char Draw();
    bool IsOut();
    float PositionX();
    float PositionY();

private:
    Vector2 Position;
    char mProyectile = 248;
    char mDirection;
    float spdx = 4;
    float spdy = 2;
};
