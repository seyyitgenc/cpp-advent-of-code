#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

// problem link : https://adventofcode.com/2022/day/2

// TODO : need to implement filesystem to get rid of absolute path

void get_input(const std::string& path, std::vector<std::vector<std::string>> &input){
    std::ifstream myfile(path);
    std::string line;
    
    std::vector<std::string> row;
    
    int score = 0;
    while (std::getline(myfile, line))
    {
        std::stringstream stream(line);
        std::string data;
        while (stream >> data) // to read all data in each row
            row.push_back(data);

        if (!row.empty())
        {
            input.push_back(row);
            row.clear();
        }
    }
    // we add last element with this because we skip on top
    if (!row.empty())
        input.push_back(row);
    myfile.close();
}


// solver for part1
int p1_solve(std::vector<std::vector<std::string>> &data){
    int score = 0;

    for (auto &&row : data)
    {
        // C Z draw 90 - 67 = 23 = delta = 0
        // A Y win 89 - 65  = 24 = delta = 1
        // B X lose 88 - 66 = 22 = delta = 2
        score += row[1][0] - 'X' + 1; // we added our data hand score

        // -23 is for absolute difference "A" and "X". + 3 is to prevenet negative data. our delta range is  0 - 3 
        int delta = (row[1][0] - row[0][0] - 23 + 3 ) % 3;

        if (delta == 0) // draw
            score += 3;
        else if (delta == 1)
            score += 6;
        // otherwise lose so do nothing
    }
    
    return score;
}
// solver for part2
int p2_solve(std::vector<std::vector<std::string>> &data){
    int score = 0;
    
    // X = LOSE, Y = DRAW, Z = WIN
    // lets write all possible inputs
    
    // AX , BX , CX NEED TO LOSE
    // -Z , -X , -Y 

    // AZ , BZ , CZ NEED TO WIN
    // -Y, -Z, -X

    // AY , BY , CY NEED TO DRAW
    // -X, -Y, -Z

    // i will never come up with that kind of an solution
    // for (auto &&row : data)
    // {
    //     int delta = (row[0][0] + row[1][0] - 128 - 25) % 3;
    //     if (delta == 0)
    //         delta = 3;
    //     score += delta + ((row[1][0] - 'X') * 3); 
    // }
    // return score;

    // my dumbest soltion but it workds
    for (auto &&row : data)
    {
        if (row[1][0] == 'X')
        {
            // LOSE
            if (row[0][0] == 'A')
                score += 3;
            if (row[0][0] == 'B')
                score += 1;
            if (row[0][0] == 'C')
                score += 2;
        }
        if (row[1][0] == 'Y')
        {
            // DRAW
            if (row[0][0] == 'A')
                score += 4;
            if (row[0][0] == 'B')
                score += 5;
            if (row[0][0] == 'C')
                score += 6;
        }
        if (row[1][0] == 'Z')
        {
            // WIN
            if (row[0][0] == 'A')
                score += 8;
            if (row[0][0] == 'B')
                score += 9;
            if (row[0][0] == 'C')
                score += 7;
        }
    }
    return score;
}

int main(){
    std::vector<std::vector<std::string>> calories;
    get_input("C:/projects/cpp-advent-of-code/src/2022/day2/input.txt", calories);
    std::cout << "Part 1 result : " << p1_solve(calories) << std::endl;
    std::cout << "Part 2 result : " << p2_solve(calories) << std::endl;
    return 0;
}