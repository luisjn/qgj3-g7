#include "Enemy.hpp"

Enemy::Enemy(float x, float y, char e)
{
    Position.x = x;
    Position.y = y;
    mEnemy = e;
    radiousImpact = ENEMY_RADIOUS_IMPACT;
}

char Enemy::Draw()
{
    return mEnemy;
}

float Enemy::PositionX()
{
    return Position.x;
}

float Enemy::PositionY()
{
    return Position.y;
}

void Enemy::FollowPlayer(Vector2 playerPos)
{
    Vector2 dir = (playerPos - Position).Normalize();
    Position.x += dir.x * 0.2;
    Position.y += dir.y * 0.2;
    if (Position.x == playerPos.x && Position.y == playerPos.y - 1)
    {
        Position.y -= 1;
    }
    if (Position.x == playerPos.x + 1 && Position.y == playerPos.y)
    {
        Position.x += 1;
    }
    if (Position.x == playerPos.x && Position.y == playerPos.y + 1)
    {
        Position.y += 1;
    }
    if (Position.x == playerPos.x - 1 && Position.y == playerPos.y)
    {
        Position.x -= 1;
    }
}

float Enemy::DistanceVector2(Vector2 v1, Vector2 v2)
{
    float d = sqrt(pow((v1.x - v2.x), 2) + pow((v1.y - v2.y), 2));
    return d;
}

bool Enemy::IsColliding(Vector2 other)
{
    float distance = DistanceVector2(other, Position); // distance circle
    if(
        distance<=radiousImpact // distance circle - Best for Enemies
        //(other.x-radiousImpact<=Position.x)&&(other.x+radiousImpact>=Position.y)&& // linear distance - Best for shoots
        //(other.y-radiousImpact<=Position.y)&&(other.y+radiousImpact>=Position.y) // linear distance - Best for shoots
        ){
        return true;
    }
    return false;
}
