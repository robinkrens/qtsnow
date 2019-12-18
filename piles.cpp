#include "piles.h"

Piles::Piles(int w, int h)
{
   maxWidth = w;
   pileBottom = h;
   for (int i = 0; i < maxWidth; i++) {
        pilePixel[i] = pileBottom;
    }

}

bool Piles::hitPile(int x, int y) {
    if (x > maxWidth)
        return false;
    if (pilePixel[x] == y)
        return true;
    return false;
}

void Piles::pileUp(int x) {
    pilePixel[x] = pilePixel[x] - 1;
}

//void Piles::update(int h, int w) {
//    maxWidth = w;
//    pileBottom = h;
//}



