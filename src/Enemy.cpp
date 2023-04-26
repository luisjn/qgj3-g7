#include "Enemy.hpp"

Enemy::Enemy(float x, float y, std::string e)
{
    Position.x = x;
    Position.y = y;
    mEnemy = e;
}

std::string Enemy::Draw()
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
    Position.x += dir.x * 0.1;
    Position.y += dir.y * 0.1;
}
