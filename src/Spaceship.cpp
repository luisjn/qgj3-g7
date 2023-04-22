#include "Spaceship.hpp"

Spaceship::Spaceship()
{
    Position.x = 60;
    Position.y = 15;
}

void Spaceship::Right()
{
    mSpaceship = mSpaceshipR;
    Position.x += 1;
}

void Spaceship::Left()
{
    mSpaceship = mSpaceshipL;
    Position.x -= 1;
}

void Spaceship::Up()
{
    mSpaceship = mSpaceshipU;
    Position.y -= 1;
}

void Spaceship::Down()
{
    mSpaceship = mSpaceshipD;
    Position.y += 1;
}

char Spaceship::Draw()
{
    return mSpaceship;
}
