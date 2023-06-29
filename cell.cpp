#include "cell.h"
#include <QLabel>
#include <QPixmap>
#include <iostream>

Cell::Cell(QWidget *parent, int x, int y) : QWidget(parent)
{
    this->x = x;
    this->y = y;
    state = empty;
    label = new QLabel(parent);
}

void Cell::putPic(QPixmap pixmap){
    label->setPixmap(pixmap);
    resize(pixmap.width(), pixmap.height());
    label->setGeometry(this->x, this->y, pixmap.width(), pixmap.height());
}

void Cell::putBlackEnemy(QWidget *parent)
{
    QPixmap pixmap = QPixmap(":/images/pink.png");
    putPic(pixmap);
    this->state = enemy;
}
void Cell::putAttackerEnemy(QWidget *parent)
{
    QPixmap pixmap = QPixmap(":/images/red.png");
    putPic(pixmap);
    this->state = enemy;
}
