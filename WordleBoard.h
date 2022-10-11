//
// Created by Vitor Pedrosa on 4/9/22.
//

#ifndef PROG1_WORDLEBOARD_H
#define PROG1_WORDLEBOARD_H
using namespace std;

class WordleBoard{
private:
    string solution;
public:
    explicit WordleBoard(string);
    static void printWord();
    void addWord(string guess);
    void checkWin(const string& guess);
    void printSolution();
};

#endif //PROG1_WORDLEBOARD_H
