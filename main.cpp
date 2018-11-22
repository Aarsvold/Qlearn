#include <QCoreApplication>
#include "qlearn.h"
#include <iostream>
#include <iomanip>
#include <ctime>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Qlearn hej;
hej.iterate(1000);
hej.printR();
hej.printroute();
}
