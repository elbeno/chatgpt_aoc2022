// I have a file where each line is a string. There is one character in common
// between the first half and the second half of each string. I need to find
// that character, and score it - the score is 1 to 26 for a through z, 27 to 52
// for A through Z. Write a C++ program to find the total score for the file.

#include <iostream>
#include <fstream>
#include <string>

int main() {
  std::string line;
  int score = 0;
  std::ifstream infile("filename.txt"); // replace "filename.txt" with the actual name of your file
  while (std::getline(infile, line)) {
    // find the character in common between the first and second half of the line
    char common_char = line[line.length() / 2];
    // determine the score for this character (1-26 for a-z, 27-52 for A-Z)
    int char_score = 0;
    if (common_char >= 'a' && common_char <= 'z') {
      char_score = common_char - 'a' + 1;
    } else if (common_char >= 'A' && common_char <= 'Z') {
      char_score = common_char - 'A' + 27;
    }
    // add this score to the total score
    score += char_score;
  }
  std::cout << "Total score: " << score << std::endl;
  return 0;
}
