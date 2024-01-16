#ifndef BELT_H
#define BELT_H
#include "Building.h"
/**
 * \brief 传送带
 */
class Belt final : public Building
{
public:
    /**
     * \brief 传送带的输入方向
     */
    int in;

    /**
     * \brief 传送带的输出方向
     */
    int out;

    Belt();
    Belt(GridVec pos, int name, int direction);
    std::vector<GridVec> BuildingAllPos() override;
    bool CanReceive(GridVec target, int directionin, int shapename) override;
    void Receive(GridVec target, int directionin, int shapename) override;
    void TickableRunning() override;
    void UpdateTickableState(GameMap &gamemap) override;
};
#endif // BELT_H
