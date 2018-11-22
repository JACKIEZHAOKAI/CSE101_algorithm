// CSE 101 Winter 2018, PA 3
//
// Name: ZHAOKAI XU, Zhang Yijia
// PID: A14738474, A92062390
// Sources of Help: book 
// Due: February 23rd, 2018 at 11:59 PM

#ifndef __USB_CPP__
#define __USB_CPP__

#include <map>
#include "USB.hpp"
#include "TwoD_Array.hpp"
using namespace std;

int find_files_naive(int USBsize, std::vector<int>& files) {
  
  int min = -1;

  for (auto it = files.begin(); it != files.end(); ++it) {
    if (USBsize == *it) {   // 1 is the minimum number of possible files
      // cout<<"USBsize = "<<USBsize<<"return = "<< 1<<endl;
      return 1;
    }
    else if (USBsize > *it) {
      // assume per the problem statement that the USB size is always met
      int files_used = find_files_naive(USBsize - *it, files) + 1;

      if (min == -1 || (files_used < min && files_used > 0)) {
        min = files_used;
      }
    }
    // do nothing if file size is larger than the USB size
  }
  //cout<<"return = "<< min<<endl;
  return min;
}


// memorizaiton table, where key is USBsize, value is min number of files required to fill in
std::map<int, int> memoize;
int find_files_memoized(int USBsize, std::vector<int>& files) {

  int min = -1;

  for (auto it = files.begin(); it != files.end(); ++it) {
    
    if (USBsize == *it) {   // 1 is the minimum number of possible files
      return 1;
    }
    //if already calculated
    if ( memoize[USBsize] != 0){
      //cout<< USBsize <<" memorized  "<< memoize[USBsize] <<endl;
      return memoize[USBsize];
    }
    else if (USBsize > *it) {
      // assume per the problem statement that the USB size is always met
      int files_used = find_files_memoized(USBsize - *it, files) + 1;

      //store the value
      int key = USBsize - *it;
      memoize[key] = files_used-1;
      //cout<<"key "<< key<< " files_used"<< files_used-1<<endl;
      
      if (min == -1 || (files_used < min && files_used > 0)) {
        min = files_used;
      }
    }
    // do nothing if file size is larger than the USB size
  }

  return min;
}

int find_files_dp(int USBsize, std::vector<int>& files) {

   TwoD_Array<int> * usb =  new  TwoD_Array<int>( USBsize+1, files.size());

   // 1 D array to store the min number of files for diff USB size
   int* memo = new int[USBsize+1]; 
   memo[0] = 0;
   memo[1] = 1;
   for( int i=2; i<=USBsize; i++)
        memo[i] = INT_MAX;
 
   //initialization
   for (int i = 0; i <= USBsize; i++)
      for (int j = 0; j < files.size(); j++) 
           usb->at(i,j)=0;

   // build the DP table
   for (int i = 1; i <= USBsize; i++)
   {
        for (int j = 0; j < files.size(); j++)
        {
            //check if the curr USB size can hold the file
            if ( files.at(j) <= i )
            {
              if ( memo[ i - files.at(j) ]  != INT_MAX)
                  usb->at(i,j) = memo[ i - files.at(j) ] + 1 ;
               // updating the min array
              if( usb->at(i,j)< memo[i])
              {
                 memo[i] = usb->at(i,j);  
              }   
            } 
        }
       
   }

   // cout<<endl;
   // usb->printOut();

  return memo[USBsize];
}
#endif








