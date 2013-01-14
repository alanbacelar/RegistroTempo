#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QTime>
#include <QDebug>
#include <QDate>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btStart, SIGNAL( clicked() ), this, SLOT(startTempo()) );
    connect(ui->btStop, SIGNAL( clicked() ), this, SLOT(stopTempo()) );

    ui->lcdNumber->display("00:00:00");
    ui->btStop->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startTempo()
{
    QTime tempo;
    mTimer = new QTimer;

    tempo.start();
    mTimer->start();

    connect(mTimer, SIGNAL( timeout() ), this, SLOT(showCurrentTime()) );

    qDebug() << "Tempo foi iniciado em: " << tempo.toString();

    dataIni = tempo.toString();

    ui->btStart->hide();
    ui->btStop->show();

}

void MainWindow::stopTempo()
{
    QTime tempo;
    tempo.start();

    disconnect(mTimer, SIGNAL( timeout() ), this, SLOT(showCurrentTime()) );
    ui->lcdNumber->display("00:00:00");

    qDebug() << "Tempo foi parado em: " << tempo.toString();

    addList(tempo.toString());

    ui->btStart->show();
    ui->btStop->hide();


}

void MainWindow::showCurrentTime(){
    QTime tempo( QTime::currentTime() );
    ui->lcdNumber->display(tempo.toString());
}


void MainWindow::addList(QString tempo)
{
    QDate data = QDate::currentDate();
    QString item = QString("Data: %3 - Hora inicial: %1 - Hora fim: %2").arg(dataIni).arg(tempo).arg(data.toString("dd/MM/yyyy"));

    ui->listWidget->addItem(item);
}


