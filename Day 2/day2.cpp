#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    // Part 1
    // open input file
    ifstream input;
    input.open("input.txt");

    // need to keep track of score
    int score1, score2 = 0;

    // we're mapping each move to 0,1,3 and then x3 each move
    int evaluate_match[9] = { 4, 1, 7, 8, 5, 2, 3, 9, 6 };


    // go line by line through input using getline
    string round;
    while(getline(input, round)) {
        // we want to remove the space between the 2 plays
        // compare first char to the second char (since " " removed)
        char opponentMove = round[0];
        char myMove = round[2];

        score1 += evaluate_match[opponentMove-'A'+3*(myMove-'X')];
        score2 += evaluate_match[opponentMove-'A'+3*((opponentMove-'A'+(myMove-'X'+2)%3)%3)];
    }

    // print sum
    cout << "Part 1: " << score1 << endl;
    cout << "Part 2: " << score2 << endl;

    return 0;
}
