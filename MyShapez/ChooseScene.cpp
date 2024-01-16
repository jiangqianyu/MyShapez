#include "ChooseScene.h"
#include "config.h"
ChooseScene::ChooseScene()
{
    ButtonSize = 160;
    choose_miner.setParent(this);
    choose_miner.setFixedSize(ButtonSize, ButtonSize);
    choose_miner.setStyleSheet("QPushButton{image: url(:/res/miner_button.png)}");
    choose_belt.setParent(this);
    choose_belt.setFixedSize(ButtonSize, ButtonSize);
    choose_belt.setStyleSheet("QPushButton{image: url(:/res/belt_button.png)}");
    choose_cutter.setParent(this);
    choose_cutter.setFixedSize(ButtonSize, ButtonSize);
    choose_cutter.setStyleSheet("QPushButton{image: url(:/res/cutter_button.png)}");
}
void ChooseScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setFont(QFont("楷体", 35, QFont::Bold));
    painter.drawText(WIDGET_WIDTH / 2 - 530, (WIDGET_HEIGHT - ButtonSize) / 2 - 35, QString("恭喜通关！请选择希望在下一关升级速度的建筑："));
    choose_miner.move(180 * 1 + ButtonSize * 0, (WIDGET_HEIGHT - ButtonSize) / 2);
    choose_miner.show();
    choose_belt.move(180 * 2 + ButtonSize * 1, (WIDGET_HEIGHT - ButtonSize) / 2);
    choose_belt.show();
    choose_cutter.move(180 * 3 + ButtonSize * 2, (WIDGET_HEIGHT - ButtonSize) / 2);
    choose_cutter.show();
}
