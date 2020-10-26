#include "m_window1.h"

M_Window1::M_Window1() : QDialog(0){

    W = new QLineEdit;
    H = new QLineEdit;
    A_X = new QLineEdit;
    B_R = new QLineEdit;
    C_R = new QLineEdit;
    D_R = new QLineEdit;
    E_Q = new QLineEdit;
    F_Q = new QLineEdit;
    Angle = new QLineEdit;

    QLabel* W_lable = new QLabel("Width");
    QLabel* H_lable = new QLabel("Height");
    QLabel* A_X_lable = new QLabel("A_X");
    QLabel* B_R_lable = new QLabel("B_R");
    QLabel* C_R_lable = new QLabel("C_R");
    QLabel* D_R_lable = new QLabel("D_R");
    QLabel* E_Q_lable = new QLabel("E_Q");
    QLabel* F_Q_lable = new QLabel("F_Q");
    QLabel* Angle_lable = new QLabel("Angle");

    make_change = new QPushButton("Change");
    cancel = new QPushButton("Cancel");

    connect(make_change, SIGNAL(clicked()), SLOT(accept()));
    connect(cancel, SIGNAL(clicked()), SLOT(reject()));

    QGridLayout* ptopLayout = new QGridLayout;
    ptopLayout->addWidget(W_lable, 0, 0);
    ptopLayout->addWidget(H_lable, 1, 0);
    ptopLayout->addWidget(A_X_lable, 2, 0);
    ptopLayout->addWidget(B_R_lable, 3, 0);
    ptopLayout->addWidget(C_R_lable, 4, 0);
    ptopLayout->addWidget(D_R_lable, 5, 0);
    ptopLayout->addWidget(E_Q_lable, 6, 0);
    ptopLayout->addWidget(F_Q_lable, 7, 0);
    ptopLayout->addWidget(Angle_lable, 8, 0);

    ptopLayout->addWidget(W, 0, 1);
    ptopLayout->addWidget(H, 1, 1);
    ptopLayout->addWidget(A_X, 2, 1);
    ptopLayout->addWidget(B_R, 3, 1);
    ptopLayout->addWidget(C_R, 4, 1);
    ptopLayout->addWidget(D_R, 5, 1);
    ptopLayout->addWidget(E_Q, 6, 1);
    ptopLayout->addWidget(F_Q, 7, 1);
    ptopLayout->addWidget(Angle, 8, 1);

    ptopLayout->addWidget(make_change, 10, 1);
    ptopLayout->addWidget(cancel, 11, 1);

    setLayout(ptopLayout);
}

QString M_Window1::getH() const{
    QString s = H->text();
    if (s == ""){
        return "0";
    }
    else if ( s[0] != '0'){
        int size_str = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] >= '0' && s[i] <= '9'){
                size_str++;
            }
        }
        if (size_str == s.size()){
            return s;
        }
        else{
            return "0";
        }
    }
    return H->text();
}

QString M_Window1::getW() const{
    QString s = W->text();
    if (s == ""){
        return "0";
    }
    else if ( s[0] != '0'){
        int size_str = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] >= '0' && s[i] <= '9'){
                size_str++;
            }
        }
        if (size_str == s.size()){
            return s;
        }
        else{
            return "0";
        }
    }
    return W->text();
}

QString M_Window1::getA_X() const{
    QString s = A_X->text();
    if (s == ""){
        return "0";
    }
    else if ( s[0] != '0'){
        int size_str = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] >= '0' && s[i] <= '9'){
                size_str++;
            }
        }
        if (size_str == s.size()){
            return s;
        }
        else{
            return "0";
        }
    }
    return A_X->text();
}

QString M_Window1::getB_R() const{
    QString s = B_R->text();
    if (s == ""){
        return "0";
    }
    else if ( s[0] != '0'){
        int size_str = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] >= '0' && s[i] <= '9'){
                size_str++;
            }
        }
        if (size_str == s.size()){
            return s;
        }
        else{
            return "0";
        }
    }
    return B_R->text();
}

QString M_Window1::getC_R() const{
    QString s = C_R->text();
    if (s == ""){
        return "0";
    }
    else if ( s[0] != '0'){
        int size_str = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] >= '0' && s[i] <= '9'){
                size_str++;
            }
        }
        if (size_str == s.size()){
            return s;
        }
        else{
            return "0";
        }
    }
    return C_R->text();
}

QString M_Window1::getD_R() const{
    QString s = D_R->text();
    if (s == ""){
        return "0";
    }
    else if ( s[0] != '0'){
        int size_str = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] >= '0' && s[i] <= '9'){
                size_str++;
            }
        }
        if (size_str == s.size()){
            return s;
        }
        else{
            return "0";
        }
    }
    return D_R->text();
}

QString M_Window1::getE_Q() const{
    QString s = E_Q->text();
    if (s == ""){
        return "0";
    }
    else if ( s[0] != '0'){
        int size_str = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] >= '0' && s[i] <= '9'){
                size_str++;
            }
        }
        if (size_str == s.size()){
            return s;
        }
        else{
            return "0";
        }
    }
    return E_Q->text();
}

QString M_Window1::getF_Q() const{
    QString s = F_Q->text();
    if (s == ""){
        return "0";
    }
    else if ( s[0] != '0'){
        int size_str = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] >= '0' && s[i] <= '9'){
                size_str++;
            }
        }
        if (size_str == s.size()){
            return s;
        }
        else{
            return "0";
        }
    }
    return F_Q->text();
}

QString M_Window1::getAngle() const{
    return Angle->text();
}
