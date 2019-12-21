#include "qtsnow.h"
#include <QApplication>
#include <QDebug>
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qtsnow w;

    w.setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    w.setAttribute(Qt::WA_TransparentForMouseEvents, true);
    w.setAttribute(Qt::WA_TranslucentBackground, true);

    w.showMaximized();


   //w.setWindowFlag(Qt::X11BypassWindowManagerHint);

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->availableGeometry();
    w.updateSizeConfig(screenGeometry.height(), screenGeometry.width());

    return a.exec();
}
