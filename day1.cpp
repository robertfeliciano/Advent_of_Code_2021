#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;


int part_1(string filename){
    ifstream input_file(filename);
    if (!input_file) {
        cerr << "Error: Cannot open file '" << filename << "'." << endl;
        return 1;
    }
    input_file.exceptions(ifstream::badbit);
    string line;
    int current;
    istringstream iss;
    vector<int> input;

    try {
        while (getline(input_file, line)) {
            iss.str(line);
            iss >> current;
            input.push_back(current);
            iss.clear();
        }
        input_file.close();
    } catch (const ifstream::failure &f) {
        cerr << "Error: An I/O error occurred reading '" << filename << "'.";
        return 1;
    }
    int increases = 0;

    for (int i = 1; i < input.size(); i++){
        if (input[i] > input[i-1]) increases++;
    }
    return increases;
}

int part_2(string filename){
    ifstream input_file(filename);
    if (!input_file) {
        cerr << "Error: Cannot open file '" << filename << "'." << endl;
        return 1;
    }
    input_file.exceptions(ifstream::badbit);
    string line;
    int current;
    istringstream iss;
    vector<int> input;

    try {
        while (getline(input_file, line)) {
            iss.str(line);
            iss >> current;
            input.push_back(current);
            iss.clear();
        }
        input_file.close();
    } catch (const ifstream::failure &f) {
        cerr << "Error: An I/O error occurred reading '" << filename << "'.";
        return 1;
    }
    int increases = 0;


    vector<int> three_measurements;
    int sum = 0;
    for (int i = 0; i < input.size(); i++){
        for (int j = 0; j < 3; j++){
            sum += input[i+j];
        }
        three_measurements.push_back(sum);
        sum = 0;
    }

    for (int i = 1; i < three_measurements.size(); i++){
        if (three_measurements[i] > three_measurements[i-1]) increases++;
    }
    return increases;
}

int main(int argc, const char *argv[]) {
    cout << "Part 1: " << part_1(argv[1]) << endl;
    cout << "Part 2: " << part_2(argv[1]) << endl;
}
