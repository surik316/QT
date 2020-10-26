#include "m_window2.h"

M_Window2::M_Window2(): QDialog(0){
    W = new QLineEdit;
    H = new QLineEdit;
    A_R = new QLineEdit;
    B_X = new QLineEdit;
    C_R = new QLineEdit;
    D_X = new QLineEdit;
    E_P = new QLineEdit;
    F_Q = new QLineEdit;
    Angle = new QLineEdit;

    QLabel* W_lable = new QLabel("Width");
    QLabel* H_lable = new QLabel("Height");
    QLabel* A_R_lable = new QLabel("A_R");
    QLabel* B_X_lable = new QLabel("B_X");
    QLabel* C_R_lable = new QLabel("C_R");
    QLabel* D_X_lable = new QLabel("D_X");
    QLabel* E_P_lable = new QLabel("E_P");
    QLabel* F_Q_lable = new QLabel("F_Q");
    QLabel* Angle_lable = new QLabel("Angle");

    make_change = new QPushButton("Change");
    cancel = new QPushButton("Cancel");

    connect(make_change, SIGNAL(clicked()), SLOT(accept()));
    connect(cancel, SIGNAL(clicked()), SLOT(reject()));

    QGridLayout* ptopLayout = new QGridLayout;
    ptopLayout->addWidget(W_lable, 0, 0);
    ptopLayout->addWidget(H_lable, 1, 0);
    ptopLayout->addWidget(A_R_lable, 2, 0);
    ptopLayout->addWidget(B_X_lable, 3, 0);
    ptopLayout->addWidget(C_R_lable, 4, 0);
    ptopLayout->addWidget(D_X_lable, 5, 0);
    ptopLayout->addWidget(E_P_lable, 6, 0);
    ptopLayout->addWidget(F_Q_lable, 7, 0);
    ptopLayout->addWidget(Angle_lable, 8, 0);

    ptopLayout->addWidget(W, 0, 1);
    ptopLayout->addWidget(H, 1, 1);
    ptopLayout->addWidget(A_R, 2, 1);
    ptopLayout->addWidget(B_X, 3, 1);
    ptopLayout->addWidget(C_R, 4, 1);
    ptopLayout->addWidget(D_X, 5, 1);
    ptopLayout->addWidget(E_P, 6, 1);
    ptopLayout->addWidget(F_Q, 7, 1);
    ptopLayout->addWidget(Angle, 8, 1);

    ptopLayout->addWidget(make_change, 10, 1);
    ptopLayout->addWidget(cancel, 11, 1);

    setLayout(ptopLayout);
}

QString M_Window2::getH() const{
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

QString M_Window2::getW() const{
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

QString M_Window2::getA_R() const{
    QString s = A_R->text();
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
    return A_R->text();
}

QString M_Window2::getB_X() const{
    QString s = B_X->text();
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
    return B_X->text();
}

QString M_Window2::getC_R() const{
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

QString M_Window2::getD_X() const{
    QString s = D_X->text();
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
    return D_X->text();
}

QString M_Window2::getE_P() const{
    QString s = E_P->text();
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
    return E_P->text();
}

QString M_Window2::getF_Q() const{
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

QString M_Window2::getAngle() const{
    return Angle->text();
}
