#include "figure.h"
#include <cmath>
#include <QMouseEvent>
#include "m_window1.h"
#include "m_window2.h"
#include <QMessageBox>

Figure::Figure(QWidget *parent) : QWidget(parent) {
    W = rand() % 300 + 50;
    H = rand() % (W - 50 ) + 50;

    A_X = rand()% (H / 3),
    B_R = rand()% (H / 3),
    C_R = rand()% (H / 3),
    D_R = rand()% (H / 3),
    E_Q = rand()% (W / 4),
    F_Q = rand()% (W / 4);
    angle = rand()% 360;
    setGeometry(rand() % 600 + 30, rand() % 400 + 30, W*sqrt(2)+1,H*sqrt(2)+1);
}

void Figure::set_data_from_dw(int H_,int  W_, int A_X_, int B_R_, int C_R_, int D_R_, int E_Q_, int F_Q_, int angle_){
    H = H_;
    W = W_;
    A_X = A_X_;
    B_R = B_R_;
    C_R = C_R_;
    D_R = D_R_;
    E_Q = E_Q_;
    F_Q = F_Q_;
    angle = angle_ % 360;

}

void Figure::paintEvent(QPaintEvent *e) {

    Q_UNUSED(e)

    this->resize(sqrt(W*W + H*H) + 1, sqrt(W*W + H*H) + 1);
    QPainterPath path_figure1;
    QPainter painter(this);
    painter.translate((sqrt(W*W + H*H) + 1)/2, (sqrt(W*W + H*H) + 1)/2);
    painter.rotate(angle);
    path_figure1.moveTo(0 + E_Q/2, -H/2);

    if (!lmb_pressed){
        QPen linepen(Qt::black);
        linepen.setWidth(2);
        painter.setPen(linepen);
    }
    else{
        QPen linepen(Qt::blue);
        linepen.setWidth(2);
        painter.setPen(linepen);

    }

    path_figure1.lineTo(W/2 - A_X, -H/2);
    path_figure1.lineTo(W/2, -H/2 + A_X);
    path_figure1.lineTo(W/2, H/2 - B_R/2);

    path_figure1.moveTo(W/2 - B_R,H/2);
    QRectF rectangle( W/2 - B_R,H/2 - B_R ,B_R, B_R);
    path_figure1.arcTo(rectangle, 270,90);

    path_figure1.moveTo(W/2 - B_R,H/2);
    path_figure1.lineTo(0 + F_Q/2,H/2);
    QRectF rectangle2( 0 - F_Q/2, H/2 - F_Q/2 ,F_Q, F_Q);
    path_figure1.arcTo(rectangle2, 0,180);

    path_figure1.moveTo(0 - F_Q/2,H/2);
    path_figure1.lineTo(0-W/2+C_R/2,H/2);
    path_figure1.moveTo(-W/2,H/2 - C_R);
    QRectF rectangle3(- W/2  , H/2 - C_R, C_R, C_R);
    path_figure1.arcTo(rectangle3, 180,90);
    path_figure1.moveTo(-W/2,H/2 - C_R);

    path_figure1.lineTo(-W/2, -H/2 + D_R/2 );
    QRectF rectangle4(- W/2 - D_R/2, -H/2 - D_R/2, D_R, D_R);
    path_figure1.arcTo(rectangle4, 270,90);

    path_figure1.moveTo(- W/2 + D_R/2, - H/2 );
    path_figure1.lineTo(0 - E_Q/2,-H/2);
    QRectF rectangle5(0 - E_Q/2,-H/2 - E_Q/2, E_Q, E_Q);
    path_figure1.arcTo(rectangle5, 180,180);
    painter.drawPath(path_figure1);
}

void Figure::set_status_pressed_1(bool status){
    lmb_pressed = status;
}

bool Figure::get_status_pressed_1(){
    return lmb_pressed;
}

void Figure::mouseMoveEvent(QMouseEvent *event){

    lmb_pressed = true;
    QWidget::update();
    if (event->buttons() & Qt::LeftButton){
        if (((event->globalPos() - offset).x() + width() > 1200) ||
            ((event->globalPos() - offset).y() + height() > 800) ||
            ((event->globalPos() - offset).x() <= 0 ) ||
            ((event->globalPos() - offset).y() <= 30))
                offset = event->globalPos() - pos();
        else
            move(event->globalPos() - offset);
    }

}

