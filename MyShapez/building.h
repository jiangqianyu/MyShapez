#ifndef BUILDING_H
#define BUILDING_H

#include <vector>
#include "vec.h"
#include "Shape.h"
#include "Timer.h"
class GameMap;

class Building
{
public:
    Building();

    /**
     * \brief 建筑的构造函数
     * \param pos 建筑的左上角网格位置
     * \param name 建筑名字，HUB,MINER,BELT_A,BELT_A_S
     * \param direction 建筑图片的方向
     */
    Building(GridVec pos, int name, int direction);

    /**
     * \brief 建筑的物品，CYCLE，RECT，LEFT_CYCLE，RIGHT_CYCLE，NONE
     */
    Shape shape;

    int init_x, init_y;

    /**
     * \brief 建筑的左上角网格位置
     */
    GridVec pos;

    /**
     * \brief 建筑名字，HUB,MINER,BELT_A,BELT_A_S
     */
    int name;

    /**
     * \brief 建筑图片的方向
     */
    int direction;

      /**
     * \brief 重载了==用于判断两个建筑是否相同
     */
    bool operator==(const Building &b) const;

    /**
     * \brief 重载了!=用于判断两个建筑是否不同
     */
    bool operator!=(const Building &b) const;

    /**
     * \brief 用建筑的左上角主网格位置获取建筑所占所有网格位置
     * \return 所有网格位置的vector
     */
    virtual std::vector<GridVec> BuildingAllPos() = 0;

    /**
     * \brief 判断是否可以放置某个建筑
     * \param click 鼠标点击的网格位置
     * \param picdirection 建筑图片方向
     * \param gamemap 地图
     */
    virtual bool CanPlace(GridVec click, int picdirection, GameMap &gamemap);

    /**
     * \brief 判断是否可以接收某个物品
     * \param target 目标网格位置
     * \param directionin 物品进入的方向
     * \param shapename 物品名字
     */
    virtual bool CanReceive(GridVec target, int directionin, int shapename) = 0;

    /**
     * \brief 接收某个物品，把建筑的物品的名字改为接收到的物品的名字
     * \param target 目标网格位置
     * \param directionout 物品进入的方向
     * \param shapename 物品名字
     */
    virtual void Receive(GridVec target, int directionin, int shapename) = 0;

    /**
     * \brief 能否传送某个物品
     * \param source 传送源的网格位置
     * \param directionout 物品出去的方向
     * \param shapename 物品名字
     * \param map 地图
     */
    bool CanSend(GridVec source, int directionout, int shapename, GameMap &map);

    /**
     * \brief 传送某个物品
     * \param source 传送源的网格位置
     * \param directionout 物品出去的方向
     * \param shapename 物品名字
     * \param map 地图
     */
    void Send(GridVec source, int directionout, int shapename, GameMap &map);

    /**
     * \brief 当前工作状态
     */
    int state;

    /**
     * \brief 当前已经running的时间
     */
    time_t running_ms;

    /**
     * \brief 没升级前需要的总时间
     */
    time_t FirstRequire_ms;

    /**
     * \brief 升级后需要的总时间
     */
    time_t SecondRequire_ms;

    /**
     * \brief 建筑自己的计时器，记录running_ms
     */
    Timer timer;

    virtual void TickableRunning() = 0;
    /**
     * \brief 更新建筑的状态
     */
    virtual void UpdateTickableState(GameMap &gamemap) = 0;
};

#endif // BUILDING_H
