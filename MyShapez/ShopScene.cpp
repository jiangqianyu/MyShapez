#include "ShopScene.h"
#include "config.h"
ShopScene::ShopScene()
{
    // 初始化按钮大小
    ButtonSize = (WIDGET_WIDTH - 5 * 100) / 4;
    // 初始化按钮
    bigger_hub.setParent(this);
    bigger_hub.setFixedSize(ButtonSize, ButtonSize);
    bigger_hub.setStyleSheet("QPushButton{image: url(:/res/bigger_hub.png)}");
    clear_barriers.setParent(this);
    clear_barriers.setFixedSize(ButtonSize, ButtonSize);
    clear_barriers.setStyleSheet("QPushButton{image: url(:/res/clear_barriers.png)}");
    increase_mine.setParent(this);
    increase_mine.setFixedSize(ButtonSize, ButtonSize);
    increase_mine.setStyleSheet("QPushButton{image: url(:/res/increase_mine.png)}");
    increase_item_value.setParent(this);
    increase_item_value.setFixedSize(ButtonSize, ButtonSize);
    increase_item_value.setStyleSheet("QPushButton{image: url(:/res/increase_item_value.png)}");
    return_button.setParent(this);
    return_button.setFixedSize(115, 115);
    return_button.setStyleSheet("QPushButton{image: url(:/res/return.png)}");
}
void ShopScene::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setFont(QFont("楷体", 25, QFont::Bold));
    // 更大的hub
    painter.drawText(100 * 1 + ButtonSize * 0 + 14, WIDGET_HEIGHT / 2 - 120, QString("更大的hub"));
    bigger_hub.move(100 * 1 + ButtonSize * 0, WIDGET_HEIGHT / 2 - 100);
    bigger_hub.show();
    painter.drawText(100 * 1 + ButtonSize * 0 + 27, WIDGET_HEIGHT / 2 + 100, QString("￥ ") + QString::number(BIGGER_HUB));
    // 清空障碍
    painter.drawText(100 * 2 + ButtonSize * 1 + 14, WIDGET_HEIGHT / 2 - 120, QString("清空障碍"));
    clear_barriers.move(100 * 2 + ButtonSize * 1, WIDGET_HEIGHT / 2 - 100);
    clear_barriers.show();
    painter.drawText(100 * 2 + ButtonSize * 1 + 27, WIDGET_HEIGHT / 2 + 100, QString("￥ ") + QString::number(CLEAR_BARRIERS));
    // 增加矿地
    painter.drawText(100 * 3 + ButtonSize * 2 + 14, WIDGET_HEIGHT / 2 - 120, QString("增加矿地"));
    increase_mine.move(100 * 3 + ButtonSize * 2, WIDGET_HEIGHT / 2 - 100);
    increase_mine.show();
    painter.drawText(100 * 3 + ButtonSize * 2 + 27, WIDGET_HEIGHT / 2 + 100, QString("￥ ") + QString::number(INCREASE_MINE));
    // 升级item
    painter.drawText(100 * 4 + ButtonSize * 3 + 14, WIDGET_HEIGHT / 2 - 120, QString("升级item"));
    increase_item_value.move(100 * 4 + ButtonSize * 3, WIDGET_HEIGHT / 2 - 100);
    increase_item_value.show();
    painter.drawText(100 * 4 + ButtonSize * 3 + 27, WIDGET_HEIGHT / 2 + 100, QString("￥ ") + QString::number(INCREASE_ITEM_VALUE));
    // 返回游戏
    painter.drawText(WIDGET_WIDTH - 155, WIDGET_HEIGHT - 165, QString("离开商店"));
    return_button.move(WIDGET_WIDTH - 150, WIDGET_HEIGHT - 150);
    return_button.show();
}
