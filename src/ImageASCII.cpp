// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------

// Class declare and external libs required: -------------------------------------------------------------------------

#include "ImageASCII.hpp"

// Constructor and destructor: ---------------------------------------------------------------------------------------

ImageASCII::ImageASCII()
{
    // Initialize
}

ImageASCII::ImageASCII(int dx, int dy)
{
    imgLengX=dx;
    imgLengY=dy;
    Initialized(dx,dy);
}

ImageASCII::ImageASCII(int dx, int dy, char initChar)
{
    imgLengX=dx;
    imgLengY=dy;
    Initialized(dx, dy, initChar);
}

ImageASCII::~ImageASCII()
{
    for(int y=0;y<imgLengY;y++)
    {
        delete []image[y];
    }
    delete []image;
}

// Voids: ------------------------------------------------------------------------------------------------------------

void ImageASCII::Initialized(int dx, int dy)
{
    imgLengX=dx;
    imgLengY=dy;
    image=new char*[imgLengY];
    for(int y=0;y<imgLengY;y++)
    {
        image[y]=new char[imgLengX];
        for(int x=0;x<imgLengX;x++)
        {
            image[y][x]='0';
        }
    }
}

void ImageASCII::Initialized(int dx, int dy,char initChar)
{
    imgLengX=dx;
    imgLengY=dy;
    image=new char*[imgLengX];
    for(int y=0;y<imgLengY;y++)
    {
        image[y]=new char[imgLengX];
        for(int x=0;x<imgLengX;x++)
        {
            image[y][x]=initChar;
        }
    }
}

void ImageASCII::Draw()
{
    for(int y=0;y<imgLengY;y++)
    {
        for(int x=0;x<imgLengX;x++)
        {
            std::cout << image[y][x]; 
	    }
        std::cout << "\n";
    }   
}


std::string ImageASCII::ToString()
{
    std::string result="";
    for(int y=0;y<imgLengY;y++)
    {
        for(int x=0;x<imgLengX;x++)
        {
            result = result + image[y][x]; 
	    }
        result = result + "\n";
    }   
    return result;
}

char ImageASCII::GetChar(int x, int y)
{
    return image[x][y];
}

bool ImageASCII::SetChar(int x, int y, char newChar)
{
    bool result = false;
    if((x>=0)&&(x<imgLengX))
    {
        if((x>=0)&&(x<imgLengX))
        {
            std::strncpy(&image[y][x], &newChar, 1);
            result=true;
        }
    }
    return result;
}

// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------
