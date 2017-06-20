#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    hazirla();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::random_Resim()//Matrise random sayi attiğim kisim
{
    for (int i = 0; i < 16; ++i)
    {
        matriscode[i] = i+1;
    }

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            int randomNumber = qrand() % 16;

            if (matriscode[randomNumber] != -1)
            {
                matris[i][j] = matriscode[randomNumber];
                matriscode[randomNumber] = -1;
            }
            else
            {
                if(randomNumber != 0)
                {
                    for(int k = randomNumber-1; k >= 0; k--)
                    {
                        if(matriscode[k] != -1)
                        {
                            matris[i][j] = matriscode[k];
                            matriscode[k] = -1;
                            break;
                        }
                        else
                        {
                            if (k == 0)
                            {
                                for (int m = randomNumber + 1; m < 16; ++m)
                                {
                                    if(matriscode[m] != -1)
                                    {
                                        matris[i][j] = matriscode[m];
                                        matriscode[m] = -1;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
                else
                {
                    for (int m = randomNumber + 1; m < 16; ++m)
                    {
                        if(matriscode[m] != -1)
                        {
                            matris[i][j] = matriscode[m];
                            matriscode[m] = -1;
                            break;
                        }
                    }
                }
            }
        }
    }
}

void MainWindow::hazirla()
{
    random_Resim();

   int X = 25;
    int Y = 25;

    for(int i = 0; i < 4; i++)//Matrisilk e boş bi resim atıyorum ki ikinci kutu ile birinci kutu arasında resim değişimi yapabileyim.
    {
        for(int j=0; j<4; j++)
        {
            matrisilk[i][j]=0;
           resim *etiket1 = new resim(this);
            etiket1->setGeometry(X,Y,75,75);
            etiket1->setFrameShape(QFrame::Box);
            etiket1->setScaledContents(true);

            QPixmap pixmap("://" + QString::number(matrisilk[i][j]) + ".png");
            etiket1->setPixmap(pixmap);
            etiket1->show();

            X += 75;
        }
        X = 25;
        Y +=75;
    }

    X = 350;
    Y = 25;
    int k=1;

    for(int i = 0; i < 4; i++)//2. kutu //Matrisimize resimleri random fonksiyonundan gelen sayiları atıyoruz.
    {
        for(int j=0; j<4; j++)//O sayilara karşılık gelen resimler matrise atanmış oluyor.
        {
            resim_Yerleri[i][j]=k;//her bir kutuya asıl olması gereken resimlerin numaralarını atıyorum ki karşılaştırma yapabileyim.
            resim *etiket2 = new resim(this);
            etiket2->setGeometry(X,Y,75,75);
            etiket2->setFrameShape(QFrame::Box);
            etiket2->setScaledContents(true);
            //etiket2->index = matris[i][j];

            QPixmap pixmap("://" + QString::number(matris[i][j]) + ".png");
            etiket2->setPixmap(pixmap);
            etiket2->show();
            X += 75;
            k++;
        }
        X = 350;
        Y +=75;
    }
    yer_Dogrumu();
}

void MainWindow::yer_Dogrumu()
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(resim_Yerleri[i][j]==matrisilk[i][j])
            {
                sayac += "+";
                ui->textEdit->setText(sayac);
            }
        }
    }
}


void MainWindow::on_pushButton_clicked()
{
    for(int i= 0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            matris[i][j]=0;
        }
    }
    random_Resim();
    hazirla();
}

void MainWindow::on_pushButton_2_clicked()
{
    int X = 675;
     int Y = 25;
    for(int i = 0; i < 4; i++)
    {
        for(int j=0; j<4; j++)
        {
            resim *etiket3 = new resim(this);
            etiket3->setGeometry(X,Y,75,75);
            etiket3->setFrameShape(QFrame::Box);
            etiket3->setScaledContents(true);

            QPixmap pixmap("://" + QString::number(resim_Yerleri[i][j]) + ".png");
            etiket3->setPixmap(pixmap);
            etiket3->show();
            X += 75;
        }
        X = 675;
        Y +=75;
    }
}
