// I have a file where each line represents a two-player game of rock paper
// scissors with the moves separated by a space. A and X are rock, B and Y are
// paper, C and Z are scissors. I am player 2 (the second column in the file).
// Each game, I score 0 for a loss, 3 for a draw and 6 for a win, plus points
// for what I played - 1 for rock, 2 for paper and 3 for scissors. Write a C++
// program to read the file and figure out my total score over all the games.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// This function returns 0 for a loss, 3 for a draw, and 6 for a win
int score(char myMove, char otherMove) {
  if (myMove == otherMove) {
    // Draw
    return 3;
  } else if (myMove == 'A' && otherMove == 'B') {
    // I played rock and the other player played paper
    return 0;
  } else if (myMove == 'A' && otherMove == 'C') {
    // I played rock and the other player played scissors
    return 6;
  } else if (myMove == 'B' && otherMove == 'C') {
    // I played paper and the other player played scissors
    return 0;
  } else if (myMove == 'B' && otherMove == 'A') {
    // I played paper and the other player played rock
    return 6;
  } else if (myMove == 'C' && otherMove == 'A') {
    // I played scissors and the other player played rock
    return 0;
  } else if (myMove == 'C' && otherMove == 'B') {
    // I played scissors and the other player played paper
    return 6;
  } else {
    // This should never happen
    return 0;
  }
}

int main() {
  // Open the file
  ifstream file("games.txt");

  if (!file.is_open()) {
    // File could not be opened
    cerr << "Error: could not open games.txt" << endl;
    return 1;
