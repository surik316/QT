#ifndef CODEEDITOR_H
#define CODEEDITOR_H

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
#include <QTextBlock>
#include <QPlainTextEdit>
class CodeEditor : public QPlainTextEdit{

    Q_OBJECT

public:

    CodeEditor(QWidget *parent = 0);
    void lineNumberAreaPaintEvent(QPaintEvent *event);
    int lineNumberAreaWidth();
    QWidget* getlineNumberArea();
    QColor current_color = "green";
    QColorDialog *lineFontDialog;
    QFontDialog *textFormatDialog;
    void setColorLine();

protected:

    void resizeEvent(QResizeEvent *event);

private slots:

    void updateLineNumberAreaWidth(int newBlockCount);
    void highlightCurrentLine();
    void updateLineNumberArea(const QRect &, int);

private:
    QTextEdit::ExtraSelection selection;
    QWidget *lineNumberArea;

};

#endif
