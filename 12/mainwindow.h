#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QToolBar>
#include <QMenu>
#include <QMenuBar>
#include <QFontDialog>
#include <QBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QColorDialog>
#include <QFileDialog>
#include <QTextCodec>
#include <QMessageBox>
#include <QTextDocumentWriter>
#include <QTextStream>
#include <QStatusBar>
#include <QLabel>
#include <QTextDocument>
#include <QString>
#include <cmath>
#include <QDateTime>
#include<QDebug>
#include <string>
#include <QTextCursor>
#include <QToolButton>

#include "searchhighlight.h"
#include "findandreplace.h"
#include "codeeditor.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:

    CodeEditor *textEdit;

    QToolBar *toolBar;
    QFontDialog *font_selection;

    QString fileName;


    QLabel *len_str;
    QLabel *current_pos;
    QLabel *last_change;
    QDateTime *date_time;
    QDateTime *saved_date_time;
    void createStatusBar();
    bool maybeSave();
    void FileMenu ();
    void EditMenu();
    void FormatMenu();
    void ViewMenu();
    void ReferenceMenu();
    bool load(const QString &f);
    void setCurrentFileName(const QString &fileName);
    SearchHighLight *dialog;
    FindAndReplace *dialog_replace;
    QAction *sb;
    QAction *tb;
    QAction *line_break;
    QAction *line_number;



public:

    MainWindow(QWidget *parent = 0);
    bool isFirstTime;

private slots:

    void SetCurrentTextFormat();
    void SetColorCurrentLine();
    void LineBreakHidden();
    void ToolBarHidden();
    void StatusBarHidden();
    void replaceALL();
    void StatusBarAction();
    void fileNew();
    void fileOpen();
    bool fileSave();
    bool fileSaveAs();
    void findText();
    void trigger_for_highlight();
    void SetFontWindow();
    void trigger_for_replace();
    void SetPalleteColor();
    void HighlightLineHidden();

};
#endif // MAINWINDOW_H
