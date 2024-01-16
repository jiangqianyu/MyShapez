#ifndef ROUNDSCENE_H
#define ROUNDSCENE_H

#include "scene.h"

class RoundScene : public Scene
{
public:
    /**
     * \brief 像素画下载，初始化关卡，初始化确认按钮
     */
    RoundScene();
    // 像素画
    QPixmap cycle_img;
    QPixmap rect_img;
    QPixmap left_cycle_img;
    QPixmap right_cycle_img;
    /**
     * \brief 当前关卡，如1，2，3，4
     */
    int level;
    /**
     * \brief 确认按钮
     */
    QPushButton confirm;
    /**
     * \brief 根据当前关卡，绘制需收集的item、确认按钮
     */
    void paintEvent(QPaintEvent *e);
};

#endif // ROUNDSCENE_H
