#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QKeyEvent>
#include <QTimer>
#include "Snake.h"
#include "Apple.h"

class Game : public QWidget {
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    ~Game();

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void onTimeout();

private:
    Snake* snake;
    Apple* apple;
    QTimer* timer;
    bool inGame;

    void initGame();
    void checkApple();
    void checkCollision();
    void gameOver(QPainter &qp);
    void drawGame(QPainter &qp);
};

#endif // GAME_H
