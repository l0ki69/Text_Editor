#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "file_manager.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
  void createFileSlot();
  void openFileSlot();
  void saveFileSlot();
 // void saveNowFileSlot();

private:
    Ui::MainWindow *ui;
    File_Manager* pFileManager;
};

#endif // MAINWINDOW_H
