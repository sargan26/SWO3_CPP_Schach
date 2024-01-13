// rook.h
#ifndef ROOK_H
#define ROOK_H

#include "chessman.h"

class Rook : public Chessman {
public:
    Rook(Color color);
    virtual char getSymbol() const override;
    virtual bool isEssential() const override;
    virtual bool canMoveTo(int startX, int startY, int endX, int endY) const override;
};

#endif
