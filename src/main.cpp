#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <array>
#include <fstream>
#include <sstream>
#define NO_NOTES 12

using namespace std;

struct Chord {
    string name;
    int* tensions;
};

Chord* addChord(string name, int tensions[]) {
    Chord* newChord = (Chord*)malloc(sizeof(Chord));
    newChord->name = name;
    newChord->tensions = (int*)calloc(NO_NOTES, sizeof(int));

    for(int i = 0; i < NO_NOTES; i++) {
        newChord->tensions[i] = tensions[i];
    }

    return newChord;
}

void deleteChord(Chord* chord) {
    free(chord->tensions);
    free(chord);
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
    const string notes[NO_NOTES] = {
        "C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab", "A", "Bb", "B"
    };// 0    1     2    3     4    5    6     7    8     9    10    11

    // Test: Display notes
    for(int i = 0; i < NO_NOTES; ++i) {
        cout << notes[(i + noteInput) % NO_NOTES] << "\t";
    }
    cout << endl;

    /*
        Tones and Tensions
            0 - Unacceptable Harmony = Unavailable Tensions/Avoid Notes
            1 - Weak Harmony = Root and 5th
            2 - Strong Harmony = Guide Tones
            3 - Jazzy Harmony = Available Tensions
    */

    // TODO Test color codes
    cout << "\033[30mUnacceptable Harmony\033[0m" << endl;
    cout << "\033[32mWeak Harmony\033[0m" << endl;
    cout << "\033[34mStrong Harmony\033[0m" << endl;
    cout << "\033[35mJazzy Harmony\033[0m" << endl;

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
    vector<Chord*> nondominantChords;
    vector<Chord*> dominantChords;
    int numTransfer[NO_NOTES];

    // Read nondominant chords
    while(getline(nondominant, chordName) && getline(nondominant, chordInfo)) {
        //cout << "Line 1: " << chordName << endl;
        //cout << "Line 2: " << chordInfo << endl;
        //cout << "====" << endl;
        int i = 0;
        stringstream chordNumbers(chordInfo);
        string temp;

        while(getline(chordNumbers, temp, ' ')) {
            if(i > 11) continue;
            numTransfer[i++] = stoi(temp);
        }

        nondominantChords.push_back(addChord(chordName, numTransfer));
    }
    
    // Read dominant chords
    while(getline(dominant, chordName) && getline(dominant, chordInfo)) {
        //cout << "Line 1: " << chordName << endl;
        //cout << "Line 2: " << chordInfo << endl;
        //cout << "====" << endl;
        int i = 0;
        stringstream chordNumbers(chordInfo);
        string temp;

        while(getline(chordNumbers, temp, ' ')) {
            if(i > 11) continue;
            numTransfer[i++] = stoi(temp);
        }

        dominantChords.push_back(addChord(chordName, numTransfer));
    }
    // Done with file reading
    nondominant.close();
    dominant.close();

    // There shouldn't be an odd number of lines, but maybe check for it...?

    // Test that everything saved to the vectors just fine
    cout << "Non-Dominant Chords" << endl;
    for(const Chord* chord : nondominantChords) {
        cout << chord->name << endl;
        for(int i = 0; i < NO_NOTES; i++) {
            cout << chord->tensions[i];
            if(i < NO_NOTES - 1) cout << " ";
        }
        cout << endl;
    }

    cout << "Dominant Chords" << endl;
    for(const Chord* chord : dominantChords) {
        cout << chord->name << endl;
        for(int i = 0; i < NO_NOTES; i++) {
            cout << chord->tensions[i];
            if(i < NO_NOTES - 1) cout << " ";
        }
        cout << endl;
    }

    // Clean up
    for(Chord*& chord : nondominantChords) {
        deleteChord(chord);
    }
    for(Chord*& chord : dominantChords) {
        deleteChord(chord);
    }
    nondominantChords.clear();
    dominantChords.clear();

    return 0;
}