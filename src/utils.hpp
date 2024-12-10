#ifndef _UTILS_HPP_
#define _UTILS_HPP_

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

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

#endif // _UTILS_HPP_