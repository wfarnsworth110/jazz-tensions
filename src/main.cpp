#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    /*
        Two additional command line arguments:
            Chord/Melody mode (0 and 1 respectively) -- NOT ADDED YET
            Music note (0-11 C through B)
    */

    // Add strong input checking later
    if(argc != 2) {
        cout << "Please input an integer as argument. Try again." << endl;
        return 1;
    }
    int noteInput = stoi(argv[1]);
    if(noteInput < 0 || noteInput > 11)
        noteInput = 0;
    
    // Set up array of strings
    string notes[12] = {
        "C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab", "A", "Bb", "B"
    };// 0    1     2    3     4    5    6     7    8     9    10    11

    for(int i = 0; i < 12; ++i) {
        cout << notes[(i+noteInput)%12] << "\t";
    }
    cout << endl;

    vector<string> notes2 = {"C"};  // 0
    notes2.push_back("Db");          // 1
    notes2.push_back("D");           // 2
    notes2.push_back("Eb");          // 3
    notes2.push_back("E");           // 4
    notes2.push_back("F");           // 5
    notes2.push_back("Gb");          // 6
    notes2.push_back("G");           // 7
    notes2.push_back("Ab");          // 8
    notes2.push_back("A");           // 9
    notes2.push_back("Bb");          // 10
    notes2.push_back("B");           // 11

    for(const string& note : notes2) {
        cout << note << "\t";
    }
    cout << endl;

    return 0;
}