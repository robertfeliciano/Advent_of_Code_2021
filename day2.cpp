#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>

//this time i don't feel like using the standard namespace :)

int part_1(std::string filename){
    std::ifstream input_file(filename);
    if (!input_file){
        std::cerr << "Error: Cannot open file '" << filename << "'." << std::endl;
        return 1;
    }
    input_file.exceptions(std::ifstream::badbit);
    std::string line;
    std::istringstream iss;
    int directions[2];
    directions[0] = 0;      //stores horizontal poisition
    directions[1] = 0;      //stores depth

    try {
        while (getline(input_file, line)) {
            iss.str(line);
            //the final character of each line is the amount of movement
            //getline doesn't read in newline characters
            int move = atoi(&line.at(line.size() - 1));
            iss.clear();
            std::string direction;
            size_t index = line.find(" ");
            direction = line.substr(0, index);

            if (direction.compare("forward") == 0){
                //if forward, we increase our horizontal position
                directions[0] += move;
            }
            else if (direction.compare("up") == 0){
                //if up, we decrease our depth 
                directions[1] -= move;
            }
            else{
                //otherwise the word must be down, so we increase our depth
                directions[1] += move;
            }
        }
        input_file.close();
    } catch (const std::ifstream::failure &f) {
        std::cerr << "Error: An I/O error occurred reading '" << filename << "'.";
        return 1;
    }

    return directions[0]*directions[1];
}

int part_2(std::string filename){
    std::ifstream input_file(filename);
    if (!input_file){
        std::cerr << "Error: Cannot open file '" << filename << "'." << std::endl;
        return 1;
    }
    input_file.exceptions(std::ifstream::badbit);
    std::string line;
    std::istringstream iss;
    int directions[2];
    directions[0] = 0;      //stores horizontal poisition
    directions[1] = 0;      //stores depth
    int aim = 0;

    try {
        while (getline(input_file, line)) {
            iss.str(line);
            //the final character of each line is the amount of movement
            //getline doesn't read in newline characters
            int move = atoi(&line.at(line.size() - 1));
            iss.clear();
            std::string direction;
            size_t index = line.find(" ");
            direction = line.substr(0, index);

            if (direction.compare("forward") == 0){
                //if forward, we increase our horizontal position
                directions[0] += move;
                if (aim != 0){
                    directions[1] += aim*move;
                }
            }
            else if (direction.compare("up") == 0){
                //if up, we decrease our depth 
                aim -= move;
            }
            else{
                //otherwise the word must be down, so we increase our depth
                aim += move;
            }
        }
        input_file.close();
    } catch (const std::ifstream::failure &f) {
        std::cerr << "Error: An I/O error occurred reading '" << filename << "'.";
        return 1;
    }
    return directions[1]*directions[0];
}

int main(int argc, char* argv[]){
    std::cout << "Part 1: " << part_1(argv[1]) << std::endl;
    std::cout << "Part 2: " << part_2(argv[1]) << std::endl;
}