#include "qtsnow.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qtsnow w;
    w.setAttribute(Qt::WA_TranslucentBackground, true);
    w.setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    w.showMaximized();
    w.updateSizeConfig(w.geometry().height(), w.geometry().width());

    return a.exec();
}
