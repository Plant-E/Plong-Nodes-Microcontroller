#ifndef DISPLAY_H
#define DISPLAY_H

class Display {
public:
    int res_x;
    int res_y;

    int visualisation_distance;
    int max_brightness;

    int full_res_x;
    int full_res_y;

    Display();
    Display(int x, int y, int visualisation_distance, int max_brightness);

    int middleX();
    int middleY();

    void visualiseBall(int int_x, int pos_y);
    void Animation_Score();
    void Animation_Players();

};

#endif
