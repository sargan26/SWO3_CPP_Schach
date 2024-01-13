// pawn.cpp
#include "pawn.h"
#include <cmath>

Pawn::Pawn(Color color) : Chessman(color) {}

char Pawn::getSymbol() const {
    return getColor() == Color::WHITE ? 'P' : 'p';
}

bool Pawn::isEssential() const {
    return false;
}

bool Pawn::canMoveTo(int startX, int startY, int endX, int endY) const {
    int forward = getColor() == Color::WHITE ? 1 : -1;
    int startRow = getColor() == Color::WHITE ? 1 : 6;
    
    if (startX == endX) {
        if (startY == startRow && endY - startY == 2 * forward) {
            return true; // Anfangszug des Bauern
        }
        return endY - startY == forward; // Normaler Zug
    }
    // Schlagbewegung
    return std::abs(startX - endX) == 1 && endY - startY == forward;
}
