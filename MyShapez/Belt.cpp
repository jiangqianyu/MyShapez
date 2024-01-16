#include "Belt.h"
#include "GameMap.h"
Belt::Belt()
{
    in = 0;
    out = 0;
    FirstRequire_ms = 1500;
    SecondRequire_ms = 720;
    switch (name)
    {
    case BELT_A:
    case BELT_A_S:
    case BELT_A_W:
        this->init_x = pos.j * CELLSIZE + CELLSIZE;
        this->init_y = pos.i * CELLSIZE + CELLSIZE / 2;
        break;
    case BELT_D:
    case BELT_D_S:
    case BELT_D_W:
        this->init_x = pos.j * CELLSIZE;
        this->init_y = pos.i * CELLSIZE + CELLSIZE / 2;
        break;
    case BELT_S:
    case BELT_S_A:
    case BELT_S_D:
        this->init_x = pos.j * CELLSIZE + CELLSIZE / 2;
        this->init_y = pos.i * CELLSIZE;
        break;
    case BELT_W:
    case BELT_W_A:
    case BELT_W_D:
        this->init_x = pos.j * CELLSIZE + CELLSIZE / 2;
        this->init_y = pos.i * CELLSIZE + CELLSIZE;
        break;
    default:
        break;
    }
}
Belt::Belt(GridVec pos, int name, int direction)
    : Building(pos, name, direction)
{
    switch (name)
    {
    case BELT_A:
    case BELT_D:
    case BELT_S:
    case BELT_W:
        in = direction;
        break;
    case BELT_A_S:
    case BELT_A_W:
        in = LEFT;
        break;
    case BELT_D_S:
    case BELT_D_W:
        in = RIGHT;
        break;
    case BELT_S_A:
    case BELT_S_D:
        in = DOWN;
        break;
    case BELT_W_A:
    case BELT_W_D:
        in = UP;
        break;
    default:
        break;
    }
    out = direction;
    FirstRequire_ms = 1500;
    SecondRequire_ms = 720;
    switch (name)
    {
    case BELT_A:
    case BELT_A_S:
    case BELT_A_W:
        this->init_x = pos.j * CELLSIZE + CELLSIZE;
        this->init_y = pos.i * CELLSIZE + CELLSIZE / 2;
        break;
    case BELT_D:
    case BELT_D_S:
    case BELT_D_W:
        this->init_x = pos.j * CELLSIZE;
        this->init_y = pos.i * CELLSIZE + CELLSIZE / 2;
        break;
    case BELT_S:
    case BELT_S_A:
    case BELT_S_D:
        this->init_x = pos.j * CELLSIZE + CELLSIZE / 2;
        this->init_y = pos.i * CELLSIZE;
        break;
    case BELT_W:
    case BELT_W_A:
    case BELT_W_D:
        this->init_x = pos.j * CELLSIZE + CELLSIZE / 2;
        this->init_y = pos.i * CELLSIZE + CELLSIZE;
        break;
    default:
        break;
    }
}
std::vector<GridVec> Belt::BuildingAllPos()
{
    std::vector<GridVec> allpos;
    allpos.push_back(pos);
    return allpos;
}
bool Belt::CanReceive(GridVec target, int directionin, int shapename)
{
    if (state == EMPTY)
    {
        if (directionin == in)
        {
            return true;
        }
    }
    return false;
}
void Belt::Receive(GridVec target, int directionin, int shapename)
{
    this->shape.name = shapename;
    this->shape.x0 = init_x;
    this->shape.y0 = init_y;
    this->state = RUNNING;
    this->timer.Reset();
}
void Belt::TickableRunning()
{
    double offset = (running_ms * CELLSIZE) / FirstRequire_ms;
    switch (name)
    {
    case BELT_A:
        this->shape.x0 = init_x - offset;
        this->shape.y0 = init_y;
        break;
    case BELT_D:
        this->shape.x0 = init_x + offset;
        this->shape.y0 = init_y;
        break;
    case BELT_S:
        this->shape.y0 = init_y + offset;
        this->shape.x0 = init_x;
        break;
    case BELT_W:
        this->shape.y0 = init_y - offset;
        this->shape.x0 = init_x;
        break;
    case BELT_A_S:
        if (running_ms < FirstRequire_ms / 2)
        {
            this->shape.x0 = init_x - offset;
            this->shape.y0 = init_y;
        }
        else
        {
            this->shape.x0 = init_x - CELLSIZE / 2;
            this->shape.y0 = init_y + (offset - CELLSIZE / 2);
        }
        break;
    case BELT_A_W:
        if (running_ms < FirstRequire_ms / 2)
        {
            this->shape.x0 = init_x - offset;
            this->shape.y0 = init_y;
        }
        else
        {
            this->shape.x0 = init_x - CELLSIZE / 2;
            this->shape.y0 = init_y - (offset - CELLSIZE / 2);
        }
        break;
    case BELT_D_S:
        if (running_ms < FirstRequire_ms / 2)
        {
            this->shape.x0 = init_x + offset;
            this->shape.y0 = init_y;
        }
        else
        {
            this->shape.y0 = init_y + (offset - CELLSIZE / 2);
            this->shape.x0 = init_x + CELLSIZE / 2;
        }
        break;
    case BELT_D_W:
        if (running_ms < FirstRequire_ms / 2)
        {
            this->shape.x0 = init_x + offset;
            this->shape.y0 = init_y;
        }
        else
        {
            this->shape.y0 = init_y - (offset - CELLSIZE / 2);
            this->shape.x0 = init_x + CELLSIZE / 2;
        }
        break;
    case BELT_S_A:
        if (running_ms < FirstRequire_ms / 2)
        {
            this->shape.x0 = init_x;
            this->shape.y0 = init_y + offset;
        }
        else
        {
            this->shape.x0 = init_x - (offset - CELLSIZE / 2);
            this->shape.y0 = init_y + CELLSIZE / 2;
        }
        break;
    case BELT_S_D:
        if (running_ms < FirstRequire_ms / 2)
        {
            this->shape.x0 = init_x;
            this->shape.y0 = init_y + offset;
        }
        else
        {
            this->shape.x0 = init_x + (offset - CELLSIZE / 2);
            this->shape.y0 = init_y + CELLSIZE / 2;
        }
        break;
    case BELT_W_A:
        if (running_ms < FirstRequire_ms / 2)
        {
            this->shape.x0 = init_x;
            this->shape.y0 = init_y - offset;
        }
        else
        {
            this->shape.x0 = init_x - (offset - CELLSIZE / 2);
            this->shape.y0 = init_y - CELLSIZE / 2;
        }
        break;
    case BELT_W_D:
        if (running_ms < FirstRequire_ms / 2)
        {
            this->shape.x0 = init_x;
            this->shape.y0 = init_y - offset;
        }
        else
        {
            this->shape.x0 = init_x + (offset - CELLSIZE / 2);
            this->shape.y0 = init_y - CELLSIZE / 2;
        }
        break;
    default:
        break;
    }
}
void Belt::UpdateTickableState(GameMap &gamemap)
{
    switch (state)
    {
    case EMPTY:
        running_ms = 0;
        break;
    case RUNNING:
        this->timer.UpdateRuningTime(FirstRequire_ms);
        running_ms = this->timer.running_ms;
        if (running_ms > FirstRequire_ms)
        {
            running_ms = FirstRequire_ms;
        }
        if (running_ms >= FirstRequire_ms)
        {
            // 运输到传送带末尾了，准备传递给下一个建筑
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
            this->shape.x0 = init_x;
            this->shape.y0 = init_y;
        }
        break;
    default:
        break;
    }
    return;
}
