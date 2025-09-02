#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Set up array of strings
    vector<string> notes = {"C "};
    notes.push_back("Db");

    for(const string& note : notes) {
        cout << note << endl;
    }

    return 0;
}