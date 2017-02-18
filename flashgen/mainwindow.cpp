#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "flashroutineobject.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_flashRoutine = new FlashRoutines;
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
        m_flashRoutine->stopRecording();
        updateCode();
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

void MainWindow::on_btn_Refresh_clicked()
{
    updateCode();
}


void MainWindow::updateCode()
{
    // print out the code as it would be printed out for Arduino

    // clear first
    ui->txt_Output->clear();

    QString chan = ui->txt_flashChannelVarName->text();
    QString hold = ui->txt_flashHoldVarName->text();
    QString pause = ui->txt_flashPauseVarName->text();
    QString flash = ui->txt_flashVarName->text();
    QString flashRoutine = ui->txt_flashRoutineVarName->text();
    QString flashRoutineIdx = ui->txt_flashRoutineIdx->text();

    int ctr = 0;

    QString str = QString("%1[%2].%3").arg(flashRoutine).arg(flashRoutineIdx).arg(flash);
    foreach (FlashObject flash, m_flashRoutine->flashes) {

        QString str2 = QString("%1[%2].").arg(str).arg(QString::number(ctr));

        QString str3 = QString("%1%2 = %3;").arg(str2).arg(chan).arg(flash.channel);
        ui->txt_Output->appendPlainText(str3);
        str3 = QString("%1%2 = %3;").arg(str2).arg(hold).arg(flash.hold);
        ui->txt_Output->appendPlainText(str3);
        str3 = QString("%1%2 = %3;").arg(str2).arg(pause).arg(flash.pause);
        ui->txt_Output->appendPlainText(str3);
        ui->txt_Output->appendPlainText("");

        ctr++;
    }
}

