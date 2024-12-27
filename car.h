#ifndef CAR_H
#define CAR_H

class car {
  private:
    int location_x;
    int location_y;
    int squareSize_width;
    int squareSize_height;
    int color;
    int direction;
    int num;

  public:
    car(int location_x, int location_y, int squareSize_width,
        int squareSize_height, int color, int direction, int num);
    ~car();
    car(const car &copy);
    car operator=(const car &copy);

    int getLocation_x();
    int getLocation_y();
    int getSquareSize_width();
    int getSquareSize_height();
    int getSquareSize_color();
    int getSquareSize_direction();

    void Draw_Object(void);
    void Car_Move(void);
  };

#endif