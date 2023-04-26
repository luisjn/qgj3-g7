#include <string>
#include "Vector2.hpp"
#include "Settings.h" // General Game DEFINEs

class Enemy
{
public:
    Enemy(float x, float y, char e);

    char Draw();
    float PositionX();
    float PositionY();
    void FollowPlayer(Vector2 playerPos);
    bool IsColliding(Vector2 other);
    float radiousImpact;

    Vector2 Position;

private:
    char mEnemy;
};
