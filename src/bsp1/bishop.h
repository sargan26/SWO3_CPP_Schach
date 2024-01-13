// bishop.h
#ifndef BISHOP_H
#define BISHOP_H

#include "chessman.h"

class Bishop : public Chessman {
public:
    Bishop(Color color);
    virtual char getSymbol() const override;
    virtual bool isEssential() const override;
    virtual bool canMoveTo(int startX, int startY, int endX, int endY) const override;
};

#endif
