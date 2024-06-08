#ifndef DISPLAY_H
#define DISPLAY_H

class Display {
public:
    int res_x;
    int res_y;

    int visualisation_distance;
    int max_brightness;

    Display(int x, int y, int visualisation_distance, int max_brightness);

    int fullResX();
    int fullResY();

    int middleX();
    int middleY();

    void visualiseBall(int int_x, int pos_y);

    void debug();

};

#endif
