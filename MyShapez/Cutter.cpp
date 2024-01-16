#include "Cutter.h"
#include "GameMap.h"
Cutter::Cutter()
{
    FirstRequire_ms = 2700;
    SecondRequire_ms = 1800;
}
Cutter::Cutter(GridVec pos, int name, int direction)
    : Building(pos, name, direction)
{
    FirstRequire_ms = 2700;
    SecondRequire_ms = 1800;
}
std::vector<GridVec> Cutter::BuildingAllPos()
{
    GridVec temp;
    std::vector<GridVec> allpos;
    allpos.push_back(pos);
    switch (direction)
    {
    case UP:
        temp.j = pos.j + 1;
        temp.i = pos.i;
        break;
    case DOWN:
        temp.j = pos.j - 1;
        temp.i = pos.i;
        break;
    case LEFT:
        temp.j = pos.j;
        temp.i = pos.i - 1;
        break;
    case RIGHT:
        temp.j = pos.j;
        temp.i = pos.i + 1;
        break;
    default:
        break;
    }
    allpos.push_back(temp);
    return allpos;
}
bool Cutter::CanPlace(GridVec click, int picdirection, GameMap &gamemap)
{
    for (auto pos : BuildingAllPos())
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
    }
    return true;
}
bool Cutter::CanReceive(GridVec target, int directionin, int shapename)
{
    if (state == EMPTY)
    {
        if (directionin == direction)
        {
            if (shapename == CYCLE)
            {
                return true;
            }
        }
    }
    return false;
}
void Cutter::Receive(GridVec target, int directionin, int shapename)
{
    this->shape.name = shapename;
    this->state = RUNNING;
    this->timer.Reset();
}
void Cutter::TickableRunning()
{

    this->timer.UpdateRuningTime(FirstRequire_ms);
    running_ms = this->timer.running_ms;
    return;
}
void Cutter::UpdateTickableState(GameMap &gamemap)
{

    switch (state)
    {
    case EMPTY:
        running_ms = 0;
        break;
    case RUNNING:
        if (running_ms >= FirstRequire_ms)
        {
            // cutter好了，准备运输
            state = BLOCK;
            running_ms = 0;
        }
        else
        {
            this->TickableRunning();
        }
        break;
    case BLOCK:
        switch (direction)
        {
        case UP:
        case RIGHT:
            if (this->CanSend(BuildingAllPos()[0], direction, LEFT_CYCLE, gamemap) && this->CanSend(BuildingAllPos()[1], direction, RIGHT_CYCLE, gamemap))
            {
                this->Send(BuildingAllPos()[0], direction, LEFT_CYCLE, gamemap);
                this->Send(BuildingAllPos()[1], direction, RIGHT_CYCLE, gamemap);
                state = EMPTY;
                this->shape.name = NONE;
            }
            break;
        case DOWN:
        case LEFT:
            if (this->CanSend(BuildingAllPos()[0], direction, RIGHT_CYCLE, gamemap) && this->CanSend(BuildingAllPos()[1], direction, LEFT_CYCLE, gamemap))
            {
                this->Send(BuildingAllPos()[0], direction, RIGHT_CYCLE, gamemap);
                this->Send(BuildingAllPos()[1], direction, LEFT_CYCLE, gamemap);
                state = EMPTY;
                this->shape.name = NONE;
            }
            break;
        default:
            break;
        }
    default:
        break;
    }
    return;
}
