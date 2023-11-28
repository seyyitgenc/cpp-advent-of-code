#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

// problem link : https://adventofcode.com/2022/day/1

// TODO : need to implement filesystem to get rid of absolute path

void get_input(const std::string& path, std::vector<std::vector<int>> &data){
    std::ifstream myfile(path);
    std::string line;
    
    std::vector<int> row;
    
    while (std::getline(myfile, line))
    {
        if (!line.empty())
            row.push_back(std::stoi(line));
        else{
            if (!row.empty())
            {
                data.push_back(row);
                row.clear();
            }
        }
    }
    // we add last element with this because we skip on top
    if (!row.empty())
        data.push_back(row);
    myfile.close();
}


// solver for part1
int p1_solve(std::vector<std::vector<int>> &data){
    int max = 0;
    for (auto row : data)
    {
        int sum = 0;
        for (auto data : row)
            sum += data;
        max = std::max(max, sum);
    }

    return max;
}
// solver for part2
int p2_solve(std::vector<std::vector<int>> &data){
    int max1, max2 ,max3 = 0;
    
    std::vector<int> summation;

    for (auto row : data)
    {
        int sum = 0;
        for (auto data : row)
            sum += data;
        summation.push_back(sum);
    }
    std::sort(summation.begin(), summation.end(), std::greater<int>());
    int output = 0;

    for (int i = 0; i < 3; i++)
        output += summation[i];

    return output;
}

int main(){
    std::vector<std::vector<int>> calories;
    get_input("C:/projects/cpp-advent-of-code/src/2022/day1/input.txt", calories);
    std::cout << "Part 1 result : " << p1_solve(calories) << std::endl;
    std::cout << "Part 2 result : " << p2_solve(calories) << std::endl;
    return 0;
}