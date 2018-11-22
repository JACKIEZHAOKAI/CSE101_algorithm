// CSE 101 Winter 2018, PA 3
//
// Name: ZHAOKAI XU, Zhang Yijia
// PID: A14738474, A92062390
// Sources of Help: book 
// Due: February 23rd, 2018 at 11:59 PM



#ifndef __GRID_SUM_CPP__
#define __GRID_SUM_CPP__

#include "TwoD_Array.hpp"
#include "GridSum.hpp"
using namespace std;

// Perform the precomputation step here
// with time complexity and space comlextity O(n^2) --- DP
GridSum::GridSum (TwoD_Array<int>& grid) {

	pg = new TwoD_Array<int>(grid.getNumRows()+1,grid.getNumCols()+1);

	//initialization
	for (int i=1; i< pg->getNumRows(); i++)
	 	for (int j=1; j< pg->getNumCols(); j++)

	 for (int i=1; i< pg->getNumRows(); i++)
	 	for (int j=1; j< pg->getNumCols(); j++)
	 		pg->at(i,j) = pg->at(i-1,j) + pg->at(i,j-1) - pg->at(i-1,j-1) + grid.at(i-1,j-1);

	 //pg->printOut();
}

// Perform the query step here		O(1) 
int GridSum::query (int x1, int y1, int x2, int y2) {
	
	return  pg->at(x2+1,y2+1) -  pg->at(x1,y2+1) -  pg->at(x2+1,y1) +  pg->at(x1,y1);
}

#endif
