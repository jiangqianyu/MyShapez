// main.cpp是入口文件
#include "WindowControl.h"

#include <QApplication>
#include <QResource>
#include "config.h"

int main(int argc, char *argv[])
{
    // QApplication是qt框架提供的应用程序类
    // 负责事件的处理，比如鼠标单击、键盘输入
    QApplication a(argc, argv);
    // 注册外部资源文件
    QResource::registerResource(GAME_RES_PATH);
    // 创建窗口，并显示
    WindowControl w;
    //    w.show();
    // 进入事件的循环处理，直到退出应用程序
    return a.exec();
}
