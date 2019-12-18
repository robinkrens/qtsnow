#ifndef PILES_H
#define PILES_H


class Piles
{
public:
    Piles(int w, int h);
    bool hitPile(int x, int y);
    void pileUp(int x);
    //void update();

private:
    int pilePixel[2000];
    int maxWidth;
    int pileBottom;
};

#endif // PILES_H
