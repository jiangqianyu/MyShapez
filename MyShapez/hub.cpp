#include "hub.h"
#include "config.h"
Hub::Hub()
{
    need = NEED_CYCLE;
    need_shape_name = CYCLE;
    current_have = 0;
    money = 0;
    increase_item_value = false;
    upgradehub = false;
}
Hub::Hub(GridVec pos, int name, int direction) : Building(pos, name, direction)
{
    need = NEED_CYCLE;
    need_shape_name = CYCLE;
    current_have = 0;
    money = 0;
    increase_item_value = false;
    upgradehub = false;
}
std::vector<GridVec> Hub::BuildingAllPos()
{
    GridVec temp;
    std::vector<GridVec> allpos;
    if (!upgradehub)
    {
        allpos.push_back(pos);
        temp.i = pos.i + 1;
        temp.j = pos.j;
        allpos.push_back(temp);
        temp.i = pos.i + 1;
        temp.j = pos.j + 1;
        allpos.push_back(temp);
        temp.i = pos.i;
        temp.j = pos.j + 1;
        allpos.push_back(temp);
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                temp.i = pos.i + i;
                temp.j = pos.j + j;
                allpos.push_back(temp);
            }
        }
    }
    return allpos;
}
bool Hub::CanPlace(GridVec click, int picdirection, GameMap &gamemap)
{
    return true;
}
bool Hub::CanReceive(GridVec source, int directionin, int shapename)
{
    return true;
}
void Hub::Receive(GridVec source, int directionin, int shapename)
{
    if (shapename == need_shape_name)
    {
        current_have++;
    }
    if (!increase_item_value)
    {
        switch (shapename)
        {
        case CYCLE:
            money += CYCLE_MONEY_1;
            break;
        case RECT:
            money += RECT_MONEY_1;
            break;
        case LEFT_CYCLE:
            money += LEFT_CYCLE_MONEY_1;
            break;
        case RIGHT_CYCLE:
            money += RIGHT_CYCLE_MONEY_1;
            break;
        default:
            break;
        }
    }
    else
    {
        switch (shapename)
        {
        case CYCLE:
            money += CYCLE_MONEY_2;
            break;
        case RECT:
            money += RECT_MONEY_2;
            break;
        case LEFT_CYCLE:
            money += LEFT_CYCLE_MONEY_2;
            break;
        case RIGHT_CYCLE:
            money += RIGHT_CYCLE_MONEY_2;
            break;
        default:
            break;
        }
    }
    return;
}
void Hub::UpdateTickableState(GameMap &gamemap)
{
    return;
}
void Hub::TickableRunning()
{
    return;
}
void Hub::UpdateNeed()
{
    switch (need_shape_name)
    {
    case CYCLE:
        need_shape_name = RECT;
        current_have = 0;
        need = NEED_RECT;
        break;
    case RECT:
        need_shape_name = LEFT_CYCLE;
        current_have = 0;
        need = NEED_LEFT_CYCLE;
        break;
    case LEFT_CYCLE:
        need_shape_name = RIGHT_CYCLE;
        current_have = 0;
        need = NEED_RIGHT_CYCLE;
        break;
    default:
        break;
    }
}
