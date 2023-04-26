#include "Vector2.hpp"

class Spaceship
{
public:
    Spaceship();

    void Right();
    void Left();
    void Up();
    void Down();
    char Draw();
    char Direction();

    Vector2 Position;

private:
    char mSpaceship = 30;
    char mDirection = 'r';
    char mSpaceshipR = 16;
    char mSpaceshipL = 17;
    char mSpaceshipU = 30;
    char mSpaceshipD = 31;
};
