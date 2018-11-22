// CSE 101 Winter 2018, PA 4
//
// Name: ZHAOKAI XU, Te Sun 
// PID: A14738474, A53200185
// Sources of Help: NO
// Due: March 10th, 2018 at 11:59 PM

#ifndef __SERIAL_CPP__
#define __SERIAL_CPP__

#include "Serial.hpp"
#include <iostream>
using namespace std;

int serial(std::vector<int> nums) {

	int left = 0;
	int right = nums.size() - 1;

   while (right > left)
   {
        int mid = left + (right - left)/2;
 
        // find the deplicated num
        if ( nums.at(mid) ==  nums.at(mid+1) || nums.at(mid) ==  nums.at(mid-1) )
            return nums.at(mid);

  	   	if ( (nums.at(right) - nums.at(mid)) != (right - mid))
	   	     	left = mid + 1;
 		    else
 			      right = mid - 1;
   }
   //not found 
   return -1;
}

#endif
