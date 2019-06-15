#ifndef FONTSETUP_H
#define FONTSETUP_H

#include <QTextEdit>
#include <QColor>
#include <QPalette>
#include <QFontDialog>
#include <QFont>

const int defaultFontSize = 10;
const QFont defaultFontStyle("Comic Sans MS"); // kek
const QColor defaultColor = Qt::black;
const QColor defaultBackgroundColor = Qt::white;
const QColor defaultSelectColor = QColor::fromRgb(0, 120, 215, 255);

class FontSetup
{
public:
    FontSetup(QTextEdit* text);
    ~FontSetup();
    void setFontStyle(const QFont fontStyle);
    void setFontColor(const QColor fontColor);
    void setFontSize(int size);
    void setBackgroundColor(const QColor backgroundColor);
    void setBackgroundTextColor(const QColor);
    void setSelectColor(const QColor selectColor, const QColor selectTextColor);

    QColor fontColor;
    QColor backgroundColor;
    QColor backgroundTextColor;
    QFont fontStyle;
    int fontSize;
    QColor selectColor;

    QTextEdit *setup;
};

#endif // FONTSETUP_H
