#ifndef QTSNOW_H
#define QTSNOW_H

#include <QWidget>
#include <QPen>
#include <QFont>
#include <QPainter>
#include <QVector>
#include <QTimer>
#include <QDebug>
#include <QColor>
#include <QTextItem>
#include <QPicture>
#include <QSound>

#include "snow.h"
#include "tree.h"

#define INTROTIME 100

namespace Ui {
class qtsnow;
}

class qtsnow : public QWidget
{
    Q_OBJECT

public:
    explicit qtsnow(QWidget *parent = 0);
    ~qtsnow();
    void paint(QPainter *painter, QPaintEvent *event);
    void animate();
    void animateGusts();
    void restoreGusts();
    void updateSizeConfig(int h, int w);

private:
    /* Graphics related */
    Ui::qtsnow *ui;
    QPen textPen;
    QFont textFont;

    /* Objects related */
    std::vector<Snow> * snowFlakes;
    Piles piles;
    bool blowingWind;
    std::vector<Tree> * trees;

    /* Window settings */
    int windowHeight;
    int windowWidth;

    /* Background  music */
    QSound bells;

    /* Time for intro text */
    int introTextTime;
    \
protected:
    void paintEvent(QPaintEvent*);

};

#endif // QTSNOW_H
