/**
 * Name: Vitor Pedrosa
 * Date: Aprill 11, 2022
 * Course: CS 360
 * Description:
 •This code read all 5 letter words from a file.
 •This code must checks that word is valid.
 •This code randomly picks a solution.
 •This code accepts 6 guesses from the user
 •This code uses the WordleBoard class to print the board after each guess.
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <algorithm>  
#include <random>
#include "WordleBoard.h"

using namespace std;
vector<string> list;


string pickSolution();
void readData(const string& file);
string validity();

int main() {
    //Input word file
    string file;
    string guess;
    cout << "Welcome to EOU Wordle!\n\n";
    //Read data from file
    readData(file);
    //Create board with solution
    WordleBoard board(pickSolution());
    //Ask for input
    for (int i = 0; i < 6; ++i) {
        guess = validity();
        board.addWord(guess);
        board.printWord();
        board.checkWin(guess);
    }
    board.printSolution();

}
/**
 * Chekcs if user enter valid word
 * @return guess
 */
string validity(){
    string guess;
    vector<int>::iterator it;
    while(true) {
        cout << "Enter your guess:";
        cin >> guess;
        if (guess.size() > 5 || guess.size() < 5)
            cout << "More/Less than 5 words!\n";
        else if (find(list.begin(), list.end(), guess) != list.end())
            return guess;
        else
            cout << "Element not found\n";
    }

}

/**
 * Picksa random word from the file using the time(0) seed
 * @return solution
 */

string pickSolution() {
    std::random_device rd;
    std::mt19937 gen(rd());
    (default_random_engine(time(nullptr)));
    uniform_int_distribution<int> longDistro(0,list.size());
    return list[longDistro(gen)];
}

/**
 * reads data from file
 * @param file to be read
 */
void readData(const string& file){
    ifstream inFile;
    inFile.open("sgb-words.txt");

    string line;
    if( !inFile.is_open() ) {
        cout << "Cannot open file" << endl;
    }
    else {
        while (!inFile.eof()) {
            getline(inFile, line);
            list.push_back(line);

            if (inFile.eof())
                break;
        }
    }
    inFile.close();
}

