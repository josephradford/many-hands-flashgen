#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "flashroutineobject.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_flashRoutine = new FlashRoutineObject;
    m_recording = false;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_flashRoutine;
}

void MainWindow::setRecording(bool recording)
{
    if (m_recording == recording) {
        return;
    }
    if (recording) {
        // start recording
        m_recording = true;

        // wait for first input
    }
}
