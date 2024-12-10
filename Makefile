all: day_1 day_2

day_1:
	@echo "Compiling solution for day 1..."
	g++ src/day_1.cpp src/utils.hpp -o bin/solution_1

day_2:
	@echo "Compiling solution for day 2..."
	g++ src/day_2.cpp src/utils.hpp -o bin/solution_2
