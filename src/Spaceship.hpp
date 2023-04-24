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
    char mSpaceship = 30;

    Vector2 Position;

private:
    char mSpaceshipR = 16;
    char mSpaceshipL = 17;
    char mSpaceshipU = 30;
    char mSpaceshipD = 31;
};
