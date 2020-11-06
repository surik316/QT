#include "mainwindow.h"
#include "searchhighlight.h"
#include "findandreplace.h"
#include <QFontDialog>
#include "linenumberarea.h"
const QString rsrcPath = "/Users/maksimsurkov/Desktop/images";
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){

    dialog = new SearchHighLight;
    dialog_replace = new FindAndReplace;

    textEdit = new CodeEditor(this);

    setCentralWidget(textEdit);
    textEdit->setFocus();
    connect(textEdit,SIGNAL(cursorPositionChanged()),this ,SLOT(StatusBarAction()));

    font_selection = new QFontDialog;
    font_selection->resize(350,50);


    createStatusBar();
    FileMenu();
    EditMenu();
    FormatMenu();
    ViewMenu();
    ReferenceMenu();
}

void MainWindow::FileMenu(){
     toolBar = new QToolBar(this);
     toolBar->setWindowTitle(QString::fromUtf8("Действия с файлом"));
     addToolBar(toolBar);

     QMenu *menu = new QMenu(QString::fromUtf8("Файл"), this);
     menuBar()->addMenu(menu);

     QAction *a;
     QIcon newIcon = QIcon::fromTheme("document-new", QIcon(rsrcPath + "/filenew.png"));
     a = new QAction(newIcon, QString::fromUtf8("&Новый"), this);
     a->setPriority(QAction::LowPriority);
     a->setShortcut(QKeySequence::New);
     connect(a, SIGNAL(triggered()), this, SLOT(fileNew()));
     toolBar->addAction(a);
     menu->addAction(a);

     a = new QAction(QIcon::fromTheme("document-open", QIcon(rsrcPath + "/fileopen.png")), QString::fromUtf8("&Открыть"), this);
     a->setPriority(QAction::LowPriority);
     a->setShortcut(QKeySequence::New);
     connect(a, SIGNAL(triggered()), this, SLOT(fileOpen()));
     toolBar->addAction(a);
     menu->addAction(a);

     a = new QAction(QIcon::fromTheme("document-save", QIcon(rsrcPath + "/filesave.png")), QString::fromUtf8("Сохранить"), this);
     a->setPriority(QAction::LowPriority);
     a->setShortcut(QKeySequence::New);
     connect(a, SIGNAL(triggered()), this, SLOT(fileSave()));
     toolBar->addAction(a);
     menu->addAction(a);

     a = new QAction( QString::fromUtf8("Сохранить как"), this);
     a->setPriority(QAction::LowPriority);
     a->setShortcut(QKeySequence::New);
     connect(a, SIGNAL(triggered()), this, SLOT(fileSaveAs()));
     menu->addAction(a);

     a = new QAction( QString::fromUtf8("Выход"), this);
     a->setPriority(QAction::LowPriority);
     a->setShortcut(QKeySequence::New);
     connect(a, SIGNAL(triggered()), this, SLOT(close()));
     menu->addAction(a);
}

