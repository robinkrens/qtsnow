#include "qtsnow.h"
#include "ui_qtsnow.h"

qtsnow::qtsnow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::qtsnow),
    piles(0,0)
{
    /* Setup graphics */
    ui->setupUi(this);

    /* Initiate timers */
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &qtsnow::animate);
    timer->start(35);

    QTimer *gustTimer = new QTimer(this);
    connect(gustTimer, &QTimer::timeout, this, &qtsnow::animateGusts);
    gustTimer->start(1000);

    blowingWind = false;

    /* Initiate dynamic vector of snowFlakes*/
    snowFlakes = new std::vector<Snow>;
    textPen = QPen(Qt::white);
    textFont.setPixelSize(100);
}

qtsnow::~qtsnow()
{
    delete ui;
}

void qtsnow::animateGusts() {

    if (blowingWind) {
        for (std::vector<Snow>::iterator it = snowFlakes->begin(); it!=snowFlakes->end(); ++it) {
            it->restoreSwirl();
            it->update();
        }
        blowingWind = false;
    }
    else {
        if (rand() % 8 > 0)
            return;
        int randDir = rand() % 2;
        for (std::vector<Snow>::iterator it = snowFlakes->begin(); it!=snowFlakes->end(); ++it) {
            it->windGust(10, randDir);
            it->update();
        }
        blowingWind = true;
    }

    /* Update screen (calls paintEvent) */
    update();
}

void qtsnow::restoreGusts() {

    for (std::vector<Snow>::iterator it = snowFlakes->begin(); it!=snowFlakes->end(); ++it) {
        it->restoreSwirl();
        it->update();
    }
}

void qtsnow::animate() {

    Snow s(&piles, windowWidth);
    snowFlakes->push_back(s);

    for (std::vector<Snow>::iterator it = snowFlakes->begin(); it!=snowFlakes->end(); ++it) {
        it->update();
    }

    /* Update screen (calls paintEvent) */
    update();

}

void qtsnow::paint(QPainter *painter, QPaintEvent *event) {

    painter->setPen(textPen);

    for (std::vector<Snow>::iterator it = snowFlakes->begin(); it!=snowFlakes->end(); ++it) {
        painter->drawRect(it->getPos());
        painter->fillRect(it->getPos(), QColor(Qt::white));

    }

    painter->setFont(textFont);
    QString wish = "Merry X-Mas!";
    QPoint wishPos(windowWidth / 2 - 250, windowHeight / 2);
    painter->drawText(wishPos, wish);


}

void qtsnow::paintEvent(QPaintEvent* event)
{

    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    this->paint(&painter, event);
    painter.end();

}

void qtsnow::updateSizeConfig(int h, int w) {

    windowHeight = h;
    windowWidth = w;
    piles = Piles(windowWidth, windowHeight);

    qDebug() << "Height: " << windowHeight << "Width: " << windowWidth;

}
