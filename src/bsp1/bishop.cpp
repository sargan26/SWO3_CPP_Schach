// bishop.cpp
#include "bishop.h"
#include <cmath>

Bishop::Bishop(Color color) : Chessman(color) {}

char Bishop::getSymbol() const {
    return getColor() == Color::WHITE ? 'B' : 'b';
}

bool Bishop::isEssential() const {
    return false;
}

bool Bishop::canMoveTo(int startX, int startY, int endX, int endY) const {
    int xDiff = std::abs(endX - startX);
    int yDiff = std::abs(endY - startY);

    // Ein Läufer kann sich nur diagonal bewegen
    return xDiff == yDiff;
}
