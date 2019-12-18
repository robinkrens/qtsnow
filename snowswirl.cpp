#include "snowswirl.h"
#include <QDebug>

snowSwirl::snowSwirl()
{
    dir = rand() % 2;
    randSwirl = rand() % 55 + 2;
    curDisposition = 0;
    speed = 1;
}
snowSwirl::snowSwirl(const snowSwirl &sw)
{
    dir = sw.dir;
    speed = sw.speed;
    curDisposition = sw.curDisposition;
    randSwirl = sw.randSwirl;
}
