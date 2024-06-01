#include "Display.h"

Display::Display() {
    res_x = 0;
    res_y = 0;
}
Display::Display(int x, int y) {
    res_x = x;
    res_y = y;

    full_res_x = x * 100;
    full_res_y = y * 100;

}

int Display::middleX(){
    return full_res_x / 2;
}
int Display::middleY(){
    return full_res_y / 2;
}
