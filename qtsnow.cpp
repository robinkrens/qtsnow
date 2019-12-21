#include "qtsnow.h"
#include "ui_qtsnow.h"

qtsnow::qtsnow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::qtsnow),
    piles(0,0),
    bells("resources/8bit.wav"),
    introTextTime(0)
{
    /* Setup graphics */
    ui->setupUi(this);

    /* Initiate timers for animation */
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &qtsnow::animate);
    timer->start(35);

    /* and windgusts */
    QTimer *gustTimer = new QTimer(this);
    connect(gustTimer, &QTimer::timeout, this, &qtsnow::animateGusts);
    gustTimer->start(1000);
    blowingWind = false;

    /* Initiate dynamic vector of snowFlakes and trees */
    snowFlakes = new std::vector<Snow>;
    trees = new std::vector<Tree>;

    /* Initiate colors for fonts and drawing */
    textPen = QPen(Qt::white);
    textFont.setPixelSize(100);

    /* Set sound to play infinite */
    bells.setLoops(QSound::Infinite);
    bells.play();

}

qtsnow::~qtsnow()
{
    delete ui;
    delete snowFlakes;
    delete trees;
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

    /* Paint snowflakes */
    textPen = QPen(Qt::white);
    painter->setPen(textPen);

    for (std::vector<Snow>::iterator it = snowFlakes->begin(); it!=snowFlakes->end(); ++it) {
        painter->drawRect(it->getPos());
        painter->fillRect(it->getPos(), QColor(Qt::white));

    }

    /* Draw trees */
    QImage tree;
    QRectF source(0.0, 0.0, 50, 61.0);
    tree.load("resources/tree.png");

   for (std::vector<Tree>::iterator it = trees->begin(); it!=trees->end(); ++it) {
       QRectF target(it->posx, windowHeight - 61, 50.0, 61.0);

       painter->drawImage(target, tree, source);
   }


   introTextTime++;
   if (introTextTime > INTROTIME)
       return;
   painter->setFont(textFont);
   QString wish = "Merry X-Mas!";

   textPen = QPen(Qt::red);
   painter->setPen(textPen);

   QPoint wishPos(windowWidth / 2 - 280, windowHeight / 2);
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

    int nrtrees = rand() % 50;
    for (int i = 0; i < nrtrees; i++) {
        Tree t = Tree(windowWidth);
        trees->push_back(t);
    }

    qDebug() << "Height: " << windowHeight << "Width: " << windowWidth;

}
