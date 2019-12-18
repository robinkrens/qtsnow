#ifndef PILES_H
#define PILES_H


class Piles
{
public:
    Piles();
    bool hitPile(int x, int y);
    void pileUp(int x);

private:
    int pilePixel[1440];
};

#endif // PILES_H
