#include <iostream>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <cmath>
#include <list>

#define Width 100
#define Height 30
#define PI 3.14159265
// x rad *180/PI = 57.29577951308

using namespace std;

struct coord
{
    int X;
    int Y;
    int x;
    int y;
};

void gotoxy(int x, int y)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void Draw(char plano[Height][Width + 1], int A, int B, char c)
{
    B = Height - 1 - B;
    if (A < 0 || B < 0 || A > Width || B >= Height)
        return;
    plano[B][A] = c;
}

void contorno(char plano[Height][Width + 1])
{
    for (int i = 0; i < Height; i++)
    {
        for (int j = 0; j < Width; j++)
        {
            if (i == 0 || i == Height - 1 || j == 0 || j == Width - 1)
            {
                Draw(plano, j, i, '+');
            }
        }
    }
}

class Nave
{
private:
    int X = Width / 2, Y = Height / 2; // coord nave
    float G = 0;                       // grados
    float x = 0, y = 0;                // aceleracion
    float vx = 0, vy = 0;              // delay
    float spd = 0;                     // velocidad

public:
    coord ret()
    {
        coord c;
        c.X = X;
        c.Y = Y;
        c.x = rotx(0);
        c.y = roty(0);

        return c;
    }

    void pintar(char plano[Height][Width + 1])
    {
        Draw(plano, X, Y, 233);
        Draw(plano, X + rotx(0), Y + roty(0), '*');
        Draw(plano, X + rotx(90), Y + roty(90), '+');
        Draw(plano, X + rotx(270), Y + roty(270), '+');
    }

    float rotx(float n)
    {
        float x = cos(((G + n) * PI) / 180);
        if (x > 0.5f && x < 1)
            x = 1;
        if (x < -0.5f && x > -1)
            x = -1;
        if (x <= 0.5f && x >= -0.5f)
            x = 0;

        return x;
    }

    float roty(float n)
    {
        float y = sin(((G + n) * PI) / 180);
        if (y > 0.5f && y < 1)
            y = 1;
        if (y < -0.5f && y > -1)
            y = -1;
        if (y <= 0.5f && y >= -0.5f)
            y = 0;

        return y;
    }

    void right()
    {
        // if (vy <= 700)
        //{
        G -= 10;
        if (G < 0)
            G = 360;
        // vy = 800.0f;
        // }
    }

    void left()
    {
        // if (vy <= 700)
        //{
        G += 10;
        if (G > 360)
            G = 0;
        // vy = 800.0f;
        // }
    }

    void acel()
    {
        // if (vx <= 500.0f)
        //{
        spd = 0.5;
        if (x + rotx(0) * spd >= -4 && x + rotx(0) * spd <= 4)
            x += rotx(0) * spd;
        if (y + roty(0) * spd >= -2 && y + roty(0) * spd <= 2)
            y += roty(0) * spd;

        //    vx = 800;
        //}
    }

    void update(float dt)
    {
        vx -= 1850.0f * dt;
        vy -= 1850.0f * dt;
        X += x;
        Y += y;

        if (X > Width - 3)
            X = 3;
        if (X < 3)
            X = Width - 3;
        if (Y > Height - 3)
            Y = 3;
        if (Y < 3)
            Y = Height - 3;
    }
};

class Bala
{
private:
    int X, Y;
    float x, y;
    float vy = 0;
    float spdx = 4;
    float spdy = 2;

public:
    Bala(coord c)
    {
        X = c.X;
        Y = c.Y;
        x = c.x;
        y = c.y;
    }

    void pintar(char plano[Height][Width + 1])
    {
        Draw(plano, X, Y, 233);
    }

    void update(float dt)
    {
        vy -= 1150.0f * dt;

        // if (vy < 0)
        //{
        X += x * spdx;
        Y += y * spdy;
        //    vy = 300.0f;
        //}
    }

    bool salir()
    {
        if (X < 3 || X > Width - 3 || Y < 3 || Y > Height - 3)
            return true;
        return false;
    }
};

int main()
{
    srand(static_cast<unsigned>(time(0)));

    char plano[Height][Width + 1];
    for (int i = 0; i < Height; i++)
        plano[i][Width] = '\n';
    plano[Height + 1][Width] = 'o';

    Nave nave;
    list<Bala *> B;
    list<Bala *>::iterator itB;

    float fps = 15.0f;
    float dt = 1.0f / fps;
    float accumulator = 0.0f;

    clock_t start = clock();

    contorno(plano);

    while (1)
    {
        clock_t end = clock();
        accumulator += float(end - start) / CLOCKS_PER_SEC;
        start = end;

        if (accumulator >= 0.2f)
            accumulator = 2.0f;

        while (accumulator >= dt)
        {
            if (GetKeyState(VK_UP) & 0x8000)
                nave.acel();
            if (GetKeyState(VK_RIGHT) & 0x8000)
                nave.right();
            if (GetKeyState(VK_LEFT) & 0x8000)
                nave.left();
            if (GetKeyState(VK_SPACE) & 0x8000)
                B.push_back(new Bala(nave.ret()));

            nave.update(dt);

            for (itB = B.begin(); itB != B.end(); itB++)
            {
                (*itB)->update(dt);
                if ((*itB)->salir())
                {
                    delete (*itB);
                    itB = B.erase(itB);
                }
            }

            accumulator -= dt;
        }

        for (int i = 1; i < Height - 1; i++)
        {
            for (int j = 1; j < Width - 1; j++)
            {
                plano[i][j] = ' ';
            }
        }

        for (itB = B.begin(); itB != B.end(); itB++)
            (*itB)->pintar(plano);

        nave.pintar(plano);

        gotoxy(0, 0);
        puts(plano[0]);
    }

    return 0;
}
