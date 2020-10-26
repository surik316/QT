#ifndef M_WINDOW2_H
#define M_WINDOW2_H
#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

class M_Window2 :public QDialog{

    Q_OBJECT

private:
    QLineEdit* W;
    QLineEdit* H;
    QLineEdit* A_R;
    QLineEdit* B_X;
    QLineEdit* C_R;
    QLineEdit* D_X;
    QLineEdit* E_P;
    QLineEdit* F_Q;
    QLineEdit* Angle;
    QPushButton *make_change;
    QPushButton *cancel;

public:
    QString getW() const;
    QString getH() const;
    QString getA_R() const;
    QString getB_X() const;
    QString getC_R() const;
    QString getD_X() const;
    QString getE_P() const;
    QString getF_Q() const;
    QString getAngle() const;
    M_Window2();

};

#endif // M_WINDOW2_H
