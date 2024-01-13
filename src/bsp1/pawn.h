// pawn.h
#ifndef PAWN_H
#define PAWN_H

#include "chessman.h"

class Pawn : public Chessman {
public:
    Pawn(Color color);
    virtual char getSymbol() const override;
    virtual bool isEssential() const override;
    virtual bool canMoveTo(int startX, int startY, int endX, int endY) const override;

private:
    bool isFirstMove = true;
};

#endif
