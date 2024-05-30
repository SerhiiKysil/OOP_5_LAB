#include "Game.h"
#include <QPainter>
#include <QTime>

Game::Game(QWidget *parent) : QWidget(parent), inGame(true) {
    setStyleSheet("background-color:black;");
    setFixedSize(300, 300);

    snake = new Snake();
    apple = new Apple(100, 100);
    timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &Game::onTimeout);
    initGame();
}

Game::~Game() {
    delete snake;
    delete apple;
}

void Game::initGame() {
    inGame = true;
    timer->start(140);
}

void Game::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter qp(this);

    if (inGame) {
        drawGame(qp);
    } else {
        gameOver(qp);
    }
}

void Game::keyPressEvent(QKeyEvent *event) {
    int key = event->key();

    if ((key == Qt::Key_Left) && (!snake->isMovingRight())) {
        snake->setDirection(Direction::Left);
    }
    if ((key == Qt::Key_Right) && (!snake->isMovingLeft())) {
        snake->setDirection(Direction::Right);
    }
    if ((key == Qt::Key_Up) && (!snake->isMovingDown())) {
        snake->setDirection(Direction::Up);
    }
    if ((key == Qt::Key_Down) && (!snake->isMovingUp())) {
        snake->setDirection(Direction::Down);
    }

    QWidget::keyPressEvent(event);
}

void Game::onTimeout() {
    if (inGame) {
        checkApple();
        checkCollision();
        snake->move();
    }

    repaint();
}

void Game::checkApple() {
    if (snake->headX() == apple->getX() && snake->headY() == apple->getY()) {
        snake->grow();
        apple->relocate(width() / 10, height() / 10);
    }
}

void Game::checkCollision() {
    if (snake->headX() >= width() || snake->headX() < 0 ||
        snake->headY() >= height() || snake->headY() < 0) {
        inGame = false;
    }

    if (snake->isColliding()) {
        inGame = false;
    }

    if (!inGame) {
        timer->stop();
    }
}

void Game::gameOver(QPainter &qp) {
    QString message = "Game Over";
    QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.horizontalAdvance(message);

    qp.setPen(Qt::white);
    qp.setFont(font);
    int h = height();
    int w = width();

    qp.drawText((w - textWidth) / 2, h / 2, message);
}

void Game::drawGame(QPainter &qp) {
    qp.setBrush(Qt::red);
    qp.drawRect(apple->getX(), apple->getY(), 10, 10);

    for (int i = 0; i < snake->length(); ++i) {
        if (i == 0) {
            qp.setBrush(Qt::green);
        } else {
            qp.setBrush(Qt::white);
        }
        qp.drawRect(snake->getX(i), snake->getY(i), 10, 10);
    }
}
