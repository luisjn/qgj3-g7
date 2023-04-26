#include "Projectile.hpp"
#include "Settings.h"

Projectile::Projectile(int px, int py, char d)
{
    mPosition.x = px;
    mPosition.y = py;
    mDirection = d;
}

char Projectile::GetDirection()
{
    return mDirection;
}

int Projectile::GetSpeedX()
{
    return spdx;
}

int Projectile::GetSpeedY()
{
    return spdy;
}

void Projectile::Update()
{
    if (mDirection == 'u') // Up
    {
        mPosition.y -= spdy;
    }
    else if (mDirection == 'd') // Down
    {
        mPosition.y += spdy;
    }
    else if (mDirection == 'r') // Rigth
    {
        mPosition.x += spdx;
    }
    else if (mDirection == 'l') // Left
    {
        mPosition.x -= spdx;
    }
}

char Projectile::Draw()
{
    return mProyectile;
}

bool Projectile::IsOut()
{
    if (mPosition.x < Limit || mPosition.x > Width - Limit || mPosition.y < Limit || mPosition.y > Height - Limit)
        return true;
    return false;
}

float Projectile::PositionX()
{
    return mPosition.x;
}

float Projectile::PositionY()
{
    return mPosition.y;
}

Vector2 Projectile::Position()
{
    return mPosition;
}
