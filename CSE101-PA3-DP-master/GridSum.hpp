// CSE 101 Winter 2018, PA 3
//
// You may modify what you store in the GridSum class if needed

#ifndef __GRID_SUM_HPP__
#define __GRID_SUM_HPP__

#include "TwoD_Array.hpp"

class GridSum {
public:
    // The constructor is first called as the precompute step
    GridSum(TwoD_Array<int>& grid);

    int query(int x1, int y1, int x2, int y2);

private:
    // You may modify these variables as needed (pg for precomputed grid)
    TwoD_Array<int> * pg;
};

#endif
