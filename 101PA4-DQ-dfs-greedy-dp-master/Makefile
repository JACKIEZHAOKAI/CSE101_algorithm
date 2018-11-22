# CSE 101 PA 4 Makefile
#
# DO NOT MODIFY

CC=g++
FLAGS=-std=c++0x -g -I./

TEST_Ice = testsrc/TestIce.cpp Ice.cpp
Ice = Ice.cpp TwoD_Array.hpp Ice.hpp
TEST_Tennis = testsrc/TestTennis.cpp Tennis.cpp
Tennis = Tennis.cpp Tennis.hpp
TEST_Serial = testsrc/TestSerial.cpp Serial.cpp
Serial = Serial.cpp TwoD_Array.hpp Serial.hpp
TEST_Buildings = testsrc/TestBuildings.cpp Buildings.cpp
Buildings = Buildings.cpp TwoD_Array.hpp Buildings.hpp
PA_SRCS = $(TEST_Tennis) $(Tennis) $(TEST_Ice) $(Ice) $(TEST_Serial) $(Serial) $(TEST_Buildings) $(Buildings)

BUILD = build

$(BUILD):
	mkdir $(BUILD)

TestIce : $(BUILD)/Ice.o $(BUILD)/TestIce.o
	$(CC) $(FLAGS) $^ -o $(BUILD)/$@
$(BUILD)/TestIce.o : $(TEST_Ice) | $(BUILD)
	$(CC) $(FLAGS) -c $< -o $@
$(BUILD)/Ice.o : $(Ice) | $(BUILD)
	$(CC) $(FLAGS) -c $< -o $@

TestTennis : $(BUILD)/Tennis.o $(BUILD)/TestTennis.o
	$(CC) $(FLAGS) $^ -o $(BUILD)/$@
$(BUILD)/TestTennis.o : $(TEST_Tennis) | $(BUILD)
	$(CC) $(FLAGS) -c $< -o $@
$(BUILD)/Tennis.o : $(Tennis) | $(BUILD)
	$(CC) $(FLAGS) -c $< -o $@

TestSerial : $(BUILD)/Serial.o $(BUILD)/TestSerial.o
	$(CC) $(FLAGS) $^ -o $(BUILD)/$@
$(BUILD)/TestSerial.o : $(TEST_Serial) | $(BUILD)
	$(CC) $(FLAGS) -c $< -o $@
$(BUILD)/Serial.o : $(Serial) | $(BUILD)
	$(CC) $(FLAGS) -c $< -o $@

TestBuildings : $(BUILD)/Buildings.o $(BUILD)/TestBuildings.o
	$(CC) $(FLAGS) $^ -o $(BUILD)/$@
$(BUILD)/TestBuildings.o : $(TEST_Buildings) | $(BUILD)
	$(CC) $(FLAGS) -c $< -o $@
$(BUILD)/Buildings.o : $(Buildings) | $(BUILD)
	$(CC) $(FLAGS) -c $< -o $@

TestAll: TestTennis TestIce TestSerial TestBuildings

all: TestAll

clean:
	rm -rf build

turnin:
	tar -cvf PA4.tar *.cpp *.hpp
	turnin -c cs101w PA4.tar

.PHONY: all
