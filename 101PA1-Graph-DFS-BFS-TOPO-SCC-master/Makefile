# CSE 101 PA 1 Makefile
#
# DO NOT MODIFY

.SUFFIXES: 

CC=g++
FLAGS=-std=c++0x -I./

TEST_DFS = testsrc/TestDFS.cpp DFS.cpp
DFS_SRCS = DFS.cpp Graph.hpp DFS.hpp
TEST_BFS = testsrc/TestBFS.cpp BFS.cpp
BFS_SRCS = BFS.cpp Graph.hpp BFS.hpp
TEST_SCC = testsrc/TestSCC.cpp SCC.cpp
SCC_SRCS = SCC.cpp Graph.hpp SCC.hpp
TEST_TopOrder = testsrc/TestTopOrder.cpp TopOrder.cpp
TopOrder_SRCS = TopOrder.cpp Graph.hpp TopOrder.hpp
PA_SRCS = $(TEST_DFS) $(DFS) $(TEST_BFS) $(BFS) $(TEST_SCC) $(SCC) $(TEST_TopOrder) $(TopOrder)

BUILD = build

$(BUILD):
	mkdir $(BUILD)

TestDFS : $(BUILD)/DFS.o $(BUILD)/TestDFS.o
	$(CC) $(FLAGS) $^ -o $(BUILD)/$@
$(BUILD)/TestDFS.o : $(TEST_DFS) | $(BUILD)
	$(CC) $(FLAGS) -c $< -o $@
$(BUILD)/DFS.o : $(DFS_SRCS) | $(BUILD)
	$(CC) $(FLAGS) -c $< -o $@

TestBFS : $(BUILD)/BFS.o $(BUILD)/TestBFS.o
	$(CC) $(FLAGS) $^ -o $(BUILD)/$@
$(BUILD)/TestBFS.o : $(TEST_BFS) | $(BUILD)
	$(CC) $(FLAGS) -c $< -o $@
$(BUILD)/BFS.o : $(BFS_SRCS) | $(BUILD)
	$(CC) $(FLAGS) -c $< -o $@

TestSCC : $(BUILD)/DFS.o $(BUILD)/SCC.o $(BUILD)/TestSCC.o
	$(CC) $(FLAGS) $^ -o $(BUILD)/$@
$(BUILD)/TestSCC.o : $(TEST_SCC) | $(BUILD)
	$(CC) $(FLAGS) -c $< -o $@
$(BUILD)/SCC.o : $(SCC_SRCS) | $(BUILD)
	$(CC) $(FLAGS) -c $< -o $@

TestTopOrder : $(BUILD)/TopOrder.o $(BUILD)/TestTopOrder.o
	$(CC) $(FLAGS) $^ -o $(BUILD)/$@
$(BUILD)/TestTopOrder.o : $(TEST_TopOrder) | $(BUILD)
	$(CC) $(FLAGS) -c $< -o $@
$(BUILD)/TopOrder.o : $(TopOrder_SRCS) | $(BUILD)
	$(CC) $(FLAGS) -c $< -o $@

TestAll: TestDFS TestBFS TestTopOrder TestSCC 

all: TestAll

clean:
	rm -rf build

turnin:
	tar -cvf PA1.tar *.cpp *.hpp
	turnin -c cs101w PA1.tar

.PHONY: all
