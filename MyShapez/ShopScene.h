#ifndef SHOPSCENE_H
#define SHOPSCENE_H

#include "scene.h"

class ShopScene : public Scene
{
public:
    /**
     * \brief 初始化按钮、按钮大小
     */
    ShopScene();
    /**
     * \brief 购买更大的hub按钮
     */
    QPushButton bigger_hub;
    /**
     * \brief 清除所有障碍物按钮
     */
    QPushButton clear_barriers;
    /**
     * \brief 增加矿地按钮
     */
    QPushButton increase_mine;
    /**
     * \brief 增加所有item价值按钮
     */
    QPushButton increase_item_value;
    /**
     * \brief 按钮大小
     */
    int ButtonSize;
    /**
     * \brief 增加所有item价值按钮
     */
    QPushButton return_button;
    /**
     * \brief 绘制4个全局加强选项，更大的hub，清除障碍，增加矿地，升级item
     */
    void paintEvent(QPaintEvent *e);
};

#endif // SHOPSCENE_H
