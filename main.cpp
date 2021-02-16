#include "MMQTT.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MMQTT w;
    w.show();
    return a.exec();
}
