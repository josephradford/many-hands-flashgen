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
    m_recording = recording;
    if (m_recording) {
        // start recording
        m_recording = true;

        // wait for first input
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_A:
    case Qt::Key_S:
    case Qt::Key_D:
        if (!m_recording) {
            // we are not acting on it, so pass it on
            QMainWindow::keyPressEvent(event);
        }
        else {
            if (event->type() == QEvent::KeyPress) {
                // next event
                // record pause since last event
                // start recording hold for this event
            }
            else if (event->type() == QEvent::KeyRelease) {
                // start the pause timer for this event
                // record the hold timer for this event
            }
        }

        break;

    default:
        // we are not acting on it, so pass it on
        QMainWindow::keyPressEvent(event);
        break;
    }
}
