#include <iostream>
#include <vector>
#include <string>

#include <fstream>
#include <sstream>
#include <set>

#include <cstdio>
// problem link : https://adventofcode.com/2022/day/3 

void get_input(std::string path,std::vector<std::string>& data){
    std::fstream myfile(path);
    std::string line;
    
    while (std::getline(myfile,line))
        data.push_back(line);
    
    myfile.close();
}

int p1_solve(std::vector<std::string> &data){
    int result = 0;
    std::set<char> test;
    std::
    for (auto &&string : data)
    {
        std::vector<int> mini_set1(52); // for first_half
        std::vector<int> mini_set2(52); // for second_half

        int size = string.size();
        std::string first_half  = string.substr(0, size / 2);
        std::string second_half = string.substr(size / 2, size);

        for (auto &&i : first_half)
        {
            // lets get index of ascii character
            int value_of_char = i - 0;
            // 0 - 25 lower 
            // 26 - 51 upper
            if (value_of_char >= 97){
                mini_set1[value_of_char - 97]++; // uppercase
            }
            else{
                mini_set1[value_of_char - 65 + 26]++; //uppercase
            } 
        }
        for (auto &&i : second_half)
        {
            // lets get index of ascii character
            int value_of_char = i - 0;
            // 0 - 25 lower 
            // 26 - 51 upper
            if (value_of_char >= 97){
                mini_set2[value_of_char - 97]++; // uppercase
            }
            else{
                mini_set2[value_of_char - 65 + 26]++; //uppercase
            } 
        }
        for (int index = 0; index < 52; index++)
        {
            // two boxes shares same item so lets add the value
            if (mini_set1[index] > 0 && mini_set2[index] > 0)
                result += index + 1;
        }
    }
    #if false // for debugging purposes
    {
        std::cout << "mini_set 2" << std::endl;
        for (auto &&i : mini_set1)
        {
            std::cout << i << ", ";
        }
        std::cout << "mini_set 2" << std::endl;
        for (auto &&i : mini_set2)
        {
            std::cout << i << ", ";
        }
        /* code */
    }
    #endif
    
    return result;
};
int p2_solve(std::vector<std::string> &data){
    int result = 0;
    for (int i = 0; i < data.size(); i += 3)
    {
        std::vector<std::pair<std::string,std::vector<int>>> group;

        group.push_back(std::pair(data[i], std::vector<int>(52)));
        group.push_back(std::pair(data[i + 1], std::vector<int>(52)));
        group.push_back(std::pair(data[i + 2], std::vector<int>(52)));
        
        for (auto &&item : group)
        {
            for (auto &&character : item.first)
            {
                int value_of_char = character - 0;
                if (value_of_char >= 97)
                    item.second[value_of_char - 97]++;
                else
                    item.second[value_of_char - 65 + 26]++;
            }
        }
        
        for (int j = 0; j < 52; j++) // for badge value
        {
            if(group[0].second[j] > 0 && group[1].second[j] > 0 && group[2].second[j] > 0){
                result += j + 1;
            }
        }

        // std::vector<std::vector<int>> group;
        // group.push_back(std::vector<int>(52));
        // group.push_back(std::vector<int>(52));
        // group.push_back(std::vector<int>(52));

        // std::string string1 = data[i];
        // std::string string2 = data[i + 1];
        // std::string string3 = data[i + 2];
        // NOTE: temporary solution
        // for (auto &&i : string1)
        // {
        //     int value_of_char = i - 0;
        //     if (value_of_char >= 97)
        //         group[0][value_of_char - 97]++; // uppercase
        //     else
        //         group[0][value_of_char - 65 + 26]++; // uppercase
        // }
        // for (auto &&i : string2)
        // {
        //     int value_of_char = i - 0;
        //     if (value_of_char >= 97)
        //         group[1][value_of_char - 97]++; // uppercase
        //     else
        //         group[1][value_of_char - 65 + 26]++; // uppercase

        // }
        // for (auto &&i : string3)
        // {
        //     int value_of_char = i - 0;
        //     if (value_of_char >= 97)
        //         group[2][value_of_char - 97]++; // uppercase
        //     else
        //         group[2][value_of_char - 65 + 26]++; // uppercase
        // }

        // for (int j = 0; j < 52; j++)
        // {
        //     if(group[0][j] > 0 && group[1][j] > 0 && group[2][j] > 0){
        //         result += j + 1;
        //     }
        // }

        
    }
    
    #if false // for debugging purposes
    {
        std::cout << "mini_set 2" << std::endl;
        for (auto &&i : mini_set1)
        {
            std::cout << i << ", ";
        }
        std::cout << "mini_set 2" << std::endl;
        for (auto &&i : mini_set2)
        {
            std::cout << i << ", ";
        }
        /* code */
    }
    #endif
    
    return result;
};

int main(){
    std::vector<std::string> input;
    get_input("C:/projects/cpp-advent-of-code/src/2022/day3/input.txt",input);

    // std::cout << "Part 1 result : " << p1_solve(input) << std::endl;
    std::cout << "Part 2 result : " << p2_solve(input) << std::endl;

    return 1;
}
