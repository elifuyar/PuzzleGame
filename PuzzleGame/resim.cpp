#include "resim.h"

resim::resim(QWidget *parent) :
    QLabel(parent)
{
    setAcceptDrops(true);
}

void resim::mousePressEvent(QMouseEvent *event)
{
     baskonum = event->pos();
    //setText(QString::number(event->x())+"  "+QString::number(event->y()));
}

void resim::mouseMoveEvent(QMouseEvent *event)
{
    /*
    int X = event->x() - baskonum.x() + geometry().x();
    int Y = event->y() - baskonum.y() + geometry().y();
    setGeometry(X,Y,geometry().width(),geometry().height());
    */
    QMimeData *mdata = new QMimeData;
    mdata->setImageData(pixmap()->toImage());
    QDrag *surukle = new QDrag(this);
    surukle->setMimeData(mdata);
    surukle->setPixmap(mdata->imageData().value<QPixmap>());
    surukle->exec(Qt::MoveAction);
}

void resim::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept();
}

void resim::dropEvent(QDropEvent *event)
{
    resim *gelen = qobject_cast<resim*> (event->source());
    if(gelen && gelen != this){
        QImage birakilan(pixmap()->toImage());
        setPixmap(event->mimeData()->imageData().value<QPixmap>());
        gelen->setPixmap(QPixmap::fromImage(birakilan));
    }
    QList<QUrl> url = event->mimeData()->urls();
    if(url.isEmpty())
        return;
    QString path = url.first().toLocalFile();
    QImage dosya(path);
    setPixmap(QPixmap::fromImage(dosya));
    event->accept();
}
