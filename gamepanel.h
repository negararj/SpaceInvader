#ifndef GAMEPANEL_H
#define GAMEPANEL_H

#include <QWidget>
#include <QLabel>

#include "laser.h"
#include "cell.h"

const int rows = 10, columns = 29;

enum GameState{win, lose, pmode, running};

class GamePanel : public QWidget
{
    Q_OBJECT
public:


    explicit GamePanel(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent *event) override;
    void make_the_map(QWidget *parent = nullptr);
    void init_labels();
    void update_score();

private:
    Laser *laser;
    Cell* map[rows][columns];
    int score, enemyNumbers;
    GameState state;
    std::vector <Cell*> attackers;
    QWidget *parent;
    QLabel *score_title, *scoreLabel;
    QLabel *win_label, *lose_label;
};

#endif // GAMEPANEL_H
