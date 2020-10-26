#ifndef M_WINDOW1_H
#define M_WINDOW1_H
#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

class M_Window1 : public QDialog{

    Q_OBJECT

private:
    QLineEdit* W;
    QLineEdit* H;
    QLineEdit* A_X;
    QLineEdit* B_R;
    QLineEdit* C_R;
    QLineEdit* D_R;
    QLineEdit* E_Q;
    QLineEdit* F_Q;
    QLineEdit* Angle;
    QPushButton *make_change;
    QPushButton *cancel;

public:
    QString getW() const;
    QString getH() const;
    QString getA_X() const;
    QString getB_R() const;
    QString getC_R() const;
    QString getD_R() const;
    QString getE_Q() const;
    QString getF_Q() const;
    QString getAngle() const;
    M_Window1();
};

#endif // M_WINDOW1_H
