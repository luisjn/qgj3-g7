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
    Vector2 Position();

private:
    Vector2 mPosition;
    char mProyectile = 248;
    char mDirection;
    float spdx = 4;
    float spdy = 2;
};
