#include "Projectile.hpp"
#include "Settings.h"

Projectile::Projectile(int px, int py, char d)
{
    Position.x = px;
    Position.y = py;
    mDirection = d;
}

void Projectile::Update()
{
    if (mDirection == 'u')
    {
        Position.y -= spdy;
    }
    else if (mDirection == 'd')
    {
        Position.y += spdy;
    }
    else if (mDirection == 'r')
    {
        Position.x += spdx;
    }
    else if (mDirection == 'l')
    {
        Position.x -= spdx;
    }
}

char Projectile::Draw()
{
    return mProyectile;
}

bool Projectile::IsOut()
{
    if (Position.x < Limit || Position.x > Width - Limit || Position.y < Limit || Position.y > Height - Limit)
        return true;
    return false;
}

float Projectile::PositionX()
{
    return Position.x;
}

float Projectile::PositionY()
{
    return Position.y;
}
