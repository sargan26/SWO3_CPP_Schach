// knight.cpp
#include "knight.h"
#include <cmath>

Knight::Knight(Color color) : Chessman(color) {}

char Knight::getSymbol() const {
    return getColor() == Color::WHITE ? 'N' : 'n';
}

bool Knight::isEssential() const {
    return false;
}

bool Knight::canMoveTo(int startX, int startY, int endX, int endY) const {
    int xDiff = std::abs(endX - startX);
    int yDiff = std::abs(endY - startY);

    // Springer-Bewegung: 2 Felder in eine Richtung und 1 Feld in die andere
    return (xDiff == 2 && yDiff == 1) || (xDiff == 1 && yDiff == 2);
}
