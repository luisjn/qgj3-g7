#include "Enemy.hpp"

Enemy::Enemy(float x, float y, char e)
{
    Position.x = x;
    Position.y = y;
    mEnemy = e;
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

bool Enemy::IsColliding(Vector2 other)
{
    // if (Position.x == other.x && Position.y == other.y)
    if (Position == other)
    {
        return true;
    }
    return false;
}
