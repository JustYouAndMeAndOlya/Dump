#include "rs.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    rs *w= new rs;
    w->resize(300,200);
    w->show();

    return a.exec();
}
