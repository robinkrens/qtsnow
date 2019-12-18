#include "snow.h"
#include <QDebug>

#define maxWidth 1440

Snow::Snow(Piles * p)
{
    int startPos = rand() % maxWidth;
    r.setRect(startPos,0,2,3);

    piled = false;
    piles = p;

    oldSwirl = swirl;

 }

Snow::~Snow() {

}

void Snow::update() {

    if (piled)
        return; /* Can destroy object, BUT planning on other doing other stuff still :D */

    if (piles->hitPile(r.x(), r.y())) {
        piles->pileUp(r.x());
        piled = true;
        return;
    }

    if (r.x() > 1440)
        r.moveLeft(0);
    else if(r.x() < 0)
        r.moveLeft(1440);

    int displacement = swirl.speed * 1;

    if (swirl.dir == 0) {
        r.moveRight(r.right() + displacement);
        swirl.curDisposition++;
    }
    else if(swirl.dir == 1) {
        r.moveRight(r.right() - displacement);
        swirl.curDisposition++;
    }

    if (swirl.curDisposition % swirl.randSwirl == 0) {
        swirl.curDisposition = 0;
        if(swirl.dir == 0)
            swirl.dir = 1;
        else {
            swirl.dir = 0;
        }
    }

    r.moveTop(r.top() + 1);


}

QRect Snow::getPos() {
    return r;
}

void Snow::windGust(int sp, int dir) {

    swirl.speed = sp;
    swirl.curDisposition = 0;
    swirl.dir = dir;
    swirl.randSwirl = 1000; /* Just keep swirling in one direction basically */

}
void Snow::restoreSwirl() {
    swirl = oldSwirl;
}

bool Snow::hitPile() {

}
