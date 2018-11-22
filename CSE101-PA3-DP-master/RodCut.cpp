// CSE 101 Winter 2018, PA 3
//
// Name: ZHAOKAI XU, Zhang Yijia
// PID: A14738474, A92062390
// Sources of Help: book 
// Due: February 23rd, 2018 at 11:59 PM

#ifndef __RODCUT_CPP__
#define __RODCUT_CPP__

#include "RodCut.hpp"
#include <iostream>
using namespace std;


int rodcut(std::map<int, int> prices, int length) {
 
   int value[length+1];
   value[0] = 0;
!
   for (int i = 1; i<=length; i++)
   {
   	   int maxValue = INT_MIN;
   	   //check all possible combinations to find the max price
       for (int j = 1; j <= i; j++){
         maxValue = MAX(maxValue, (prices[j] + value[i-j])) ;
       }
       //update the max price in teh DP array
       value[i] = maxValue;
   }
 
   return value[length];
}


#endif








