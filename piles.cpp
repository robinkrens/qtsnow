#include "piles.h"

Piles::Piles()
{
   for (int i = 0; i < 1440; i++) {
        pilePixel[i] = 860;
    }

}

bool Piles::hitPile(int x, int y) {
    if (x > 1440)
        return false;
    if (pilePixel[x] == y)
        return true;
    return false;
}

void Piles::pileUp(int x) {
    pilePixel[x] = pilePixel[x] - 1;
}



