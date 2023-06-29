#ifndef CELL_H
#define CELL_H

#include <QWidget>
#include <QLabel>

enum CellState{
    empty, enemy
};

class Cell : public QWidget
{
public:
    Cell(QWidget *parent, int x, int y);
    void putBlackEnemy(QWidget *parent);
    void putAttackerEnemy(QWidget *parent);
    void putPic(QPixmap pixmap);
private:
    int x, y;
    CellState state;
    QWidget *parent;
    QLabel *label;
};

#endif // CELL_H
