#pragma once
// External libs required: -------------------------------------------------------------------------------------------

#include <iostream>
#include "Settings.h" // General Game DEFINEs

// Class declare: ----------------------------------------------------------------------------------------------------

class ImageASCII
{
private:
public:
    char** image;
    int imgLengX, imgLengY;
    std::string ToString();
    void Initialized(int dx, int dy);
    void Initialized(int dx, int dy, char initChar);
    void Draw();
    char GetChar(int x, int y);
    bool SetChar(int x, int y, char newChar);
    ImageASCII();
    ImageASCII(int dx, int dy);
    ImageASCII(int dx, int dy, char initChar);
    ~ImageASCII();
};