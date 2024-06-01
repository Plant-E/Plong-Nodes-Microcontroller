#ifndef DISPLAY_H
#define DISPLAY_H

class Display {
public:
    int res_x;
    int res_y;

    int full_res_x;
    int full_res_y;

    Display();
    Display(int x, int y);

    int middleX();
    int middleY();

};

#endif
