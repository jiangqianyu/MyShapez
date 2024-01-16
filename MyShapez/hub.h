#ifndef HUB_H
#define HUB_H

#include "Building.h"
class Hub final : public Building
{
public:
    Hub();
    Hub(GridVec pos, int name, int direction);

    /**
     * \brief 当前等级需要的物品个数
     */
    int need;

    /**
     * \brief 当前等级需要的物品类型
     */
    int need_shape_name;

    /**
     * \brief 当前等级已提交物品个数
     */
    int current_have;

    int money;

    bool increase_item_value;

    bool upgradehub;

    std::vector<GridVec> BuildingAllPos() override;
    bool CanPlace(GridVec click, int picdirection, GameMap &gamemap) override;
    bool CanReceive(GridVec source, int directionin, int shapename) override;
    void Receive(GridVec source, int directionin, int shapename) override;
    void TickableRunning() override;
    void UpdateTickableState(GameMap &gamemap) override;
    void UpdateNeed();
};

#endif // HUB_H
