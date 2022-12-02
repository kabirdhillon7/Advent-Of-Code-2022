#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main() {
    // Part 1
    // open input file
    ifstream input;
    input.open("input.txt");

    // need to have a score vector
    vector<int> scores;

    // read through input using (while) loop
    // while we don't have a blank/empty line...
        // collect sum of portion elf's scores
        // when we hit the blank line, push back sum into vector
    string line;
    int sum = 0;

    while(getline(input, line)) {
        if(line.empty()){
            scores.push_back(sum);
            sum = 0;
            continue;
        }
        sum += stoi(line);
    }

    input.close();

    // we want the max value of vector
    // return max of score vector
    int result = 0;
    for (int score : scores){
        if (result < score){
            result = score;
        }
    }

    cout << "Top Calorie Amount: " << result << endl;

    // Part 2:
    // we want to get the top 3 scores summed

    // sort through scores using built in sort, can use other methods too
    sort(scores.begin(), scores.end());

    // we want to get the last 3 elements in sorted scores
    int i = 0;
    int index = scores.size() - 1;
    int top3Scores = 0;
    while (i < 3){
        top3Scores += scores[index];

        index--;
        i++;
    }
    cout << "Total of Top 3: " << top3Scores;
    // return 0;
}
