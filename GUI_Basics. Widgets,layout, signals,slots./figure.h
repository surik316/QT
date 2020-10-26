#ifndef FIG
#define FIG

#include <QWidget>
#include <QPainter>
#include <QPainterPath>

class Figure : public QWidget {

    Q_OBJECT

private:
  bool lmb_pressed = false;
  QPoint offset;
  int H, W, A_X, B_R, C_R, D_R, E_Q, F_Q, angle = 0, nazh = 0;

public:
  Figure(QWidget *parent = 0);
  bool get_status_pressed_1();
  void set_status_pressed_1(bool);
  void set_data_from_dw(int, int, int, int, int, int, int, int, int);

protected:
  void paintEvent(QPaintEvent *e);
  void mousePressEvent(QMouseEvent* event);
  void mouseMoveEvent(QMouseEvent *event);
};

class Figure2 : public QWidget {

  Q_OBJECT

private:    
    bool lmb_pressed = false;
    QPoint offset;
    int W, H, A_R, B_X, C_R, D_X, E_P, F_Q, angle = 0, nazh = 0;

public:    
  Figure2(QWidget *parent = 0);
  bool get_status_pressed_2();
  void set_status_pressed_2(bool);
  void set_data_from_dw(int, int, int, int, int, int, int, int, int);

protected:
  void paintEvent(QPaintEvent *e);
  void mousePressEvent(QMouseEvent* event);
  void mouseMoveEvent(QMouseEvent *event);
};


#endif

