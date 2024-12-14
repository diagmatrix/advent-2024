#include<iostream>
#include<string>
#include<vector>
#include <regex>

#include "utils.hpp"

const char* INPUT = "data/day_3/input.txt";
const std::sregex_iterator END;
const std::regex MUL_DO_DONT(R"(mul\(\d{1,3},\d{1,3}\)|do\(\)|don't\(\))");
const std::regex DIGITS(R"(\d{1,3})");

int main() {
    std::cout << "Solution to day 3!" << std::endl;

    std::vector<std::string> lines = parse_file(INPUT);
    
    // Multiplications
    int mult_sum = 0;
    int mult_sum_do_dont = 0;
    bool enabled = true;
    for (const auto& line: lines) {
        std::sregex_iterator matches(line.begin(), line.end(), MUL_DO_DONT);
        while (matches != END) {
            std::string match = (*matches).str();
            int mult = 1;

            if (match.find("don") == 0 ) {
                enabled = false;
            } else if (match.find("do") == 0) {
                enabled = true;
            } else {
                std::sregex_iterator nums(match.begin(), match.end(), DIGITS);
                while(nums != END) {
                    int num = std::stoi((*nums).str());
                    mult *= num;
                    ++nums;
                }

                mult_sum += mult;
                if (enabled) {
                    mult_sum_do_dont += mult;
                }
            }
            
            ++matches;
        }      
    }

    std::cout << "Mult result: " << mult_sum << std::endl;
    std::cout << "Mult do-dont result: " << mult_sum_do_dont << std::endl;
    return EXIT_SUCCESS;
}