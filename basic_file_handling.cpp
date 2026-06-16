#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ifstream file ("data.txt");
    string word;
    file >> word;
    cout << word;
    file >> word;
    cout << word << endl;

    file.ignore();

    string line;
    getline(file, line);
    cout << line;

    file.close();
    return 0;
}