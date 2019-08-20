#include "gl.hpp"
#include <utility>

void line(int x0, int y0, int x1, int y1, TGAImage& image, TGAColor color) {
    // first set x directions to positive
    if (x0 > x1) {
        std::swap(x0, x1);
        std::swap(y0, y1);
    }
    
    // if height is greater than width, swap x and y
    bool tall = false;
    if (std::abs(y1-y0) > x1-x0) {
        std::swap(y1, x1);
        std::swap(y0, x0);
        tall = true;
    }
    // remove floating points for optimization
    int dx = x1-x0;
    int dy = y1-y0;
    int derror = std::abs(dy) * 2;
    int error = 0;
    int y = y0;
    for (int x = x0; x <= x1; x++) {
        if (tall) image.set(y, x, color);
        else image.set(x, y, color);
        error += derror;
        if (error > dx) {
            y += (dy > 0) ? 1 : -1;
            error -= dx*2;
        }
    }
}