// chessman.cpp
#include "chessman.h"

Chessman::Chessman(Color color) : color(color) {}

//Chessman::~Chessman() {}

Color Chessman::getColor() const { return color; }