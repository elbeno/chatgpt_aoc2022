// I have a file where each line is a string. There is one character from the
// first half of each string that is repeated in the second half. I need to find
// that character, and score it - the score is 1 to 26 for a through z, 27 to 52
// for A through Z. Write a C++ program to find the total score for the file.

#include <fstream>
#include <iostream>
#include <string>

int main() {
  // Open the file for reading
  std::ifstream file("file.txt");

  // Check if the file was opened successfully
  if (!file.is_open()) {
    std::cerr << "Error: failed to open file\n";
    return 1;
  }

  // Initialize the total score to 0
  int total_score = 0;

  // Read the file line by line
  std::string line;
  while (std::getline(file, line)) {
    // Get the length of the line
    int length = line.length();

    // Check if the length of the line is even
    if (length % 2 == 0) {
      // Get the index of the first character from the first half of the string
      int mid = length / 2;

      // Find the character that is repeated in the second half of the string
      for (int i = 0; i < mid; i++) {
        if (line[i] == line[mid + i]) {
          // Calculate the score for the character
          // The score is 1 to 26 for a through z, 27 to 52 for A through Z
          int score = 0;
          if (line[i] >= 'a' && line[i] <= 'z') {
            score = line[i] - 'a' + 1;
          } else if (line[i] >= 'A' && line[i] <= 'Z') {
            score = line[i] - 'A' + 27;
          }

          // Add the score to the total score
          total_score += score;

          // Stop searching for the character
          break;
        }
      }
    }
  }

  // Print the total score
  std::cout << "Total score: " << total_score << std::endl;

  file.close();
  return 0;
}
