#include "Building.h"
#include "config.h"
#include "GameMap.h"
Building::Building()
{
    shape.name = NONE;
    state = EMPTY;
    running_ms = 0;
    timer.Reset();
}
Building::Building(GridVec pos, int name, int direction)
{
    this->pos = pos;
    this->name = name;
    this->direction = direction;
    shape.name = NONE;
    state = EMPTY;
    running_ms = 0;
    timer.Reset();
}
bool Building::operator==(const Building &b) const
{
    return (this->pos.i == b.pos.i && this->pos.j == b.pos.j);
}
bool Building::operator!=(const Building &b) const
{
    return !(this == &b);
}
bool Building::CanPlace(GridVec click, int picdirection, GameMap &gamemap)
{
    // miner重载
    // 如果超出地图范围，返回false
    if (click.i < 0 || click.i >= HEIGHT || click.j < 0 || click.j >= WIDTH)
    {
        return false;
    }
    // 如果在矿地上，或有障碍物，返回false
    if (gamemap.GetResource(click) != NONE)
    {
        return false;
    }
    //    // 如果点击的是hub，返回false
    //    if(gamemap.GetBuilding(click) != nullptr)
    //    {
    //        if(gamemap.GetBuilding(click)->name == HUB)
    //        {
    //            return false;
    //        }
    //    }
    // 如果有其他建筑，返回false
    std::vector<GridVec> allpos = BuildingAllPos();
    for (auto pos : allpos)
    {
        if (gamemap.GetBuilding(pos) != nullptr)
        {
            return false;
        }
    }
    return true;
}
bool Building::CanSend(GridVec source, int directionout, int shapename, GameMap &map)
{
    // TODO
    if (this->name == HUB || this->name == TRASH)
    {
        return false;
    }
    GridVec target = map.GetTatget(source, directionout);
    if (target.i < 0 || target.i >= HEIGHT || target.j < 0 || target.j >= WIDTH)
    {
        return false;
    }
    if (map.GetBuilding(target) == nullptr)
    {
        return false;
    }
    if (map.GetBuilding(target)->CanReceive(target, directionout, shapename))
    {
        return true;
    }
    return false;
}
void Building::Send(GridVec source, int directionout, int shapename, GameMap &map)
{
    // TODO
    GridVec target = map.GetTatget(source, directionout);
    map.GetBuilding(target)->Receive(target, directionout, shapename);
    this->shape.name = NONE;
}
