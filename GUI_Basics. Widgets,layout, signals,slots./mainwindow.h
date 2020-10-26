#ifndef mainwindow_h
#define mainwindow_h
#include "figure.h"
#include <QtGui>
#include <QPushButton>
#include <QMainWindow>
#include  <QButtonGroup>
#include <unordered_map>

class MainWindow : public QMainWindow {

  Q_OBJECT

private: 

     QButtonGroup buttons_group;
     QPushButton *m_figure1 = new QPushButton("Figure 1");
     QPushButton *m_figure2 = new QPushButton("Figure 2");
     QPushButton *m_add = new QPushButton("+");
     QPushButton *m_delete = new QPushButton("-");
     QTimer tmr;
     std::unordered_map<int, Figure*> widjets_f1;
     int index_1 = 0;
     std::unordered_map<int, Figure2*> widjets_f2;
     int index_2 = 0;

public:
    MainWindow(QWidget *p = 0);
    QToolBar* createToolBar();

public slots:
    void activate_del();
    void button_F1_pressed();
    void button_F2_pressed();
    void button_add_pressed();
    void delete_figure1();
    void delete_figure2();
};

#endif




