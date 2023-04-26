#include <string>
#include "Vector2.hpp"

class Enemy
{
public:
    Enemy(float x, float y, char e);

    char Draw();
    float PositionX();
    float PositionY();
    void FollowPlayer(Vector2 playerPos);
    bool IsColliding(Vector2 other);

    Vector2 Position;

private:
    char mEnemy;
};
