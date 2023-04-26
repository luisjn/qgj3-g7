#include <string>
#include "Vector2.hpp"

class Enemy
{
public:
    Enemy(float x, float y);
    Enemy(float x, float y, std::string e);

    std::string Draw();
    float PositionX();
    float PositionY();
    void FollowPlayer(Vector2 playerPos);

    Vector2 Position;

private:
    std::string mEnemy;
};
