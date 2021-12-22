#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;


int count_increases(string filename){
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

int main(int argc, const char *argv[]) {
    cout << count_increases(argv[1]) << endl;
}