void MainWindow::EditMenu(){

     toolBar->setWindowTitle(QString::fromUtf8("Работа с файлом"));
     addToolBar(toolBar);

     QMenu *menu = new QMenu(QString::fromUtf8("Правка"), this);
     menuBar()->addMenu(menu);

     QAction *a;

     a = new QAction(QIcon::fromTheme("undo", QIcon(rsrcPath + "/editundo.png")),QString::fromUtf8("Отменить"), this);
     a->setPriority(QAction::LowPriority);
     a->setShortcut(QKeySequence::New);
     connect(a, SIGNAL(triggered()), textEdit, SLOT(undo()));
     toolBar->addAction(a);
     menu->addAction(a);

     a = new QAction(QIcon::fromTheme("redo", QIcon(rsrcPath + "/editredo.png")),QString::fromUtf8("Повторить"), this);
     a->setPriority(QAction::LowPriority);
     a->setShortcut(QKeySequence::New);
     connect(a, SIGNAL(triggered()), textEdit, SLOT(redo()));
     toolBar->addAction(a);
     menu->addAction(a);

     a = new QAction(QIcon::fromTheme("copy", QIcon(rsrcPath + "/editcopy.png")), QString::fromUtf8("Копировать"), this);
     a->setPriority(QAction::LowPriority);
     a->setShortcut(QKeySequence::New);
     connect(a, SIGNAL(triggered()), textEdit, SLOT(copy()));
     toolBar->addAction(a);
     menu->addAction(a);

     a = new QAction(QIcon::fromTheme("cut", QIcon(rsrcPath + "/editcut.png")), QString::fromUtf8("Вырезать"), this);
     a->setPriority(QAction::LowPriority);
     a->setShortcut(QKeySequence::New);
     connect(a, SIGNAL(triggered()), textEdit, SLOT(cut()));
     toolBar->addAction(a);
     menu->addAction(a);

     a = new QAction(QIcon::fromTheme("paste", QIcon(rsrcPath + "/editpaste.png")), QString::fromUtf8("Вставить"), this);
     a->setPriority(QAction::LowPriority);
     a->setShortcut(QKeySequence::New);
     connect(a, SIGNAL(triggered()), textEdit, SLOT(paste()));
     toolBar->addAction(a);
     menu->addAction(a);


     QMenu *toolButton_menu = new QMenu(QString::fromUtf8("Найти/Найти и заменить"));
     QToolButton* toolButton = new QToolButton();
     toolButton->setIcon(QIcon(rsrcPath + "/editfind.png"));
     toolButton->setMenu(toolButton_menu);

     a = new QAction( QString::fromUtf8("Найти"), this);
     a->setPriority(QAction::LowPriority);
     a->setShortcut(QKeySequence::New);
     connect(a, SIGNAL(triggered()), this, SLOT(trigger_for_highlight()));
     menu->addAction(a);
     toolButton_menu->addAction(a);

     a = new QAction( QString::fromUtf8("Найти и заменить"), this);
     a->setPriority(QAction::LowPriority);
     a->setShortcut(QKeySequence::New);
     connect(a, SIGNAL(triggered()), this, SLOT(trigger_for_replace()));
     menu->addAction(a);
     toolButton_menu->addAction(a);
     toolButton->setPopupMode(QToolButton::InstantPopup);
      toolBar->addWidget(toolButton);

     a = new QAction( QString::fromUtf8("Выделить все"), this);
     a->setPriority(QAction::LowPriority);
     a->setShortcut(QKeySequence::New);
     connect(a, SIGNAL(triggered()), textEdit, SLOT(selectAll()));
     menu->addAction(a);
}

void MainWindow::FormatMenu(){

     QMenu *menu = new QMenu(QString::fromUtf8("Формат"), this);
     menuBar()->addMenu(menu);

     QAction *a;

     line_break = new QAction( QString::fromUtf8("Перенос по словам"), this);
     line_break->setPriority(QAction::LowPriority);
     line_break->setShortcut(QKeySequence::New);
     line_break->setCheckable(true);
     connect(line_break, SIGNAL(triggered()), this, SLOT(LineBreakHidden()));
     menu->addAction(line_break);

     a = new QAction( QString::fromUtf8("Выбор шрифта"), this);
     a->setPriority(QAction::LowPriority);
     a->setShortcut(QKeySequence::New);
     connect(a, SIGNAL(triggered()), this, SLOT(SetCurrentTextFormat()));
     menu->addAction(a);
}

