#include "StartScene.h"
#include "config.h"

StartScene::StartScene()
{
    logo.load(LOGO_PATH);
    // 初始化按钮
    new_game.setParent(this);
    new_game.setFixedSize(250, 150);
    new_game.setStyleSheet("QPushButton{image: url(:/res/new_game.png)}");
    continue_game.setParent(this);
    continue_game.setFixedSize(250, 150);
    continue_game.setStyleSheet("QPushButton{image: url(:/res/continue_game.png)}");
}
void StartScene::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.drawPixmap((WIDGET_WIDTH - 710) / 2, 120, 710, 180, logo);
    new_game.move((WIDGET_WIDTH - 250) / 2, 400);
    new_game.show();
    continue_game.move((WIDGET_WIDTH - 250) / 2, 600);
    continue_game.show();
}
