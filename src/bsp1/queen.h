// queen.h
#ifndef QUEEN_H
#define QUEEN_H

#include "chessman.h"

class Queen : public Chessman {
public:
    Queen(Color color);
    virtual char getSymbol() const override;
    virtual bool isEssential() const override;
    virtual bool canMoveTo(int startX, int startY, int endX, int endY) const override;
};

#endif
