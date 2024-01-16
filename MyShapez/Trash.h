#ifndef TRASH_H
#define TRASH_H

#include "Building.h"

class Trash : public Building
{
public:
    Trash();
    Trash(GridVec pos, int name, int direction);
    std::vector<GridVec> BuildingAllPos() override;
    bool CanPlace(GridVec click, int picdirection, GameMap &gamemap) override;
    bool CanReceive(GridVec source, int directionin, int shapename) override;
    void Receive(GridVec source, int directionin, int shapename) override;
    void TickableRunning() override;
    void UpdateTickableState(GameMap &gamemap) override;
};

#endif // TRASH_H
