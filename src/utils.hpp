#ifndef _UTILS_HPP_
#define _UTILS_HPP_

#include <string.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

typedef std::vector<std::vector<int> > int_matrix;

std::vector<std::string> parse_file(const std::string& path) {
    std::vector<std::string> lines;    
    std::ifstream file(path);
    
    if (!file.is_open()) {
        std::cout << "Could not open: " << path << std::endl; 
        return lines;
    }

    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    file.close();
    return lines;
}

// Taken from https://stackoverflow.com/questions/5888022/split-string-by-single-spaces
std::vector<std::string> split(const std::string& txt, const char ch)
{
    size_t pos = txt.find(ch);
    size_t initialPos = 0;
    std::vector<std::string> strs;

    // Decompose statement
    while( pos != std::string::npos ) {
        strs.push_back( txt.substr( initialPos, pos - initialPos ) );
        initialPos = pos + 1;

        pos = txt.find( ch, initialPos );
    }

    // Add the last one
    strs.push_back( txt.substr( initialPos, std::min( pos, txt.size() ) - initialPos + 1 ) );

    return strs;
}

int_matrix parse_input(const std::string& path) { // Only works for one space
    int_matrix parsed_input;

    std::vector<std::string> lines = parse_file(path);
    if (lines.empty()) {
        return parsed_input;
    }

    // Parse lines
    for (const auto& line: lines) {
        std::vector<int> parsed_line;
        std::vector<std::string> tokens = split(line, ' ');
        for (const auto& token: tokens) {
            parsed_line.push_back(std::stoi(token));
        }
        parsed_input.push_back(parsed_line);
    }

    return parsed_input;
}

void print_matrix(const int_matrix& m) {
    for (const auto& row: m) {
        for (const auto& num: row) {
            std::cout << num << " "; 
        }
        std::cout << std::endl;
    }
}

void print_array(const std::vector<int>& a) {
    for (const auto& elem: a) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

#endif // _UTILS_HPP_