#include "HelpScene.h"
#include "config.h"
HelpScene::HelpScene()
{
    return_button.setParent(this);
    return_button.setFixedSize(115, 115);
    return_button.setStyleSheet("QPushButton{image: url(:/res/return.png)}");
    return_button.move(WIDGET_WIDTH - 150, WIDGET_HEIGHT - 150);
    return_button.show();
    setTxt();
}
void HelpScene::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setFont(QFont("楷体", 25, QFont::Bold));
    painter.drawText(WIDGET_WIDTH - 155, WIDGET_HEIGHT - 165, QString("返回游戏"));
}
void HelpScene::setTxt()
{
    QTextEdit *text = new QTextEdit(this);
    text->setPlainText("                           关于本作   \n"
                       "这里是shapez的小demo，类似异形工厂的小游戏。是c++高程大作业。\n"
                       "基本操作:\n"
                       "使用键盘ＷＡＳＤ控制建筑方向，鼠标右键撤销已放置的建筑。\n"
                       "共有四种建筑：\n"
                       "开采器：放置在矿地上后可开采出物品。请注意输出物品的方向。\n"
                       "传送带：运送物品。请注意运送物品的方向。\n"
                       "切割机：将物品纵向切开并分别输出。如果只需要其中一半的物品，那么需要使用垃圾桶清除另一半物品，否则切割机会停止工作。\n"
                       "垃圾桶：可以从所有四个方向上输入物品并永久清除它们。\n"
                       "获胜条件: 每个关卡需收集一定数量的物品，通过四个关卡即可获胜。\n"
                       "每个关卡结束后，可以升级开采器、传送带或切割机中的一个建筑。请注意，升级效果仅在当前关卡有效。\n"
                       "通过消耗金币，可以在商店中全局强化交付中心的大小、开采物所在地块的数量等。\n"
                       "游戏可自动存档。\n"
                       "感谢游玩！");
    text->setReadOnly(true);
    text->setFixedSize(WIDGET_WIDTH, WIDGET_HEIGHT - 200);
    text->setStyleSheet("background: transparent; color: black; border-style: outset; font: bold 36px; font-family: 楷体;");
    text->move(0, 0);
    text->show();
}
