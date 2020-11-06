#ifndef REFERENCEWINDOW_H
#define REFERENCEWINDOW_H

#include <QDialog>
#include <QLabel>
class ReferenceWindow: public QDialog{

    Q_OBJECT
public:
    ReferenceWindow();
private:
    QAction* photo;
    QLabel* version;
    QLabel* name_author;
    QLabel* version_QT;
    QLabel* data_make;
    QPushButton* make_cancel;

};

#endif // REFERENCEWINDOW_H
