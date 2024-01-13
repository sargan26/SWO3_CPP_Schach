#ifndef CHESSMAN_H
#define CHESSMAN_H

enum class Color { WHITE, BLACK };

class Chessman {
public:
    Chessman(Color color);
    virtual ~Chessman() = default;

    Color getColor() const;
    virtual char getSymbol() const = 0;
    virtual bool isEssential() const = 0;
    virtual bool canMoveTo(int startX, int startY, int endX, int endY) const = 0;

private:
    Color color;
};

#endif
