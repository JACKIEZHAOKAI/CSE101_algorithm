// CSE 101 Winter 2018, PA 4
//
// Name: ZHAOKAI XU, Te Sun 
// PID: A14738474, A53200185
// Sources of Help: NO
// Due: March 10th, 2018 at 11:59 PM

#ifndef __TENNIS_CPP__
#define __TENNIS_CPP__

#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include "Tennis.hpp"
#include <algorithm>
using namespace std;


int tennis(std::vector<Interval> lessons) {

	//quick sort	
	struct less_than_key
	{
	    inline bool operator() (const Interval& interval1, const Interval& interval2)
	    {
	        return (interval1.start < interval2.start);
	    }
	};
	sort(lessons.begin(), lessons.end(), less_than_key());

	//print 
	 // for(auto it = lessons.begin(); it!= lessons.end();it++)
	 // 	cout<< it->start <<"  "<< it->end<<endl;

	// Basic idea: greedy
	// Sort intervals by starting time 
	// d = 0
	// for j = 1 to n {
	//  if (class j is compatible with some court k)
	//  	schedule class j in court k
	//  else
	//  	allocate a new court d + 1
	//  	schedule class j in court d + 1
	// 		d = d + 1
	//} 

	int num_courts = 1;

	//create a min priority queue
	priority_queue<int, vector<int>, greater<int> > min_pq;

	//assign class 1 to court 1
	min_pq.emplace(lessons.begin()->end);
	lessons.erase(lessons.begin());

	for(auto it = lessons.begin(); it!= lessons.end();it++){

		int ending = min_pq.top();

		if(it->start >= ending){
			min_pq.pop();
			min_pq.emplace(it->end);
		}
		else{
			num_courts++;
			min_pq.emplace(it->end);
		}
	}

	return num_courts;
}
#endif
















