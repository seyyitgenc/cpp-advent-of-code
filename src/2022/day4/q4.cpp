#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

void get_input(const std::string &path, std::vector<std::pair<std::string, std::string>> &input){
    std::fstream myfile(path);
    std::string line;
    while (std::getline(myfile, line))
    {
        int pos = line.find_first_of(",");
        input.push_back(std::pair(line.substr(0,pos),line.substr(pos + 1,line.length())));
    }
}

int p1_solve(std::vector<std::pair<std::string, std::string>>& data){
    int result = 0;
    return result;
}

int p2_solve(std::vector<std::pair<std::string, std::string>>& data){
    int result = 0;
    return result;
}


int main(){
    std::vector<std::pair<std::string, std::string>> input;
    get_input("C:/projects/cpp-advent-of-code/src/2022/day4/input.txt", input);
    std::cout << p1_solve(input) << std::endl;
    std::cout << p2_solve(input) << std::endl;
}
