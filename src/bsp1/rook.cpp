// rook.cpp
#include "rook.h"
#include <cmath>

Rook::Rook(Color color) : Chessman(color) {}

char Rook::getSymbol() const {
    return getColor() == Color::WHITE ? 'R' : 'r';
}

bool Rook::isEssential() const {
    return false;
}

bool Rook::canMoveTo(int startX, int startY, int endX, int endY) const {
    // Ein Turm kann sich horizontal oder vertikal bewegen
    return startX == endX || startY == endY;
}
