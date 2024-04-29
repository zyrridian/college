#ifndef COORDINATE_H
#define COORDINATE_H

struct Titik {
    int x;
    int y;
};

void geserX(Titik &titik, int x) {
    titik.x += x;
}

void geserY(Titik &titik, int y) {
    titik.y += y;
}

void geserXY(Titik &titik, int x, int y) {
    titik.x += x;
    titik.y += y;
}

#endif