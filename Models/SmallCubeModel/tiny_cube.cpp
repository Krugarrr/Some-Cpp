#include "tiny_cube.h"

void tiny_cube::rotX() {
    auto tmp = palette[0];
    palette[0] = palette[4];
    palette[4] = palette[1];
    palette[1] = palette[5];
    palette[5] = tmp;
}

void tiny_cube::rotY() {
    auto temp = palette[2];
    palette[2] = palette[1];
    palette[1] = palette[3];
    palette[3] = palette[0];
    palette[0] = temp;
}

void tiny_cube::rotZ() {
    auto temp = palette[5];
    palette[5] = palette[3];
    palette[3] = palette[4];
    palette[4] = palette[2];
    palette[2] = temp;
}

void tiny_cube::setColor(int pos, int colour) {
    this->palette[pos] = colour;
}

unsigned char *tiny_cube::move(int i) {
    _colour[0] = palette[i] >> 16;
    _colour[1] = palette[i] >> 8;
    _colour[2] = palette[i];
    return _colour;
}

const double tiny_cube::getSize() {
    return size;
}

