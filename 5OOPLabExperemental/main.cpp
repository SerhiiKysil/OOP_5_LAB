#include <QApplication>
#include "Game.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Game game;
    game.setWindowTitle("Snake Game");
    game.show();

    return app.exec();
}
