#include "frog.h"

frog::frog(int location_x, int location_y, int squareSize_width, int squareSize_height, int color, int direction)
{
    this->location_x = location_x;
    this->location_y = location_y;
    this->squareSize_width = squareSize_width;
    this->squareSize_height = squareSize_height;
    this->color = color;
    this->direction = direction;
}

frog::~frog()
{
}

frog::frog(const frog &copy)
{
    if (&copy != this)
    {
        this->location_x = copy.location_x;
        this->location_y = copy.location_y;
        this->squareSize_width = copy.squareSize_width;
        this->squareSize_height = copy.squareSize_height;
        this->color = copy.color;
        this->direction = copy.direction;
    }
}

frog frog::operator=(const frog &copy)
{
    if (&copy != this)
    {
        this->location_x = copy.location_x;
        this->location_y = copy.location_y;
        this->squareSize_width = copy.squareSize_width;
        this->squareSize_height = copy.squareSize_height;
        this->color = copy.color;
        this->direction = copy.direction;
    }
    return (*this);
    
}

int frog::getLocation_x()
{
    return (this->location_x);
}
int frog::getLocation_y()
{
    return (this->location_y);
}

int frog::getSquareSize_width()
{
    return (this->squareSize_width);
}
int frog::getSquareSize_height()
{
    return (this->squareSize_height);
}
int frog::getSquareSize_color()
{
    return (this->color);
}
int frog::getSquareSize_direction()
{
    return (this->direction);
}