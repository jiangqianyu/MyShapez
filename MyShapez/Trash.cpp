#include "Trash.h"
#include "gamemap.h"
Trash::Trash()
{
}
Trash::Trash(GridVec pos, int name, int direction) : Building(pos, name, direction)
{
}
std::vector<GridVec> Trash::BuildingAllPos()
{
    // TODO
    std::vector<GridVec> allpos;
    allpos.push_back(pos);
    return allpos;
}
bool Trash::CanPlace(GridVec click, int picdirection, GameMap &gamemap)
{
    // 如果超出地图范围，返回false
    if (pos.i < 0 || pos.i >= HEIGHT || pos.j < 0 || pos.j >= WIDTH)
    {
        return false;
    }
    // 如果在矿地上，或有障碍物，返回false
    if (gamemap.GetResource(pos) != NONE)
    {
        return false;
    }
    // 如果点击的是hub，返回false
    if (gamemap.GetBuilding(pos) != nullptr)
    {
        if (gamemap.GetBuilding(pos)->name == HUB || gamemap.GetBuilding(pos)->name == CUTTER || gamemap.GetBuilding(pos)->name == TRASH)
        {
            return false;
        }
    }
    return true;
}
bool Trash::CanReceive(GridVec source, int directionin, int shapename)
{
    return true;
}
void Trash::Receive(GridVec source, int directionin, int shapename)
{
    return;
}
void Trash::UpdateTickableState(GameMap &gamemap)
{
    return;
}
void Trash::TickableRunning()
{
    return;
}
