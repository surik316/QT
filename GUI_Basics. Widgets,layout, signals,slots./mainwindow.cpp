#include "mainwindow.h"
#include "figure.h"
MainWindow::MainWindow(QWidget *p) : QMainWindow(p) {
    QPalette pal;
    pal.setColor(this->backgroundRole(), Qt::white);
    this->setPalette(pal);
    addToolBar(Qt::TopToolBarArea, createToolBar());
    connect(m_figure1, SIGNAL(clicked()), this, SLOT(button_F1_pressed()));
    connect(m_figure2, SIGNAL(clicked()), this, SLOT(button_F2_pressed()));
    connect(m_add, SIGNAL(clicked()), this, SLOT(button_add_pressed()));
    connect(m_delete, SIGNAL(clicked()), this, SLOT(delete_figure1()));
    connect(m_delete, SIGNAL(clicked()), this, SLOT(delete_figure2()));
    connect(&tmr, SIGNAL(timeout()), this, SLOT(activate_del()));
    tmr.start(1);
}

QToolBar* MainWindow::createToolBar() {
    QToolBar *ptb = new QToolBar();
    ptb->setMovable(false);

    m_figure1->setCheckable(true);
    m_figure2->setCheckable(true);
    m_add->setEnabled(false);
    m_delete->setEnabled(false);
    buttons_group.addButton(m_figure1);
    buttons_group.addButton(m_figure2);
    buttons_group.setExclusive(false);
    ptb->setFixedHeight(30);
    ptb->addWidget(m_figure1);
    ptb->addWidget(m_figure2);
    ptb->addWidget(m_add);
    ptb->addWidget(m_delete);
    return ptb;
}

void MainWindow::activate_del(){
    bool fl_ = false;
        for (const auto i : widjets_f2){
            if (i.second->get_status_pressed_2()){
                fl_ = true;
                break;
            }
        }
        for (const auto i :widjets_f1){
            if (i.second->get_status_pressed_1()){
                fl_ = true;
                break;
            }
        }
        if (fl_)
            m_delete->setEnabled(true);
        else
            m_delete->setEnabled(false);
}

void MainWindow::button_F1_pressed(){
    if (buttons_group.button(-2)->isChecked() == true ){
        if (buttons_group.button(-3)->isChecked() == true){
            m_figure2->setChecked(false);
        }
        m_add->setEnabled(true);
    }
    else{
        m_add->setEnabled(false);
    }
}

void MainWindow::button_F2_pressed(){
    if (buttons_group.button(-3)->isChecked() == true){
        if (buttons_group.button(-2)->isChecked() == true){
            m_figure1->setChecked(false);
        }
        m_add->setEnabled(true);
    }
    else{
        m_add->setEnabled(false);
    }
}

void MainWindow::button_add_pressed(){

    if (buttons_group.button(-2)->isChecked() == true){

        Figure *f1 = new Figure(this);
        widjets_f1[index_1] = f1;
        f1->show();
        m_figure2->setChecked(false);
        index_1++;

    }
    if (buttons_group.button(-3)->isChecked() == true){
        Figure2 *f2 = new Figure2(this);
        widjets_f2[index_2] = f2;
        f2->show();
        m_figure1->setChecked(false);
        index_2++;
    }
}

void MainWindow::delete_figure1(){

    if (m_delete->isEnabled()){
        std::vector<int> key;
        for (auto i: widjets_f1){
            if (i.second->get_status_pressed_1()){
                key.push_back(i.first);
                i.second->set_status_pressed_1(false);
                i.second->hide();
              }
        }
    for (auto i : key){
           widjets_f1.erase(i);
     }


    }
}

void MainWindow::delete_figure2(){

    if (m_delete->isEnabled()){
        std::vector<int> key;
        for (auto i: widjets_f2){
            if (i.second->get_status_pressed_2()){
                key.push_back(i.first);
                i.second->set_status_pressed_2(false);
                i.second->hide();
             }
        }
    for (auto i : key){
           widjets_f2.erase(i);

     }

    }
}


