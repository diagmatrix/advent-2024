#include<iostream>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

#include "utils.hpp"

const char* INPUT = "data/day_2/input.txt";

bool safe_report(const std::vector<int>& report);

int main() {
    std::cout << "Solution to day 2!" << std::endl;

    // Get list
    int_matrix input = parse_input(INPUT);
    if (input.empty()) {
        std::cout << "Error parsing input" << std::endl;
        return EXIT_FAILURE;
    }

    // Get safe reports
    int safe_reports = 0;
    int safe_dampener_reports = 0;
    for (const auto& report: input) {
        safe_reports += safe_report(report); // True = 1

        bool safe_without_pos = false;
        std::vector<int> mut_report;
        for (int i = 0; i < report.size(); i++) {
            if (safe_without_pos) {
                break;
            }

            for (int j = 0; j < report.size(); j++) {
                if (i != j) {
                    mut_report.push_back(report[j]);
                }
            }

            safe_without_pos = safe_report(mut_report);
            mut_report.clear();
        }
        safe_dampener_reports += safe_without_pos; // True = 1
        
    }

    std::cout << "Safe reports: " << safe_reports << std::endl; 
    std::cout << "Safe dampener reports: " << safe_dampener_reports << std::endl;
    return EXIT_SUCCESS;
}

bool safe_report(const std::vector<int>& report) {
    bool safe_level = true;
    bool tendency = report.size() > 2 ? std::signbit(report[1] - report[0]) : false; // Default asc
    for (int i = 0; i < report.size() - 1; i++) {
        // Check tendency
        bool tendency_check = tendency == std::signbit(report[i+1] - report[i]);
        // Check adjacent
        bool adjacent_check = std::abs(report[i] - report[i+1]) >= 1 && std::abs(report[i] - report[i+1]) <= 3;
        // Adjust safe level
        safe_level = tendency_check && adjacent_check;
        if (!safe_level) {
            break;
        }
    }

    return safe_level;   
}