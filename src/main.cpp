#include <iostream>
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
            0 - Unavailable Tension
            1 - Weak chord tones (1st and 5th)
            2 - Guide tones (3rd and 7th)
            3 - Available tensions (9th, 11th, 13th, etc.)
    */

    // Non-Dominant chords: Maj7, m7, m7b5, mMaj7, Maj+7, diminished
    const int major7[12] = {1, 0, 3, 0, 2, 0, 3, 1, 0, 3, 0, 2};
    const int minor7[12] = {1, 0, 3, 2, 0, 3, 0, 1, 0, 3, 2, 0};
    const int halfDiminished7[12] = {1, 0, 3, 2, 0, 3, 1, 0, 3, 0, 2, 0};
    const int minorMajor7[12] = {1, 0, 3, 2, 0, 3, 0, 1, 0, 3, 0, 2};
    const int augmentedMajor7[12] = {1, 0, 3, 0, 2, 0, 3, 0, 1, 0, 0, 2};
    const int diminished7[12] = {1, 0, 3, 2, 0, 3, 1, 0, 3, 2, 0, 3};

    // Dominant chords: 7, 7sus, +7
    const int dominant7[12] = {1, 3, 3, 3, 2, 0, 3, 1, 3, 3, 2, 0};
    const int suspended7[12] = {1, 3, 3, 3, 3, 2, 0, 1, 3, 3, 2, 0};
    const int augmented7[12] = {1, 3, 3, 3, 2, 0, 3, 0, 1, 3, 2, 0};
    
    return 0;
}