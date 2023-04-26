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
}

float Enemy::DistanceVector2(Vector2 v1, Vector2 v2)
{
    float d = sqrt(pow((v1.x - v2.x), 2) + pow((v1.y - v2.y), 2));
    return d;
}

bool Enemy::IsColliding(Vector2 other)
{
    float distance = DistanceVector2(other, Position); // distance circle
    if (distance <= radiousImpact)
    {
        return true;
    }
    return false;
}

bool Enemy::IsColliding(Vector2 other, char mDirection, int spdx, int spdy)
{
    int other_x = static_cast<int>(other.x);
    int other_y = static_cast<int>(other.y);
    int pos_x = static_cast<int>(Position.x);
    int pos_y = static_cast<int>(Position.y);

    if (mDirection == 'u') // Up
    {
        //mPosition.y -= spdy;
        if ((pos_x==other_x))
        {
            if ((other_y-spdy<=pos_y) && (pos_y<=other_y))
            {
                return true;
            }
        }
    }
    else if (mDirection == 'd') // Down
    {
        //mPosition.y += spdy;
        if ((pos_x==other_x))
        {
            if ((other_y<=pos_y) && (pos_y<=other_y+spdy))
            {
                return true;
            }
        }
    }
    else if (mDirection == 'r') // Rigth
    {
        //mPosition.x += spdx;
        if ((pos_y==other_y))
        {
            if ((other_x<=pos_x) && (pos_x<=other_x+spdx))
            {
                return true;
            }
        }
    }
    else if (mDirection == 'l') // Left
    {
        //mPosition.x -= spdx;
         if ((pos_y==other_y))
        {
            if ((other_x-spdx<=pos_x) && (pos_x<=other_x))
            {
                return true;
            }
        }
   }
/*
(other.x-radiousImpact<=Position.x)&&(other.x+radiousImpact>=Position.y)&& // linear distance - Best for shoots
(other.y-radiousImpact<=Position.y)&&(other.y+radiousImpact>=Position.y) // linear distance - Best for shoots

    float distance = DistanceVector2(other, Position); // distance circle
*/
    
    return false;
}
