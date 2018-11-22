// CSE 101 Winter 2018, PA 3
//
// Name: ZHAOKAI XU, Zhang Yijia
// PID: A14738474, A92062390
// Sources of Help: book 
// Due: February 23rd, 2018 at 11:59 PM



#ifndef __LCS_CPP__
#define __LCS_CPP__

#include "LCS.hpp"
using namespace std;

std::string lcs(std::string s1, std::string s2) {

	TwoD_Array<int> * c = new TwoD_Array<int> (s1.length()+1, s2.length()+1);

	//initialization 
	for( int i=0; i<= s1.length(); i++)
    		c->at(i,0) = 0;
	for ( int j=0; j<= s2.length(); j++)
       		c->at(0,j) = 0;

	//compute the DP table
	for ( int i=1; i<= s1.length(); i++)
	{
		for ( int j=1; j <= s2.length(); j++)
		{
			if ( s1.at(i-1) == s2.at(j-1) )
				c->at(i,j) = c->at(i-1,j-1) + 1;
			else
				c->at(i,j)  = MAX(c->at(i,j-1), c->at(i-1, j));	
		}
	}

	// c->printOut();
	
	//find the common sequence
	string lcs = "";
	int i = s1.length(), j = s2.length();
   	while (i > 0 && j > 0){

		if (c->at(i,j) == c->at(i-1,j)){
   			 //cerr<< "move up"<<endl;
   			i--;
   		}
		else if (c->at(i,j) == c->at(i,j-1)){
   			 //cerr<< "move left"<<endl;
   			j--;
   		}
   		else{
   			 // cerr<< "move up right"<<endl;
   			 // cerr<<c->at(i,j)<<endl;
   			lcs += s1.at(i-1);
   			i--;
   			j--;
   		}
   	}

	reverse(lcs.begin(),lcs.end());

  return lcs;
}
#endif
