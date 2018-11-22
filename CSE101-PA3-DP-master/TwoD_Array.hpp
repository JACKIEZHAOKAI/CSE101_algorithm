// CSE 101 Winter 2018, PA 3
//
// Name: ZHAOKAI XU
// PID: A14738474
// Sources of Help: book 
// Due: February 23rd, 2018 at 11:59 PM


#ifndef __TWOD_ARRAY_HPP__
#define __TWOD_ARRAY_HPP__

#include <iostream>

// This class will create an N * M array of type T for you since 
// multi dimensional arrays are slow in C++
template <typename T>
class TwoD_Array {
public:
    // n represents number of rows,
    // m represents number of columns
    TwoD_Array (int n, int m): n(n), m(m) {
        linear_array = new T[n * m];
    }

    // you can use 'at' to both set and retrieve values in the 2D_Array
    T& at (int x, int y) {
        return linear_array[(x*m) + y];
    }

    // returns number of rows
    int getNumRows() {
        return n;
    }

    // returns number of columns
    int getNumCols() {
        return m;
    }

    // prints out the TwoD_Array -- useful for debugging purposes
    void printOut() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cout << at(i,j) << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

private:
    T * linear_array;
    int n;
    int m;
};

#endif
