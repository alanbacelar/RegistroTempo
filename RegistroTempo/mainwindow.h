#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void startTempo();
    void stopTempo();
    void showCurrentTime();
    void addList(QString tempo);

private:
    Ui::MainWindow *ui;
    QTimer *mTimer;

    QString dataIni;

};

#endif // MAINWINDOW_H
