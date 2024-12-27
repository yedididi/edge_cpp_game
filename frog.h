#ifndef FROG_H
#define FROG_H

#ifdef __cplusplus
 extern "C" {
#endif 

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
        // ~frog();
        frog(const frog &copy);
        // frog operator=(const frog &copy);

        int getLocation_x();
        int getLocation_y();
        int getSquareSize_width();
        int getSquareSize_height();
        int getColor();
        int getDirection();

        void setColor(int color);
        void setDirection(int direction);

        void Draw_Object();
        void Frog_Move(int k);

        void k0(void);
        void k1(void);
        void k2(void);
        void k3(void);
};

#ifdef __cplusplus
}
#endif

#endif