#include "car.h"
#include "device_driver.h"
#include "lcd.h"

car ::car(int location_x, int location_y, int squareSize_width, int squareSize_height, int color, int direction, int num)
{
    this ->location_x = location_x;
    this ->location_y = location_y;
    this ->squareSize_height = squareSize_height;
    this ->squareSize_width = squareSize_width;
    this ->color = color;
    this ->direction = direction;
    this ->num = num;
}
       
car ::~car()
{

}
       
car ::car(const car &copy) // 복사
{
    if(&copy != this){
        
    this -> location_x = copy.location_x;
    this -> location_y = copy.location_y;
    this -> squareSize_height = copy.squareSize_height;
    this -> squareSize_width = copy.squareSize_width;
    this -> color = copy.color;
    this -> direction = copy.direction;
    this -> num = copy.num;
    }

}   


car car::operator=(const car &copy)
{
    if(&copy != this){
        
    this -> location_x = copy.location_x;
    this -> location_y = copy.location_y;
    this -> squareSize_height = copy.squareSize_height;
    this -> squareSize_width = copy.squareSize_width;
    this -> color = copy.color;
    this -> direction = copy.direction;
    this -> num = copy.num;
    }
    return (*this);
}

int car::getLocation_x()
{
    return (this->location_x);
}

int car::getLocation_y()
{
    return (this->location_y);
}

int car::getSquareSize_width()
{
    return (this->squareSize_width);
}

int car::getSquareSize_height()
{
    return (this->squareSize_height);
}

int car::getSquareSize_color()
{
    return (this->color);
}

int car::getSquareSize_direction()
{
    return (this->direction);
}

void car::Draw_Object() 
{
    Lcd_Draw_Box(this->location_x, this->location_y, this->squareSize_width, this->squareSize_height, colors[this->color]);
}

void car::Car_Move(void) 
{
    this->location_x += CAR_STEP * this->direction;
    if ((this->location_x + this->squareSize_width >= X_MAX) || (this->location_x <= X_MIN))
        this->direction = -this->direction;
}
