#ifndef MINER_H
#define MINER_H

#include "Building.h"
/**
 * \brief 采矿机
 */
class Miner final : public Building
{
public:
    Miner();
    Miner(GridVec pos, int direction, int name);
    std::vector<GridVec> BuildingAllPos() override;
    bool CanPlace(GridVec click, int picdirection, GameMap &gamemap) override;
    bool CanReceive(GridVec target, int directionin, int shapename) override;
    void Receive(GridVec target, int directionin, int shapename) override;
    void TickableRunning() override;
    int GetDigShapeType(GridVec pos, GameMap &gamemap);
    void UpdateTickableState(GameMap &gamemap) override;
};

#endif // MINER_H
