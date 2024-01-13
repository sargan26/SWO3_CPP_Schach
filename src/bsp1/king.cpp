// king.cpp
#include "king.h"
#include <cmath>

King::King(Color color) : Chessman(color) {}

char King::getSymbol() const {
    return getColor() == Color::WHITE ? 'K' : 'k';
}

bool King::isEssential() const {
    return true;
}

bool King::canMoveTo(int startX, int startY, int endX, int endY) const {
    int xDiff = std::abs(endX - startX);
    int yDiff = std::abs(endY - startY);
    return (xDiff <= 1 && yDiff <= 1) && !(xDiff == 0 && yDiff == 0);
}
