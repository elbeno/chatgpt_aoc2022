// I have a file where each line represents a two-player game of rock paper
// scissors. A and X are rock, B and Y are paper, C and Z are scissors. I am
// player 2 (the second column in the file). Each game, I score 1 point for a
// win, 3 for a draw and 6 for a win, plus points for what I played - 1 for
// rock, 2 for paper and 3 for scissors. Write a C++ program to read the file
// and figure out my total score over all the games.

#include <iostream>
#include <fstream>
#include <string>

int score(char c) {
  if (c == 'A' || c == 'X') return 1;
  if (c == 'B' || c == 'Y') return 2;
  if (c == 'C' || c == 'Z') return 3;
  return 0;
}

int main() {
  // Open the file for reading
  std::ifstream infile("games.txt");

  // Initialize total score to 0
  int total_score = 0;

  // Read each line of the file
  std::string line;
  while (std::getline(infile, line)) {
    // Split the line into two characters
    char player1 = line[0];
    char player2 = line[1];

    // Calculate the score for this game
    int game_score = score(player2);
    if (player1 == player2) game_score += 3;
    if ((player1 == 'A' && player2 == 'C') ||
        (player1 == 'B' && player2 == 'A') ||
        (player1 == 'C' && player2 == 'B')) game_score += 6;

    // Add the score for this game to the total score
    total_score += game_score;
  }

  // Print the total score
  std::cout << "Total score: " << total_score << std::endl;

  return 0;
}
