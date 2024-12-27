#ifndef FROG_H
#define FROG_H

class frog
{   
    private:
        int location_x;
        int location_y;
        int squareSize_width;
        int squareSize_height;
        int color;
        int direction;

    public:
        frog(int location_x, int location_y, int squareSize_width, int squareSize_height, int color, int direction);
        ~frog();
        frog(const frog &copy);
        frog operator=(const frog &copy);

        int getLocation_x();
        int getLocation_y();
        int getSquareSize_width();
        int getSquareSize_height();
        int getSquareSize_color();
        int getSquareSize_direction();

};

#endif