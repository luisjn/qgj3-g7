#include "Spaceship.hpp"

Spaceship::Spaceship()
{
    Position.x = 3;
    Position.y = 15;
}

void Spaceship::Right()
{
    mSpaceship = mSpaceshipR;
    if (mDirection != 'r')
        mDirection = 'r';

    Position.x += 1;
}

void Spaceship::Left()
{
    mSpaceship = mSpaceshipL;
    if (mDirection != 'l')
        mDirection = 'l';
    Position.x -= 1;
}

void Spaceship::Up()
{
    mSpaceship = mSpaceshipU;
    if (mDirection != 'u')
        mDirection = 'u';
    Position.y -= 1;
}

void Spaceship::Down()
{
    mSpaceship = mSpaceshipD;
    if (mDirection != 'd')
        mDirection = 'd';
    Position.y += 1;
}

char Spaceship::Draw()
{
    return mSpaceship;
}

char Spaceship::Direction()
{
    return mDirection;
}