void MainWindow::ViewMenu(){
    QMenu *menu = new QMenu(QString::fromUtf8("Вид"), this);
    menuBar()->addMenu(menu);

    QAction *a;
    a = new QAction( QString::fromUtf8("Выбор цвета фона"), this);
    a->setPriority(QAction::LowPriority);
    a->setShortcut(QKeySequence::New);
    connect(a, SIGNAL(triggered()), this, SLOT(SetPalleteColor()));
    menu->addAction(a);

    a = new QAction( QString::fromUtf8("Выбор цвета текущей строки"), this);
    a->setPriority(QAction::LowPriority);
    a->setShortcut(QKeySequence::New);
    connect(a, SIGNAL(triggered()), this, SLOT(SetColorCurrentLine()));
    menu->addAction(a);

    line_number = new QAction( QString::fromUtf8("Отображение нумерации строк"), this);
    line_number->setCheckable(true);
    line_number->setPriority(QAction::LowPriority);
    line_number->setShortcut(QKeySequence::New);
    connect(line_number, SIGNAL(triggered()), this, SLOT(HighlightLineHidden()));
    menu->addAction(line_number);

    tb = new QAction( QString::fromUtf8("Отображение панели инструментов"), this);
    tb->setCheckable(true);
    tb->setPriority(QAction::LowPriority);
    tb->setShortcut(QKeySequence::New);
    connect(tb, SIGNAL(triggered()), this, SLOT(ToolBarHidden()));
    menu->addAction(tb);

    sb  = new QAction( QString::fromUtf8("Отображение строки состояния"), this);
    sb ->setCheckable(true);
    sb ->setPriority(QAction::LowPriority);
    sb ->setShortcut(QKeySequence::New);
    connect(sb , SIGNAL(triggered()), this, SLOT(StatusBarHidden()));
    menu->addAction(sb);

    a = new QAction( QString::fromUtf8("Подсветка синтаксиса"), this);
    a->setCheckable(true);
    a->setPriority(QAction::LowPriority);
    a->setShortcut(QKeySequence::New);
    //connect(a, SIGNAL(triggered()), this, SLOT(SetColor()));
    menu->addAction(a);

    QMenu *window_syntax = new QMenu(QString::fromUtf8("Выбор синтаксиса"));
    //connect(a, SIGNAL(triggered()), this, SLOT(SetColor()));
    menu->addMenu(window_syntax);

    QMenu *syntax_setting = new QMenu(QString::fromUtf8("Выбор/Редактирование стиля подсветки"));
    //connect(a, SIGNAL(triggered()), this, SLOT(SetColor()));
    menu->addMenu(syntax_setting);
}

void MainWindow::ReferenceMenu(){
    QMenu *a = new QMenu(QString::fromUtf8("Справка"), this);
    menuBar()->addMenu(a);
}

bool MainWindow::fileSave()
 {

     if (fileName.isEmpty()){
        return fileSaveAs();
     }
     QFile file(fileName);
     if (file.open(QFile::WriteOnly)){
         file.write(textEdit->toPlainText().toUtf8());
     }
     current_pos->setText((date_time->currentDateTime()).toString("yyyy-MM-dd")+" " + (date_time->currentDateTime()).toString("HH-mm"));
     return 0;
}

bool MainWindow::fileSaveAs(){
    QString file_name = QFileDialog::getSaveFileName(this, tr("Save as..."),"/Users/maksimsurkov/");
    if (file_name.isEmpty()){
       return false;
    }
    setCurrentFileName(file_name);
    return fileSave();
}

void MainWindow::fileNew(){
    textEdit->clear();
    setCurrentFileName(QString());
}

void MainWindow::fileOpen(){
    QString  file_name = QFileDialog::getOpenFileName(this, tr("Open File..."),"/Users/maksimsurkov/");
    if (!file_name.isEmpty()){
         load(file_name);
    }

}

void MainWindow::StatusBarAction(){

    len_str ->setText("Число символов: " + QString::number(textEdit->toPlainText().size())
                      + " Число строк: " + QString::number(textEdit->document()->blockCount())
                      +" Число слов: "+ QString::number(textEdit->toPlainText().split(QRegExp("(\\s|\\n|\\r)+"), QString::SkipEmptyParts).count())
                      +" | "+ QString::number(floor(double(1000*(textEdit->toPlainText().size())*8)/1024 + 0.5)/1000) );

    current_pos->setText("Строка: "+QString::number((textEdit->textCursor().blockNumber())/*- textEdit->textCursor().positionInBlock()*/)
                         + " Столбец: " +QString::number(textEdit->textCursor().positionInBlock()));
    last_change->setText((date_time->currentDateTime()).toString("HH-mm"));

}

void MainWindow::createStatusBar(){

     len_str = new QLabel("Число символов: " + QString::number(textEdit->toPlainText().size())
                          + " Число строк: " + QString::number(textEdit->document()->blockCount())
                          +" Число слов: "+ QString::number(textEdit->toPlainText().split(QRegExp("(\\s|\\n|\\r)+"), QString::SkipEmptyParts).count())
                          +" | "+ QString::number(floor(double(1000*(textEdit->toPlainText().size())*8)/1024 + 0.5)/1000) );

     current_pos = new QLabel("Строка: "+QString::number((textEdit->textCursor().blockNumber())/*- textEdit->textCursor().positionInBlock()*/ )
                              + " Столбец: " +QString::number(textEdit->textCursor().positionInBlock()));
     last_change = new QLabel("Неизменено");

     statusBar()->addWidget(last_change);

     statusBar()->addWidget(current_pos);

     statusBar()->addWidget(len_str);


}

