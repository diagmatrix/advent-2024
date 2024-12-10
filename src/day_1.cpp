#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

#include "utils.hpp"

const char* INPUT = "data/day_1/input.txt";
const char* BLANK = "";

int main() {
    std::cout << "Solution to day 1!" << std::endl;

    // Get list
    std::vector<std::string> list = parse_file(INPUT);
    if (list.empty()) {
        return EXIT_FAILURE;
    }

    // Parse list
    std::vector<int> list_1, list_2;
    for (const auto& line: list) {
        std::vector<std::string> tokens = split(line, ' ');
        std::string num_1, num_2;
        bool space = false;
        for (const auto& t: tokens) {
            if (strcmp(t.c_str(), BLANK) == 0) {
                space = true;
            } else {
                if (!space) {
                    num_1 += t;
                } else {
                    num_2 += t;
                }
            }
        }
        list_1.push_back(std::stoi(num_1));
        list_2.push_back(std::stoi(num_2));
    }

    // Sort lists
    std::sort(list_1.begin(), list_1.end());
    std::sort(list_2.begin(), list_2.end());

    // Calculate distances
    int distance = 0;
    int size = std::min(list_1.size(), list_2.size()); // Just in case...
    for (int i = 0; i < size; i++) {
        int fst = list_1[i];
        int sec = list_2[i];
        distance += fst > sec ? fst - sec : sec - fst;
    }

    // Calculate similarity score
    int sim_score = 0;
    for (const auto& first: list_1) {
        int n_appearances = 0;
        for (const auto& second: list_2) {
            n_appearances += first == second; // TRUE = 1
        }
        sim_score += first * n_appearances;
    }

    std::cout << "The total distance is: " << distance << std::endl; 
    std::cout << "The similarity score is: " << sim_score << std::endl;
    return EXIT_SUCCESS;
}