#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <array>
#include <fstream>

using namespace std;

struct Chord {
    string name;
    int* tensions;
};

Chord addChord(string name, int* tensions) {
    Chord newChord = {name, tensions};
    return newChord;
}

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
    const string notes[12] = {
        "C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab", "A", "Bb", "B"
    };// 0    1     2    3     4    5    6     7    8     9    10    11

    // Test: Display notes
    for(int i = 0; i < 12; ++i) {
        cout << notes[(i + noteInput) % 12] << "\t";
    }
    cout << endl;

    /*
        Tones and Tensions
            0 - Unacceptable Harmony = Unavailable Tensions/Avoid Notes
            1 - Weak Harmony = Root and 5th
            2 - Strong Harmony = Guide Tones
            3 - Jazzy Harmony = Available Tensions
    */

    // Have an awesome double array to keep track of these ugly numbers
    const string chordNames[9] = {
        "Major 7", "Minor 7", "Half Diminished 7",
        "Minor Major 7", "Augmented Major 7", "Diminished 7",
        "Dominant 7", "Suspended 7", "Augmented 7"
    };
    const int availableTensions[9][12] = {
        // Non-Dominant Chords
        {1, 0, 3, 0, 2, 0, 3, 1, 0, 3, 0, 2}, // Major 7
        {1, 0, 3, 2, 0, 3, 0, 1, 0, 3, 2, 0}, // Minor 7
        {1, 0, 3, 2, 0, 3, 1, 0, 3, 0, 2, 0}, // Half Diminished 7
        {1, 0, 3, 2, 0, 3, 0, 1, 0, 3, 0, 2}, // Minor Major 7
        {1, 0, 3, 0, 2, 0, 3, 0, 1, 0, 0, 2}, // Augmented Major 7
        {1, 0, 3, 2, 0, 3, 1, 0, 3, 2, 0, 3}, // Diminished 7
        // Dominant Chords
        {1, 3, 3, 3, 2, 0, 3, 1, 3, 3, 2, 0}, // Dominant 7
        {1, 3, 3, 3, 3, 2, 0, 1, 3, 3, 2, 0}, // Suspended 7
        {1, 3, 3, 3, 2, 0, 3, 0, 1, 3, 2, 0}  // Augmented 7
    };

    // TODO Test color codes
    cout << "\033[30mUnacceptable Harmony\033[0m" << endl;
    cout << "\033[32mWeak Harmony\033[0m" << endl;
    cout << "\033[34mStrong Harmony\033[0m" << endl;
    cout << "\033[35mJazzy Harmony\033[0m" << endl;

    // TODO Test int* shenanigans
    /*
    int no_notes = 12;
    int* ptr;
    ptr = (int*)malloc(sizeof(int) * no_notes);
    ptr[0] = 1;
    ptr[1] = 0;
    ptr[2] = 3;
    ptr[3] = 0;
    ptr[4] = 2;
    ptr[5] = 0;
    ptr[6] = 3;
    ptr[7] = 1;
    ptr[8] = 0;
    ptr[9] = 3;
    ptr[10] = 0;
    ptr[11] = 2;

    vector<Chord> chords;
    chords.push_back(addChord("Major 7", ptr));

    // Test for the actual tension highlighting before adding file operations
    // TODO Redo the colors
    for(const Chord& chord : chords) {
        cout << chord.name << endl;
        for(int i = 0; i < no_notes; ++i) {
            cout << chord.tensions[i] << "\t";
        }
        cout << endl;
        for(int i = 0; i < no_notes; ++i) {
            string output = notes[(i + noteInput) % 12];
            switch (chord.tensions[i])
            {
            case 2:
                // Strong harmony
                cout << "\033[34m" << output << "\033[0m\t";
                break;
            case 1:
                // Weak harmony
                cout << "\033[32m" << output << "\033[0m\t";
                break;
            case 3:
                // Jazzy harmony
                cout << "\033[35m" << output << "\033[0m\t";
                break;
            default:
                // Unacceptable harmony
                cout << "\033[30m" << output << "\033[0m\t";
                break;
            }
        }
        cout << endl;
    }
    */

    // TODO Test file reading (setup and error handling)
    ifstream nondominant("../nondominant.txt");
    ifstream dominant("../dominant.txt");
    if(!nondominant.is_open() || !dominant.is_open()) {
        cerr << "Error opening one or more files." << endl;
        return 1;
    }

    // Reading
    string chordName;
    string chordInfo;
    cout << "Non-Dominant Chords" << endl;
    while(getline(nondominant, chordName) && getline(nondominant, chordInfo)) {
        cout << "Line 1: " << chordName << endl;
        cout << "Line 2: " << chordInfo << endl;
        cout << "====" << endl;
    }
    cout << "Dominant Chords" << endl;
    while(getline(dominant, chordName) && getline(dominant, chordInfo)) {
        cout << "Line 1: " << chordName << endl;
        cout << "Line 2: " << chordInfo << endl;
        cout << "====" << endl;
    }

    // There shouldn't be an odd number of lines, but maybe check for it...?

    // Clean up
    nondominant.close();
    dominant.close();
    //chords.clear();
    //free(ptr);
    return 0;
}