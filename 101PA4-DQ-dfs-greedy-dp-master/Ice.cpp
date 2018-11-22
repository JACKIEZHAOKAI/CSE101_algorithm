// CSE 101 Winter 2018, PA 4
//
// Name: ZHAOKAI XU, Te Sun 
// PID: A14738474, A53200185
// Sources of Help: NO
// Due: March 10th, 2018 at 11:59 PM

#ifndef __ICE_CPP__
#define __ICE_CPP__

#include "Ice.hpp"
#include "iostream"
using namespace std;
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int ice(TwoD_Array<int> rooms) {

	TwoD_Array<int> * dp = new TwoD_Array<int>(rooms.getNumRows(),rooms.getNumCols());

	//starting from the right down corner
	dp->at(dp->getNumRows()-1,dp->getNumCols()-1) = rooms.at(rooms.getNumRows()-1,rooms.getNumCols()-1) + 1;

	// //initialize the dp table with the last row and col
	for (int i= dp->getNumRows()-2; i >=0; i--)
		if (( dp->at(i+1,dp->getNumCols()-1) + rooms.at(i,dp->getNumCols()-1) ) > 0 )
			dp->at(i,dp->getNumCols()-1) = dp->at(i+1,dp->getNumCols()-1) + rooms.at(i,dp->getNumCols()-1);
		else 
			dp->at(i,dp->getNumCols()-1) = 1;


	for (int j= dp->getNumCols()-2; j >=0; j--)
		if ( dp->at(dp->getNumRows()-1,j+1) + rooms.at(dp->getNumRows()-1,j) > 0 )
			dp->at(dp->getNumRows()-1,j) = dp->at(dp->getNumRows()-1,j+1) + rooms.at(dp->getNumRows()-1,j);
		else 
			dp->at(dp->getNumRows()-1,j) = 1;

	for (int i=dp->getNumRows()-2; i >=0 ; i--)
		for (int j=dp->getNumRows()-2; j >=0 ; j--)
			if (( MIN( dp->at(i,j+1), dp->at(i+1,j) ) +  rooms.at(i,j) ) > 0 )
				dp->at(i,j) = MIN( dp->at(i,j+1), dp->at(i+1,j)) + rooms.at(i,j);
			else 
				dp->at(i,j) = 1;

	// rooms.printOut();
	// dp->printOut();

	return dp->at(0,0);

}
#endif








