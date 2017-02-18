#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class FlashRoutineObject;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    FlashRoutineObject *m_flashRoutine;
};

#endif // MAINWINDOW_H
