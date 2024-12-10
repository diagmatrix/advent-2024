#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

#include "utils.hpp"

const char* INPUT = "data/day_2/input.txt";
const char* BLANK = "";

int main() {
    std::cout << "Solution to day 2!" << std::endl;

    // Get list
    std::vector<std::string> raw_reports = parse_file(INPUT);
    if (raw_reports.empty()) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}