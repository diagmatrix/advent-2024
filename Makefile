all: day_1

day_1:
	echo "Compiling solution for day 1..."
	g++ src/day_1.cpp src/utils.hpp -o bin/solution_1

run: day_1
	./bin/solution_*