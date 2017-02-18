#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "flashroutineobject.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_flashRoutine = new FlashRoutineObject;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_flashRoutine;
}
