#ifndef CUTTER_H
#define CUTTER_H

#include "Building.h"

class Cutter : public Building
{
public:
    Cutter();
    Cutter(GridVec pos, int name, int direction);
    std::vector<GridVec> BuildingAllPos() override;
    bool CanPlace(GridVec click, int picdirection, GameMap &gamemap) override;
    bool CanReceive(GridVec target, int directionin, int shapename) override;
    void Receive(GridVec target, int directionin, int shapename) override;
    void TickableRunning() override;
    void UpdateTickableState(GameMap &gamemap) override;
};

#endif // CUTTER_H
