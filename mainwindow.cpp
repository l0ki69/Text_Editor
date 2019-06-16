#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <qstring.h>
#include <QContextMenuEvent>
#include <qfiledialog.h>
#include <QColorDialog>
#include <QInputDialog>
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pFileManager = new File_Manager();
    pFontSetup = new FontSetup(ui->textEdit);


    connect(ui->createFile, &QAction::triggered, this, &MainWindow::createFileSlot);
    connect(ui->openFile, &QAction::triggered, this, &MainWindow::openFileSlot);
    connect(ui->saveFile, &QAction::triggered, this, &MainWindow::saveFileSlot);

    connect(ui->changeFontSize, &QAction::triggered, this, &MainWindow::changeFontSizeSlot);
    connect(ui->changeFontStyle, &QAction::triggered, this, &MainWindow::changeFontStyleSlot);
    connect(ui->changeFontColor, &QAction::triggered, this, &MainWindow::changeFontColorSlot);
    connect(ui->changeBackgroundColor, &QAction::triggered, this, &MainWindow::changeBackgroundColorSlot);
    connect(ui->changeBackgroundTextColor, &QAction::triggered, this, &MainWindow::changeBackgroundTextColorSlot);
    connect(ui->changeSelect, &QAction::triggered, this, &MainWindow::changeSelectSlot);

    connect(ui->action_UTF_8, &QAction::triggered, this, &MainWindow::codecUTF8Slot);
    connect(ui->action_KOI8_R, &QAction::triggered, this, &MainWindow::codecKOI8Slot);
    connect(ui->action_Windows_1251, &QAction::triggered, this, &MainWindow::codecWindows1251Slot);

    pFontSetup->setFontStyle(defaultFontStyle);
    pFontSetup->setFontSize(defaultFontSize);
    pFontSetup->setSelectColor(defaultSelectColor, defaultBackgroundColor);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete pFileManager;
    delete pFontSetup;
}

void MainWindow::openFileSlot()
{
    QString path = QFileDialog::getOpenFileName(this, "Открыть файл", pFileManager->fileName, "*.txt *.cpp *.c *.h");
    pFileManager->currentPath = path;
    if(path != "")
    {
       QString text = pFileManager->openFile(path);
       ui->textEdit->setPlainText(text);
    }
}

void MainWindow::createFileSlot()
{
  QString path = QFileDialog::getSaveFileName(this, "Создать новый файл", "Newfile");
  pFileManager->currentPath = path;
  pFileManager->createFile(path);
}

void MainWindow::saveNowFileSlot() {
  if(pFileManager->currentPath != "")
  {
      QString text = ui->textEdit->toPlainText();
      pFileManager->saveFile(pFileManager->currentPath,text);
  }
}


void MainWindow::saveFileSlot()
{
    QString path = QFileDialog::getSaveFileName(this, "Сохранить файл", pFileManager->fileName, "*.txt  *.cpp *.c *.h");
    if(path != "")
    {
        QString text = ui->textEdit->toPlainText();
        pFileManager->saveFile(path,text);
    }
}

void MainWindow::changeFontSizeSlot()
{
    pFontSetup->setFontSize(QInputDialog::getInt(this, "Изменить размер текста","Лучше не меняй", pFontSetup->fontSize, 1, 100));
}

void MainWindow::changeFontColorSlot()
{
    pFontSetup->setFontColor(QColorDialog::getColor(pFontSetup->fontColor,this));
}

void MainWindow::changeFontStyleSlot()
{
    pFontSetup->setFontStyle(QFontDialog::getFont(nullptr, pFontSetup->fontStyle, this));
}

void MainWindow::changeBackgroundColorSlot()
{
    pFontSetup->setBackgroundColor(QColorDialog::getColor(pFontSetup->backgroundColor,this));
}

void MainWindow::changeBackgroundTextColorSlot()
{
    pFontSetup->setBackgroundTextColor(QColorDialog::getColor(pFontSetup->backgroundTextColor,this));
}


void MainWindow::changeSelectSlot()
{
    pFontSetup->setSelectColor(QColorDialog::getColor(pFontSetup->selectColor,this), defaultBackgroundColor);
}

void MainWindow::codecUTF8Slot()
{
  QString text = ui->textEdit->toPlainText();
  QTextCodec *codec = QTextCodec::codecForName("UTF-8");
  QByteArray byteArray;
  QDataStream in(&byteArray, QIODevice::ReadOnly);
  in >> byteArray;
  byteArray = codec->fromUnicode(text);
  text = byteArray;
  ui->textEdit->setPlainText(text);
}

void MainWindow::codecKOI8Slot()
{
  QString text = ui->textEdit->toPlainText();
  QTextCodec *codec = QTextCodec::codecForName("KOI8-R");
  QByteArray byteArray;
  QDataStream in(&byteArray, QIODevice::ReadOnly);
  in >> byteArray;
  byteArray = codec->fromUnicode(text);
  text = byteArray;
  ui->textEdit->setPlainText(text);
}

void MainWindow::codecWindows1251Slot()
{
  QString text = ui->textEdit->toPlainText();
  QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
  QByteArray byteArray;
  QDataStream in(&byteArray, QIODevice::ReadOnly);
  in >> byteArray;
  byteArray = codec->fromUnicode(text);
  text = byteArray;
  ui->textEdit->setPlainText(text);
}
