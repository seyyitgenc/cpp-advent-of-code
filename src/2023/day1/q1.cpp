#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <unordered_map>
#include "filesystem.h"

// problem link : https://adventofcode.com/2023/day1

void get_input_p1(const std::string path ,std::vector<std::string> &data){
    std::fstream file(path);
    std::string line;
    while (std::getline(file,line)){
        std::string numbers;
        for (auto &&ch : line)
        {
            int n = ch - 48;
            if (n <= 9)
                numbers += ch;
        }
        data.push_back(numbers);
    }
    
}

// note: i can optimize this a little bit more maybe
void get_input_p2(const std::string path ,std::vector<std::string> &data){
    std::unordered_map<std::string, std::string> map;
    map["one"]   = "1"; map["two"]   = "2"; map["three"] = "3";
    map["four"]  = "4"; map["five"]  = "5"; map["six"]   = "6";
    map["seven"] = "7"; map["eight"] = "8"; map["nine"]  = "9";

    std::fstream file(path);
    std::string line;
    // lets create an input to solve it easily
    while (std::getline(file,line)){
        std::string number;
        for (int i = 0; i < line.size(); i++)
        {
            std::string test;
            test.clear();
            for (int j = i; j < i+ 5 && j < line.size(); j++)
            {
                test += line[j];
                if (map.find(test) != map.end())
                {
                    // std::cout << test << std::endl;
                    number += map[test];
                    break;
                }
            }

            int n = line[i] - 48;
            if (n <= 9)
                number += line[i];

        }
        data.push_back(number);
    }
}


int p1_solve(std::vector<std::string> &data){
    int result = 0;

    for (auto &&item : data)
    {
        std::string number = "";
        number +=  item.at(0);
        number += item.at(item.size() - 1);
        result += std::stoi(number);
    }
    
    return result;
}

int p2_solve(std::vector<std::string> &data){
    int result = 0;
    for (auto &&item : data)
    {
        std::string number = "";
        number +=  item.at(0);
        number += item.at(item.size() - 1);
        result += std::stoi(number);
    }
    
    return result;
}

int main(){
    std::vector<std::string> input;
    get_input_p1(FileSystem::getPath("src/2023/day1/input.txt"),input);
    std::cout << "Part 1 : " << p1_solve(input) << std::endl;
    input.clear();
    get_input_p2(FileSystem::getPath("src/2023/day1/input.txt"),input);
    std::cout << "Part 2 : " << p2_solve(input) << std::endl;

    return 0;
}
