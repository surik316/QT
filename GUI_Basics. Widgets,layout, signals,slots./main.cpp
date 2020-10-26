#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    MainWindow a;
    a.resize(1200,800);
    a.show();
    return app.exec();

}

