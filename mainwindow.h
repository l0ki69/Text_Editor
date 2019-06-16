#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "file_manager.h"
#include "fontsetup.h"


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
  void saveNowFileSlot();

  void changeFontStyleSlot();
  void changeFontColorSlot();
  void changeFontSizeSlot();
  void changeBackgroundColorSlot();
  void changeBackgroundTextColorSlot();

  void changeSelectSlot();

  void codecUTF8Slot();
  void codecKOI8Slot();
  void codecWindows1251Slot();

private:
    Ui::MainWindow *ui;
    File_Manager* pFileManager;
    FontSetup* pFontSetup;
};

#endif // MAINWINDOW_H
