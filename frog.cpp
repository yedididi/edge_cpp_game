#include "device_driver.h"

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
int frog::getColor()
{
    return (this->color);
}
int frog::getDirection()
{
    return (this->direction);
}


void frog::setColor(int color)
{
    this->color = color;
}

void frog::setDirection(int direction)
{
    this->direction = direction;
}

void frog::Draw_Object()
{
    Lcd_Draw_Box(this->location_x, this->location_y, this->squareSize_width, this->squareSize_height, colors[this->color]);
}

 void frog::k0(void)
{
	if(this->location_y > Y_MIN) this->location_y -= FROG_STEP;
}

 void frog::k1(void)
{
	if(this->location_y + this->squareSize_height < Y_MAX) this->location_y += FROG_STEP;
}

 void frog::k2(void)
{
	if(this->location_x > X_MIN) this->location_x -= FROG_STEP;
}

 void frog::k3(void)
{
	if(this->location_x + this->squareSize_width < X_MAX) this->location_x += FROG_STEP;
}


// void frog::Frog_Move(int k)
// {
//     // UP(0), DOWN(1), LEFT(2), RIGHT(3)
// 	void (frog::*key_func[])(void) = {k0, k1, k2, k3};
// 	if(k <= 3) key_func[k]();
// }

void frog::Frog_Move(int k)
{
    void (frog::*key_func[])(void) = {&frog::k0, &frog::k1, &frog::k2, &frog::k3};

    if (k >= 0 && k <= 3)
    {
        (this->*key_func[k])();
    }
}
