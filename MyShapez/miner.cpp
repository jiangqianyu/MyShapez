#include "Miner.h"
#include "GameMap.h"

Miner::Miner()
{
    FirstRequire_ms = 2700;
    SecondRequire_ms = 1500;
}
Miner::Miner(GridVec pos, int name, int direction)
    : Building(pos, name, direction)
{
    FirstRequire_ms = 2700;
    SecondRequire_ms = 1500;
}
std::vector<GridVec> Miner::BuildingAllPos()
{
    std::vector<GridVec> allpos;
    allpos.push_back(pos);
    return allpos;
}
bool Miner::CanPlace(GridVec click, int picdirection, GameMap &gamemap)
{
    // 如果超出地图范围，返回false
    if (click.i < 0 || click.i >= HEIGHT || click.j < 0 || click.j >= WIDTH)
    {
        return false;
    }
    // 如果不是在矿地上，返回false
    if (gamemap.GetResource(click) == NONE || gamemap.GetResource(click) == BARRIER)
    {
        return false;
    }
    return true;
}
bool Miner::CanReceive(GridVec target, int directionin, int shapename)
{
    return false;
}
void Miner::Receive(GridVec target, int directionin, int shapename)
{
    return;
}
void Miner::TickableRunning()
{
    this->timer.UpdateRuningTime(FirstRequire_ms);
    running_ms = this->timer.running_ms;
    return;
}
int Miner::GetDigShapeType(GridVec pos, GameMap &gamemap)
{
    return gamemap.GetResource(pos);
}
void Miner::UpdateTickableState(GameMap &gamemap)
{
    switch (state)
    {
    case EMPTY:
        state = RUNNING;
        running_ms = 0;
        this->shape.name = GetDigShapeType(pos, gamemap);
        this->timer.Reset();
        break;
    case RUNNING:
        if (running_ms >= FirstRequire_ms)
        {
            // dig好了，准备运输
            state = BLOCK;
            running_ms = 0;
        }
        else
        {
            this->TickableRunning();
        }
        break;
    case BLOCK:
        if (this->CanSend(pos, direction, this->shape.name, gamemap))
        {
            this->Send(pos, direction, this->shape.name, gamemap);
            state = EMPTY;
            this->shape.name = NONE;
        }
        break;
    default:
        break;
    }
    return;
}
