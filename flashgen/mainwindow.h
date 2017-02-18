#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class FlashRoutines;

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
    void keyReleaseEvent(QKeyEvent *event);

    void on_btn_Record_clicked();
    void on_btn_Stop_clicked();

    void on_btn_Refresh_clicked();

private:
    Ui::MainWindow *ui;

    FlashRoutines *m_flashRoutine;

    bool m_recording;
    void updateCode();
};

#endif // MAINWINDOW_H
