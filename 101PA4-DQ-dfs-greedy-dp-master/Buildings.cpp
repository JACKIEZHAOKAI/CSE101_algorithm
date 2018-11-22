// CSE 101 Winter 2018, PA 4
//
// Name: ZHAOKAI XU, Te Sun 
// PID: A14738474, A53200185
// Sources of Help: NO
// Due: March 10th, 2018 at 11:59 PM

#ifndef __BUILDINGS_CPP__
#define __BUILDINGS_CPP__

#include "Buildings.hpp"
#include <stack> 
#include <iostream>
#include <utility>
using namespace std;

int buildings(TwoD_Array<int> survey) {

	int total_buildings =0;
	//run DFS for each grid if it is 1, else if 0, do nothing 
	for(int i=0; i< survey.getNumRows(); i++ )
		for(int j=0; j< survey.getNumCols(); j++ )
			if (survey.at(i,j) == 1){

				//found a building
				total_buildings++;

				stack< pair <int, int> > stack;
				//visit
				survey.at(i,j) = 0;
				//push to stack
				pair <int, int>  point(i,j);
				stack.push(point);

				while (!stack.empty())
				{
			  		pair <int, int>  curr = stack.top(); 
			  		stack.pop();

			  		for ( int i=0; i<4; i++)
			  		{
			  			if( i == 0 && curr.second>0){	//move left
			  				if ( survey.at(curr.first, curr.second-1) == 1)
			  				{
			  					//visit
			  					 survey.at(curr.first, curr.second-1) = 0;
			  					 // push to stack
			  					 pair <int, int>  temp(curr.first, curr.second-1); 
			  					 stack.push(temp);
			  				}
			  			}
			  			if( i == 1 && curr.first>0){	//move up
			  				if ( survey.at(curr.first-1, curr.second) == 1)
			  				{
			  					 survey.at(curr.first-1, curr.second) = 0;
			  					 pair <int, int>  temp(curr.first-1, curr.second); 
			  					 stack.push(temp);
			  				}
			  			}
			  			if( i == 2 && curr.second < survey.getNumCols()-1){	//move right  
			  				if ( survey.at(curr.first, curr.second+1) == 1)
			  				{
			  					 survey.at(curr.first, curr.second+1) = 0;
			  					 pair <int, int>  temp(curr.first, curr.second+1); 
			  					 stack.push(temp);
			  				}
			  			}
			  			if( i == 3 && curr.first<survey.getNumRows()-1){		//move down 
			  				if ( survey.at(curr.first+1, curr.second) == 1)
			  				{
			  					 survey.at(curr.first+1, curr.second) = 0;
			  					 pair <int, int>  temp(curr.first+1, curr.second); 
			  					 stack.push(temp);
			  				}
			  			}
			  		}
			 	}


			}
  
  return total_buildings;
}
#endif
