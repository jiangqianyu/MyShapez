#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "config.h"
#include "vec.h"
class Building;

class GameMap
{
public:
    /**
     * \brief 初始化，矿地为none，建筑为空指针
     */
    GameMap();

    /**
     * \brief 升级地图前，地图上哪些单元是矿地
     */
    void FirstMap();
    /**
     * \brief 升级地图后，地图上哪些单元是矿地
     */
    void SecondMap();

    void ClearBarriers();
    /**
     * \brief 地图上哪些单元是矿地
     */
    int Resource[HEIGHT][WIDTH];

    /**
     * \brief 地图每个单元的建筑
     */
    Building *BuildingsMap[HEIGHT][WIDTH];

    /**
     * \brief 获取某个网格位置的资源
     * \param pos 位置
     * \return 资源类型
     */
    int GetResource(GridVec pos);

    /**
     * \brief 在鼠标点击的网格位置放置建筑
     * \param pos 位置
     * \param building 建筑
     * \param direction 图片方向
     * \param name 建筑名字，HUB,MINER,BELT_A,BELT_A_S
     */
    void SetBuilding(GridVec pos, Building *building, int direction, int name);

    /**
     * \brief 获取某个网格位置的建筑
     * \param pos 位置
     * \return 建筑
     */
    Building *GetBuilding(GridVec pos);

    /**
     * \brief 移除某个网格位置的建筑
     * \param pos 位置
     */
    void RemoveBuilding(GridVec pos);

    /**
     * \brief 获取某个网格位置的目标网格位置
     * \param source 源网格位置
     * \param direction 发出方向
     * \return 目标网格位置
     */
    GridVec GetTatget(GridVec source, int directionout);

    /**
     * \brief 获取某个网格位置的相反方向
     * \param direction 方向
     * \return 相反方向
     */
    int OppositeDirection(int direction);
};

#endif // GAMEMAP_H