void Figure::mousePressEvent(QMouseEvent* event){

    if (event->button() & Qt::LeftButton){
        nazh++;
        if (nazh % 2 == 0)
            lmb_pressed = false;
        else
            lmb_pressed = true;
        QWidget::update();
        offset = event->globalPos() - pos();
    }
    if (event->button() & Qt::RightButton){
        if (!lmb_pressed){
              nazh++;
        }
        lmb_pressed = true;
        QWidget::update();
        M_Window1* w1 = new M_Window1;
        if(w1->exec() == QDialog::Accepted){
            if (w1->getW() == "0" || w1->getH() == "0" || w1->getA_X() == "0" ||
                w1->getB_R() == "0" || w1->getC_R() == "0" || w1->getD_R() == "0" ||
                    w1->getE_Q() == "0"){
                QMessageBox::information(0 ,"Information", "Some data is zero");
            }
            else{
                if (((w1->getW()).toInt() <= (w1->getH()).toInt()) ||
                   ((w1->getA_X()).toInt() >= (w1->getH()).toInt()/3) ||
                   ((w1->getB_R()).toInt() >= (w1->getH()).toInt()/3) ||
                   ((w1->getC_R()).toInt() >= (w1->getH()).toInt()/3) ||
                   ((w1->getD_R()).toInt() >= (w1->getH()).toInt()/3) ||
                   ((w1->getW()).toInt() /4 <= (w1->getE_Q()).toInt()) ||
                   ((w1->getW()).toInt() /4 <= (w1->getF_Q()).toInt())){
                    QMessageBox::information(0,
                    "Information",
                    "Error entered"
                    );
                }
                else{
                    set_data_from_dw((w1->getW()).toInt(),
                            (w1->getH()).toInt(),
                            (w1->getA_X()).toInt(),
                            (w1->getB_R()).toInt(),
                            (w1->getC_R()).toInt(),
                            (w1->getD_R()).toInt(),
                            (w1->getE_Q()).toInt(),
                            (w1->getF_Q()).toInt(),
                            (w1->getAngle()).toInt());
                    double perimetr = (W/2 - A_X - E_Q/2) + (H/2 - A_X - B_R)
                            + 3.14*B_R/2 + (W/2 - F_Q/2 - B_R/2) + 3.14*F_Q/2
                            + (W/2 - C_R/2 - F_Q/2) + 3.14*C_R/2
                            + (H/2 - C_R - D_R/2) + (W/2 - D_R/2 - E_Q/2);
                    QString sp = QString::number(perimetr);
                    double square = W*H - A_X*A_X/2 - 3.14*B_R*B_R/4  - 3.14*F_Q*F_Q/2 - 3.14*C_R*C_R/4 - 3.14*D_R*D_R/4 - 3.14*E_Q*E_Q/2;
                    QString ss = QString::number(square);
                    QMessageBox::information(0,
                            "Information",
                            "Square: "
                            + ss
                            +"\nPerimetr: "
                            + sp
                            );
                    QWidget::update();
                }
            }
        }
        else{
            double perimetr = (W/2 - A_X/2 - E_Q/2) + abs(-H/2 + A_X) + (H/2 - B_R/2) + 3.14*B_R/2 +(W/2 - F_Q/2) + 3.14*F_Q/2 + (W/2 - C_R/2 - F_Q/2) + 3.14*C_R/2 +
                    (H/2 - C_R - D_R/2) + (W/2 - D_R/2 - E_Q/2);
            QString sp = QString::number(perimetr);
            double square = W*H - A_X*A_X/2 - 3.14*B_R*B_R/4  - 3.14*F_Q*F_Q/2 - 3.14*C_R*C_R/4 - 3.14*D_R*D_R/4 - 3.14*3.14*E_Q*E_Q/2;
            QString ss = QString::number(square);
            QMessageBox::information(0,
                    "Information",
                    "Square: "
                    + ss
                    +"\nPerimetr: "
                    + sp
                    );
            QWidget::update();
        }
        delete w1;
    }
}

