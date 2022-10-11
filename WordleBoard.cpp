/**
 * Name: Vitor Pedrosa
 * Date: Aprill 11, 2022
 * Course: CS 360
 * Description:
 •This class is responsible for printing out the current and previous guesses, including
  determining the proper color for each letter of the guesses.
•This class keeps track of all the previous guesses, along with the solution.
 */


#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <cmath>
#include <sstream>
#include <map>
#include "WordleBoard.h"

using namespace std;
string board[6][6];
int numGuess = 0 ;
map<char,int> maps;
/**
 * Constructor for Wordle
 * @param s
 */
WordleBoard::WordleBoard(string s) {
    solution = move(s);
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            if(j == 0)
                board[i][j] = to_string(i + 1);
            else
                board[i][j] = "_";
        }
    }
    //Map num of words
    for(char & i : solution)
        maps[i]++;
}
/**
 * Prints Wordle board
 */
void WordleBoard::printWord() {
    for(auto & i : board) {
        for(auto & j : i){
            cout << j << ' ';
        }
        cout << endl;
    }
}
/**
 * Adds guess to 2d array
 * @param guess
 */
void WordleBoard::addWord(string guess) {
    map<char,int> counts = maps;
    stringstream buffer;
    char residue[5];
    string resi;
    //GREEN
    for (int i = 1; i < 6; ++i) {
        //If it's in the right place
        if (guess[i - 1] == solution[i - 1]) {
            buffer << "\033[1;32m" << guess[i - 1] << "\033[0m";
            board[numGuess][i] = buffer.str();
            buffer.str(string());
            counts[guess[i-1]]--;
        } else {
            residue[i - 1] = solution[i - 1];
            resi = string(residue);
        }
    }
    //YELLOW
    for (int i = 1; i < 6; ++i) {
        if (resi.find(guess[i - 1]) != string::npos) {
            if (board[numGuess][i] == "_") {
                if(counts[guess[i-1]] >= 1) {
                    buffer << "\033[1;33m" << guess[i - 1] << "\033[0m";
                    board[numGuess][i] = buffer.str();
                    buffer.str(string());
                    counts[guess[i-1]]--;
                }
            }
        }
    }

    //BLACK
    for (int i = 1; i < 6; ++i) {
        if (board[numGuess][i] == "_") {
            buffer << "\033[1;37m" << guess[i - 1] << "\033[0m";
            board[numGuess][i] = buffer.str();
            buffer.str(string());
        }
    }
    numGuess++;
}
/**
 * Checks if user entered correct solution for the game
 * @param guess
 */
void WordleBoard::checkWin(const string& guess) {
    if(guess == solution) {
        cout << "You win!";
        exit(1);
    }

}
/**
 * Prints solution if user lost the game
 */
void WordleBoard::printSolution() {
    cout << "Good try :(" << endl;
    cout << "The actual solution was: " << solution;

}


