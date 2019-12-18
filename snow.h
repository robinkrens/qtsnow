#ifndef SNOW_H
#define SNOW_H

#include <QRect>
#include "snowswirl.h"
#include "piles.h"

class Snow
{

public:
    Snow(Piles * piles, int screenWidth);
    ~Snow();
    void update();
    QRect getPos();
    bool hitPile();
    void windGust(int sp, int dir);
    void restoreSwirl();

private:
    int maxWidth;
    QRect r; /* simple 1-dot rectangle for now */
    snowSwirl swirl, oldSwirl; /* Snow swirling (<-- is it called that way) */
    bool piled;
    Piles * piles;

};

#endif // SNOW_H