void MainWindow::SetFontWindow(){
    font_selection->exec();
}

void MainWindow::SetPalleteColor(){
    QColorDialog* d = new QColorDialog (this);
    d -> exec();
    QPalette p = textEdit->palette();
    p.setColor(QPalette::Active, QPalette::Base, d->selectedColor());
    p.setColor(QPalette::Inactive, QPalette::Base, Qt::white);
    textEdit->setPalette(p);
}

void MainWindow::trigger_for_highlight(){

    if (!dialog){
        dialog = new SearchHighLight;
    }
    dialog -> show();
    connect(dialog, SIGNAL(accepted()),this,SLOT(findText()));

}

void MainWindow::replaceALL(){
    textEdit->insertPlainText((textEdit->toPlainText()).replace(dialog_replace->getLine(), dialog_replace->get_replace_line()));
}

void MainWindow::findText(){
    QString str = dialog->getLine();
    QTextDocument *document = textEdit->document();
    bool found = false;

    QTextCursor highlightCursor(document);
    QTextCursor cursor(document);

    cursor.beginEditBlock();

    QTextCharFormat plainFormat(highlightCursor.charFormat());
    QTextCharFormat colorFormat = plainFormat;
    colorFormat.setForeground(Qt::red);

    while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {

        highlightCursor = document->find(str, highlightCursor, QTextDocument::FindWholeWords);

        if (!highlightCursor.isNull()) {
            found = true;
            highlightCursor.movePosition(QTextCursor::WordRight, QTextCursor::KeepAnchor);
            highlightCursor.mergeCharFormat(colorFormat);
        }
    }
    cursor.endEditBlock();
    isFirstTime = false;
    if (found == false) {
        QMessageBox::information(this, tr("Word Not Found"),
        "Sorry, the word cannot be found.");
    }


}

void MainWindow::trigger_for_replace(){
    if (!dialog_replace){
        dialog_replace = new FindAndReplace;
    }
    dialog_replace -> show();
    connect(dialog_replace, SIGNAL(signal_replace()),this,SLOT(replaceALL()));
}

void MainWindow::setCurrentFileName(const QString &fileName)
 {
     this->fileName = fileName;
     textEdit->document()->setModified(false);

     QString shownName;
     if (fileName.isEmpty())
         shownName = "untitled.txt";
     else
         shownName = QFileInfo(fileName).fileName();

     setWindowTitle(tr("%1[*] - %2").arg(shownName).arg(QString::fromUtf8("Editor Text")));
     setWindowModified(false);

}

bool MainWindow::load(const QString &f)
 {
     if (!QFile::exists(f)){
         return false;
     }
     QFile file(f);
     if (!file.open(QFile::ReadOnly)){
         return false;
     }

     QByteArray data = file.readAll();
     QString str = QString::fromLocal8Bit(data);
     textEdit->setPlainText(str);
     setCurrentFileName(f);
     return true;
 }

void MainWindow::StatusBarHidden(){
    if (sb->isChecked()){
        statusBar()->hide();
    }
    else{
        statusBar()->show();
    }
}

void MainWindow::ToolBarHidden(){
    if (tb->isChecked()){
        toolBar->hide();
    }
    else{
        toolBar->show();
    }
}

void MainWindow::LineBreakHidden(){
    if (line_break->isChecked()){
        textEdit->setWordWrapMode(QTextOption::NoWrap);
    }
    else{
        textEdit->setWordWrapMode(QTextOption::WordWrap);
    }
}

void MainWindow::HighlightLineHidden(){
    if (line_number->isChecked()){
        textEdit->getlineNumberArea()->hide();
    }
    else{
        textEdit->getlineNumberArea()->show();
    }
}

void MainWindow::SetColorCurrentLine(){
   textEdit->setColorLine();
}

void MainWindow::SetCurrentTextFormat(){

    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont("Times", 12), this);
    if (ok) {
        textEdit->setFont(font);

    }
}

