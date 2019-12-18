#include "qtsnow.h"
#include <QApplication>
#include <QDebug>
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qtsnow w;

    /* Linux (X11) Settings */
    //w.setAttribute(Qt::WA_TransparentForMouseEvents, true);
    //w.setWindowFlag(Qt::X11BypassWindowManagerHint);
    w.setAttribute(Qt::WA_TranslucentBackground, true);
    w.setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    w.showMaximized();

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->availableGeometry();
    w.updateSizeConfig(screenGeometry.height(), screenGeometry.width());
    //w.adjustSize();

    return a.exec();
}
