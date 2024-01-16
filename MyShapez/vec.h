#ifndef VEC_H
#define VEC_H
#include "config.h"
/**
 *\brief 网格坐标，j是横坐标，i是纵坐标，int
 */
typedef struct gridvec
{
    int j, i;

    gridvec(int j = 0, int i = 0) : j(j), i(i)
    {
    }
    int operator-(gridvec b)
    {
        if (j - b.j == 1 && i == b.i)
        {
            return RIGHT;
        }
        if (j - b.j == -1 && i == b.i)
        {
            return LEFT;
        }
        if (i - b.i == 1 && j == b.j)
        {
            return DOWN;
        }
        if (i - b.i == -1 && j == b.j)
        {
            return UP;
        }
        return 0;
    }
    gridvec operator+(int side) const
    {
        switch (side)
        {
        case UP:
            return gridvec{j, i - 1};
        case DOWN:
            return gridvec{j, i + 1};
        case LEFT:
            return gridvec{j - 1, i};
        case RIGHT:
            return gridvec{j + 1, i};
        }
        return gridvec{j, i};
    }

    bool operator==(const gridvec &pos) const
    {
        return j == pos.j && i == pos.i;
    }
} GridVec;

/**
 *\brief 图片坐标，x是横坐标，y是纵坐标，int
 */
typedef struct picvec
{
    int x, y;
} PicVec;

#endif // VEC_H
