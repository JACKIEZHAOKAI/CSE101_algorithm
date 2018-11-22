// CSE 101 Winter 2018, PA 4
//
// Add fields here if necessary, as long as
// it compiles and runs with our Makefile
// and autograder.

#ifndef __INTERVAL_HPP__
#define __INTERVAL_HPP__

class Interval {
  public:
  int start;
  int end;

  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};
#endif
