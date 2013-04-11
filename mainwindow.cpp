#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <QString>
#include <QFileDialog>
#include <opencv2/opencv.hpp>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Open movie"), "",
                                                    tr("mp4(*.mp4);;AllFiles(*)"));

    ui -> lineEdit -> setText(filename);

    mov.openmovie(filename);
}
