#ifndef SHAPE_H
#define SHAPE_H

/**
 * \brief 物品，CYCLE，RECT，LEFT_CYCLE，RIGHT_CYCLE，NONE，每个传送带实例包含一个物品，其他建筑以名字模拟处理物品
 */
typedef struct shape
{
    /**
     * \brief 哪个物品，名字是宏
     */
    int name;
    /**
     * \brief 物品图片中心点横纵坐标,double
     */

    int x0, y0;
} Shape;

#endif // SHAPE_H
