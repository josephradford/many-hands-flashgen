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

        // clear out the flash routines, ready for the new one
        m_flashRoutine->clear();

        // wait for first input
    }
    else {
        // finish off the last key
        m_flashRoutine->stopKeyPress();
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_A:
    case Qt::Key_S:
    case Qt::Key_D:
        if (m_recording && !event->isAutoRepeat()) {
            // next event
            // record pause since last event
            // start recording hold for this event
            m_flashRoutine->startKeyPress(event->key());
        }
        else {
            // we are not acting on it, so pass it on
            QMainWindow::keyPressEvent(event);
        }

        break;

    default:
        // we are not acting on it, so pass it on
        QMainWindow::keyPressEvent(event);
        break;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_A:
    case Qt::Key_S:
    case Qt::Key_D:
        if (m_recording && !event->isAutoRepeat()) {
            // start the pause timer for this event
            // record the hold timer for this event
            m_flashRoutine->stopKeyPress();
        }
        else {
            // we are not acting on it, so pass it on
            QMainWindow::keyReleaseEvent(event);
        }

        break;

    default:
        // we are not acting on it, so pass it on
        QMainWindow::keyReleaseEvent(event);
        break;
    }
}



void MainWindow::on_btn_Record_clicked()
{
    setRecording(true);
}

void MainWindow::on_btn_Stop_clicked()
{
    setRecording(false);
}
