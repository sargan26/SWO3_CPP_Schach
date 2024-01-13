// king.h
#ifndef KING_H
#define KING_H

#include "chessman.h"

class King : public Chessman {
public:
    King(Color color);
    virtual char getSymbol() const override;
    virtual bool isEssential() const override;
    virtual bool canMoveTo(int startX, int startY, int endX, int endY) const override;
};

#endif