Figure2::Figure2(QWidget *parent) : QWidget(parent) {
    W = rand() % 300 + 50;
    H = rand() % (W - 50 ) + 50;

    A_R = rand()% (H / 3),
    B_X = rand()% (H / 3),
    C_R = rand()% (H / 3),
    D_X = rand()% (H / 3),
    E_P = rand()% (W / 4),
    F_Q = rand()% (W / 4);
    angle = rand()% 360;
    setGeometry(rand() % 600 + 30, rand() % 400 + 30, W*sqrt(2)+1,H*sqrt(2)+1);
}

void Figure2::set_data_from_dw(int H_,int  W_, int A_R_, int B_X_, int C_R_, int D_X_, int E_P_, int F_Q_, int angle_){
    H = H_;
    W = W_;
    A_R = A_R_;
    B_X = B_X_;
    C_R = C_R_;
    D_X = D_X_;
    E_P = E_P_;
    F_Q = F_Q_;
    angle = angle_ % 360;

}

void Figure2::paintEvent(QPaintEvent *e) {
    Q_UNUSED(e)
    this->resize(sqrt(W*W + H*H) + 1, sqrt(W*W + H*H) + 1);

    QPainterPath path_figure2;
    QPainter painter(this);
    painter.translate(sqrt(W*W + H*H)/2, sqrt(W*W + H*H)/2);
    painter.rotate(angle);
    path_figure2.moveTo(0 + E_P/2, -H/2);
    if (!lmb_pressed){
        QPen linepen(Qt::black);
        linepen.setWidth(2);
        painter.setPen(linepen);

    }
    else{
        QPen linepen(Qt::blue);
        linepen.setWidth(2);
        painter.setPen(linepen);
    }
    //A3
    path_figure2.lineTo(W/2 - A_R/2,-H/2);
    QRectF rectangle(W/2 - A_R/2, -H/2 - A_R/2, A_R, A_R);
    path_figure2.arcTo(rectangle, 180, 90);
    path_figure2.moveTo(W/2, -H/2 + A_R/2);
    //B1
    path_figure2.lineTo(W/2, H/2 - B_X);
    path_figure2.lineTo(W/2 - B_X, H/2 - B_X);
    path_figure2.lineTo(W/2 - B_X, H/2);
    //F6
    path_figure2.lineTo(0 + F_Q/2,H/2);
    QRectF rectangle2( 0 - F_Q/2, H/2 - F_Q/2 ,F_Q, F_Q);
    path_figure2.arcTo(rectangle2, 0,180);
    //C3
    path_figure2.moveTo(0 - F_Q/2, H/2);
    path_figure2.lineTo(-W/2 + C_R/2,H/2);
    QRectF rectangle3( -W/2 - C_R/2, H/2 - C_R/2 ,C_R, C_R);
    path_figure2.arcTo(rectangle3, 0,90);
    path_figure2.moveTo(-W/2, H/2 - C_R/2);
    //D1
    path_figure2.lineTo(-W/2, -H/2 + D_X);
    path_figure2.lineTo(-W/2 + D_X, -H/2 + D_X);
    path_figure2.lineTo(-W/2 + D_X, -H/2);
    //E5
     path_figure2.lineTo(-E_P/2, -H/2);
     path_figure2.lineTo(-E_P/2, -H/2 + E_P/2);
     path_figure2.lineTo(E_P/2, -H/2 + E_P/2);
     path_figure2.lineTo(E_P/2, -H/2);
     painter.drawPath(path_figure2);
}

void Figure2::mouseMoveEvent(QMouseEvent *event){
    lmb_pressed = true;
    QWidget::update();
    if (event->buttons() & Qt::LeftButton){
        if (((event->globalPos() - offset).x() + width() > 1200) ||
            ((event->globalPos() - offset).y() + height() > 800) ||
            ((event->globalPos() - offset).x() <= 0 ) ||
            ((event->globalPos() - offset).y() <= 30))
                offset = event->globalPos() - pos();
        else
            move(event->globalPos() - offset);
    }
}

