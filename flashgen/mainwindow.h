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

private slots:
    void setRecording(bool recording);

    void keyPressEvent(QKeyEvent *event);
private:
    Ui::MainWindow *ui;

    FlashRoutineObject *m_flashRoutine;

    bool m_recording;
};

#endif // MAINWINDOW_H
