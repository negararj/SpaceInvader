#include "gamepanel.h"
#include <iostream>
#include <random>

const int SCORE = 10;

GamePanel::GamePanel(QWidget *parent) : QWidget{parent}
{
    this->setFocusPolicy(Qt::StrongFocus);
    score = enemyNumbers = 0;
    make_the_map(parent);
    state = GameState::running;

    init_labels();
}

void GamePanel::update_score(){
    scoreLabel->setText(QString::number(score));
    if(!enemyNumbers){
        state = win;
    }
    if (state == win) {
        win_label->show();
    }else if (state == lose) {
        lose_label->show();
    }
}

void GamePanel::init_labels(){
    score_title = new QLabel(this);
    score_title->setText("score");
    score_title->setStyleSheet("QLabel {font-family: Fixedsys;color: white;font-size: 16px;}");
    score_title->setGeometry(50, 12, 60, 26);

    scoreLabel = new QLabel(this);
    scoreLabel->setIndent(-80);
    scoreLabel->setText("0");
    scoreLabel->setStyleSheet("QLabel {font-family: Fixedsys;color: white;font-size: 16px;}");
    scoreLabel->setGeometry(110, 12, 150, 26);

    win_label = new QLabel(this);
    win_label->hide();
    win_label->setText("You win!");
    win_label->setStyleSheet("QLabel {font-family: Fixedsys;color: green;font-size: 16px;}");
    win_label->setGeometry(310, 12, 150, 26);

    lose_label = new QLabel(this);
    lose_label->hide();
    lose_label->setText("You lose!");
    lose_label->setStyleSheet("QLabel {font-family: Fixedsys;color: red;font-size: 16px;}");
    lose_label->setGeometry(310, 12, 150, 26);

    update_score();
}

void GamePanel::make_the_map(QWidget *parent){
    srand (time(NULL));
    for(int i = 0; i < rows; i ++){
        for(int j = 0; j < columns; j ++){
            map[i][j] = new Cell(parent,50+(20*j),50+(20*i));
            int randomNumber = rand() % 2;
            if(randomNumber){
                map[i][j]->putAttackerEnemy(parent);
                attackers.push_back(map[i][j]);
            }
            else{
                map[i][j]->putBlackEnemy(parent);
            }
            enemyNumbers ++;
        }
    }
}

void GamePanel::keyPressEvent(QKeyEvent* event) {

}