void Figure2::mousePressEvent(QMouseEvent* event){
    if (event->button() & Qt::LeftButton){
        nazh++;
        if (nazh % 2 == 0)
            lmb_pressed = false;
        else
            lmb_pressed = true;
        QWidget::update();
        offset = event->globalPos() - pos();
    }
    if (event->button() & Qt::RightButton){
        if (!lmb_pressed){
              nazh++;
        }
        lmb_pressed = true;
        QWidget::update();
        M_Window2* w1 = new M_Window2;
        if(w1->exec() == QDialog::Accepted){
            if (w1->getW() == "0" || w1->getH() == "0" || w1->getA_R() == "0" ||
                w1->getB_X() == "0" || w1->getC_R() == "0" || w1->getD_X() == "0" ||
                    w1->getE_P() == "0"){
                QMessageBox::information(0 ,"Information", "Some data is zero");
            }
            else{
                if (((w1->getW()).toInt() <= (w1->getH()).toInt()) ||
                   ((w1->getA_R()).toInt() >= (w1->getH()).toInt()/3) ||
                   ((w1->getB_X()).toInt() >= (w1->getH()).toInt()/3) ||
                   ((w1->getC_R()).toInt() >= (w1->getH()).toInt()/3) ||
                   ((w1->getD_X()).toInt() >= (w1->getH()).toInt()/3) ||
                   ((w1->getW()).toInt() /4 <= (w1->getE_P()).toInt()) ||
                   ((w1->getW()).toInt() /4 <= (w1->getF_Q()).toInt())){
                    QMessageBox::information(0,
                    "Information",
                    "Error entered"
                    );
                }
                else{
                    set_data_from_dw((w1->getW()).toInt(),
                            (w1->getH()).toInt(),
                            (w1->getA_R()).toInt(),
                            (w1->getB_X()).toInt(),
                            (w1->getC_R()).toInt(),
                            (w1->getD_X()).toInt(),
                            (w1->getE_P()).toInt(),
                            (w1->getF_Q()).toInt(),
                            (w1->getAngle()).toInt());
                    double perimetr = (W/2 - A_R/2 - E_P/2) + abs(H/2 - A_R - B_X) + 2*B_X  + (W/2 - F_Q/2 - B_X ) + 3.14*F_Q/2 + (W/2 - C_R/2 - F_Q/2) + 3.14*C_R/2 +
                            (H/2 - C_R - D_X) + 2*D_X + (W/2 - D_X/2 - E_P/2) + 2*E_P;
                    QString sp = QString::number(perimetr);
                    double square = W*H - 3.14*A_R*A_R/4 - B_X*B_X  - 3.14*F_Q*F_Q/2 - 3.14*C_R*C_R/4 - D_X*D_X - E_P*E_P/2;
                    QString ss = QString::number(square);
                    QMessageBox::information(0,
                            "Information",
                            "Square: "
                            + ss
                            +"\nPerimetr: "
                            + sp
                            );
                    QWidget::update();

                }
            }
        }
        else{
            double perimetr = (W/2 - A_R/2 - E_P/2) + abs(H/2 - A_R - B_X) + 2*B_X  + (W/2 - F_Q/2 - B_X ) + 3.14*F_Q/2 + (W/2 - C_R/2 - F_Q/2) + 3.14*C_R/2 +
                    (H/2 - C_R - D_X) + 2*D_X + (W/2 - D_X/2 - E_P/2) + 2*E_P;
            QString sp = QString::number(perimetr);
            double square = W*H - 3.14*A_R*A_R/4 - B_X*B_X  - 3.14*F_Q*F_Q/2 - 3.14*C_R*C_R/4 - D_X*D_X - E_P*E_P/2;
            QString ss = QString::number(square);
            QMessageBox::information(0,
                    "Information",
                    "Square: "
                    + ss
                    +"\nPerimetr: "
                    + sp
                    );
            QWidget::update();
        }
        delete w1;
    }
}

bool Figure2::get_status_pressed_2(){
    return lmb_pressed;
}

void Figure2::set_status_pressed_2(bool status){
    lmb_pressed = status;
}
