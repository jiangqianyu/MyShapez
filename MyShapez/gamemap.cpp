#include "GameMap.h"
#include "Building.h"
GameMap::GameMap()
{
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
        {
            Resource[i][j] = NONE;
        }
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
        {
            BuildingsMap[i][j] = nullptr;
        }
}

void GameMap::FirstMap()
{
    // 初始化资源
    Resource[11][3] = CYCLE;
    Resource[12][2] = CYCLE;
    Resource[12][3] = CYCLE;
    Resource[13][2] = CYCLE;
    Resource[13][3] = CYCLE;
    Resource[13][4] = CYCLE;
    Resource[14][3] = CYCLE;
    Resource[2][20] = RECT;
    Resource[2][21] = RECT;
    Resource[2][22] = RECT;
    Resource[3][19] = RECT;
    Resource[3][20] = RECT;
    Resource[3][21] = RECT;
    Resource[4][20] = RECT;
    Resource[4][21] = RECT;
    Resource[1][3] = BARRIER;
    Resource[2][4] = BARRIER;
    Resource[4][2] = BARRIER;
    Resource[5][1] = BARRIER;
    Resource[9][6] = BARRIER;
    Resource[10][5] = BARRIER;
    Resource[9][3] = BARRIER;
    Resource[12][7] = BARRIER;
    Resource[8][9] = BARRIER;
    Resource[12][9] = BARRIER;
    Resource[12][10] = BARRIER;
    Resource[13][9] = BARRIER;
    Resource[13][8] = BARRIER;
    Resource[14][7] = BARRIER;
    Resource[2][13] = BARRIER;
    Resource[2][17] = BARRIER;
    Resource[3][14] = BARRIER;
    Resource[3][15] = BARRIER;
    Resource[4][10] = BARRIER;
    Resource[4][13] = BARRIER;
    Resource[5][14] = BARRIER;
    Resource[5][17] = BARRIER;
    Resource[6][18] = BARRIER;
    Resource[6][19] = BARRIER;
    Resource[7][20] = BARRIER;
    Resource[8][21] = BARRIER;
    Resource[9][23] = BARRIER;
    Resource[9][20] = BARRIER;
    Resource[10][14] = BARRIER;
    Resource[11][13] = BARRIER;
    Resource[12][14] = BARRIER;
    Resource[14][14] = BARRIER;
}

void GameMap::SecondMap()
{
    // 增加资源
    Resource[9][16] = CYCLE;
    Resource[10][16] = CYCLE;
    Resource[10][17] = CYCLE;
    Resource[10][18] = CYCLE;
    Resource[11][17] = CYCLE;
    Resource[11][18] = CYCLE;
    Resource[12][18] = CYCLE;
    Resource[3][5] = RECT;
    Resource[3][6] = RECT;
    Resource[4][6] = RECT;
    Resource[4][7] = RECT;
    Resource[4][8] = RECT;
    Resource[5][7] = RECT;
    Resource[5][6] = RECT;
    Resource[5][5] = RECT;
    Resource[6][5] = RECT;
    Resource[6][8] = RECT;
}

void GameMap::ClearBarriers()
{
    Resource[1][3] = NONE;
    Resource[2][4] = NONE;
    Resource[4][2] = NONE;
    Resource[5][1] = NONE;
    Resource[9][6] = NONE;
    Resource[10][5] = NONE;
    Resource[9][3] = NONE;
    Resource[12][7] = NONE;
    Resource[8][9] = NONE;
    Resource[12][9] = NONE;
    Resource[12][10] = NONE;
    Resource[13][9] = NONE;
    Resource[13][8] = NONE;
    Resource[14][7] = NONE;
    Resource[2][13] = NONE;
    Resource[2][17] = NONE;
    Resource[3][14] = NONE;
    Resource[3][15] = NONE;
    Resource[4][10] = NONE;
    Resource[4][13] = NONE;
    Resource[5][14] = NONE;
    Resource[5][17] = NONE;
    Resource[6][18] = NONE;
    Resource[6][19] = NONE;
    Resource[7][20] = NONE;
    Resource[8][21] = NONE;
    Resource[9][23] = NONE;
    Resource[9][20] = NONE;
    Resource[10][14] = NONE;
    Resource[11][13] = NONE;
    Resource[12][14] = NONE;
    Resource[14][14] = NONE;
}
int GameMap::GetResource(GridVec pos)
{
    return Resource[pos.i][pos.j];
}

void GameMap::SetBuilding(GridVec pos, Building *building, int direction, int name)
{
    for (auto pos : building->BuildingAllPos())
    {
        BuildingsMap[pos.i][pos.j] = building;
    }
}

Building *GameMap::GetBuilding(GridVec pos)
{
    return BuildingsMap[pos.i][pos.j];
}

void GameMap::RemoveBuilding(GridVec pos)
{
    if (BuildingsMap[pos.i][pos.j]->name != HUB)
    {
        for (auto pos : BuildingsMap[pos.i][pos.j]->BuildingAllPos())
        {
            BuildingsMap[pos.i][pos.j] = nullptr;
        }
    }
}
GridVec GameMap::GetTatget(GridVec source, int directionout)
{
    GridVec target = source;
    switch (directionout)
    {
        {
        case UP:
            target.i--;
            break;
        case DOWN:
            target.i++;
            break;
        case LEFT:
            target.j--;
            break;
        case RIGHT:
            target.j++;
            break;
        }
    default:
        break;
    }
    return target;
}
int GameMap::OppositeDirection(int direction)
{
    switch (direction)
    {
    case UP:
        return DOWN;
    case DOWN:
        return UP;
    case LEFT:
        return RIGHT;
    case RIGHT:
        return LEFT;
    default:
        return NONE;
    }
}
