# CSE 101 PA 3 Makefile
#
# DO NOT MODIFY

CC=g++
FLAGS=-std=c++0x -g -I./

TEST_GridSum = testsrc/TestGridSum.cpp GridSum.cpp
GridSum = GridSum.cpp TwoD_Array.hpp GridSum.hpp
TEST_RodCut = testsrc/TestRodCut.cpp RodCut.cpp
RodCut = RodCut.cpp RodCut.hpp
TEST_LCS = testsrc/TestLCS.cpp LCS.cpp
LCS = LCS.cpp TwoD_Array.hpp LCS.hpp
TEST_USB = testsrc/TestUSB.cpp USB.cpp
USB = USB.cpp TwoD_Array.hpp USB.hpp
PA_SRCS = $(TEST_RodCut) $(RodCut) $(TEST_GridSum) $(GridSum) $(TEST_LCS) $(LCS) $(TEST_USB) $(USB)

BUILD = build

$(BUILD):
	mkdir $(BUILD)

TestGridSum : $(BUILD)/GridSum.o $(BUILD)/TestGridSum.o
	$(CC) $(FLAGS) $^ -o $(BUILD)/$@
$(BUILD)/TestGridSum.o : $(TEST_GridSum) | $(BUILD)
	$(CC) $(FLAGS) -c $< -o $@
$(BUILD)/GridSum.o : $(GridSum) | $(BUILD)
	$(CC) $(FLAGS) -c $< -o $@

TestRodCut : $(BUILD)/RodCut.o $(BUILD)/TestRodCut.o
	$(CC) $(FLAGS) $^ -o $(BUILD)/$@
$(BUILD)/TestRodCut.o : $(TEST_RodCut) | $(BUILD)
	$(CC) $(FLAGS) -c $< -o $@
$(BUILD)/RodCut.o : $(RodCut) | $(BUILD)
	$(CC) $(FLAGS) -c $< -o $@

TestLCS : $(BUILD)/LCS.o $(BUILD)/TestLCS.o
	$(CC) $(FLAGS) $^ -o $(BUILD)/$@
$(BUILD)/TestLCS.o : $(TEST_LCS) | $(BUILD)
	$(CC) $(FLAGS) -c $< -o $@
$(BUILD)/LCS.o : $(LCS) | $(BUILD)
	$(CC) $(FLAGS) -c $< -o $@

TestUSB : $(BUILD)/USB.o $(BUILD)/TestUSB.o
	$(CC) $(FLAGS) $^ -o $(BUILD)/$@
$(BUILD)/TestUSB.o : $(TEST_USB) | $(BUILD)
	$(CC) $(FLAGS) -c $< -o $@
$(BUILD)/USB.o : $(USB) | $(BUILD)
	$(CC) $(FLAGS) -c $< -o $@

TestAll: TestRodCut TestGridSum TestLCS TestUSB

all: TestAll

clean:
	rm -rf build

turnin:
	tar -cvf PA3.tar *.cpp *.hpp
	turnin -c cs101w PA3.tar

.PHONY: all
