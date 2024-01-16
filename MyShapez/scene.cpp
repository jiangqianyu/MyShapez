#include "scene.h"
#include "config.h"
Scene::Scene(QWidget *parent)
    : QWidget{parent}
{
    // 设置窗口尺寸
    this->setFixedSize(WIDGET_WIDTH, WIDGET_HEIGHT);
    // 设置窗口图标
    this->setWindowIcon(QIcon(GAME_ICON));
    // 设置窗口名字
    this->setWindowTitle(GAME_TITLE);
    //
    setMouseTracking(true);
}
