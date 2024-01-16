#include "WinScene.h"
#include "config.h"
WinScene::WinScene()
{
    win.load(WIN_PATH);
}
void WinScene::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setFont(QFont("楷体", 35, QFont::Bold));
    painter.drawText((WIDGET_WIDTH - 70) / 2, (WIDGET_HEIGHT - 400) / 2 - 40, QString("Win!"));
    painter.drawPixmap((WIDGET_WIDTH - 400) / 2, (WIDGET_HEIGHT - 400) / 2, 400, 400, win);
}
