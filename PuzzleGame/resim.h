#ifndef RESIM_H
#define RESIM_H

#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QDrag>

class resim : public QLabel
{
    Q_OBJECT
public:
    explicit resim(QWidget *parent = 0);
private:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    QPoint baskonum;
    //int index;

signals:

public slots:

};

#endif // RESIM_H
