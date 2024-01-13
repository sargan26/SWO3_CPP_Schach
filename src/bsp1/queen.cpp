// queen.cpp
#include "queen.h"
#include <cmath>

Queen::Queen(Color color) : Chessman(color) {}

char Queen::getSymbol() const {
    return getColor() == Color::WHITE ? 'Q' : 'q';
}

bool Queen::isEssential() const {
    return false;
}

bool Queen::canMoveTo(int startX, int startY, int endX, int endY) const {
    int xDiff = std::abs(endX - startX);
    int yDiff = std::abs(endY - startY);

    // Eine Dame kann sich horizontal, vertikal und diagonal bewegen
    return xDiff == yDiff || startX == endX || startY == endY;
}
