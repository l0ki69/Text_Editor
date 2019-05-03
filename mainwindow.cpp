#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <qstring.h>
#include <QContextMenuEvent>
#include <qfiledialog.h>
#include <QColorDialog>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pFileManager = new File_Manager();
//    pFontSetup = new FontSetup(ui->textEdit);
//    pCompiler = new Compiler();


    connect(ui->createFile, &QAction::triggered, this, &MainWindow::createFileSlot);
    connect(ui->openFile, &QAction::triggered, this, &MainWindow::openFileSlot);
    connect(ui->saveFile, &QAction::triggered, this, &MainWindow::saveFileSlot);
    //connect(ui->saveNowFile, &QAction::triggered, this, &MainWindow::saveNowFileSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
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
  QString path = QFileDialog::getSaveFileName(this, "Создать новый файл", "sampleText");
  pFileManager->currentPath = path;
  pFileManager->createFile(path);
}

/*void MainWindow::saveNowFileSlot() {
  if(pFileManager->currentPath != "")
  {
      QString text = ui->textEdit->toPlainText();
      pFileManager->saveFile(pFileManager->currentPath,text);
  }
}
*/
void MainWindow::saveFileSlot()
{
    QString path = QFileDialog::getSaveFileName(this, "Сохранить файл", pFileManager->fileName, "*.txt  *.cpp *.c *.h");
    if(path != "")
    {
        QString text = ui->textEdit->toPlainText();
        pFileManager->saveFile(path,text);
    }
}
