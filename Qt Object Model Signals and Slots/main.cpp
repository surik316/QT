#include <QCoreApplication>
#include "Klass.h"
#include <QTimer>
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Klass klass;
    QObject::connect(&klass, SIGNAL(all_signal()), &a, SLOT(quit()));
    return a.exec();
}
