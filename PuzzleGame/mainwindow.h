#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "resim.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int matrisilk[4][4];
    int matris[4][4];
    int matriscode[16];
    int resim_Yerleri[4][4];
    QString sayac;
    resim *etiket[4][4];


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    void random_Resim();
    void hazirla();
    void yer_Dogrumu();
};

#endif // MAINWINDOW_H
