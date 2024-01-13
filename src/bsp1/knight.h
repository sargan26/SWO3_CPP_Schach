// knight.h
#ifndef KNIGHT_H
#define KNIGHT_H

#include "chessman.h"

class Knight : public Chessman {
public:
    Knight(Color color);
    virtual char getSymbol() const override;
    virtual bool isEssential() const override;
    virtual bool canMoveTo(int startX, int startY, int endX, int endY) const override;
};

#endif
