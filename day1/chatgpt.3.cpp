#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <vector>

int main() {
  // Open the input file
  std::ifstream input("input.txt");

  // Read the numbers from the file into a vector
  std::vector<int> numbers;
  int number;
  while (input >> number) {
    numbers.push_back(number);
  }

  // Initialize the maximum group total to the minimum possible value
  int max_group_total = std::numeric_limits<int>::min();

  // Initialize the current group total to 0
  int current_group_total = 0;

  // Loop through the numbers in the vector
  for (const auto &number : numbers) {
    // If the current number is a blank line, update the maximum group total
    // if necessary and reset the current group total to 0
    if (number == 0) {
      max_group_total = std::max(max_group_total, current_group_total);
      current_group_total = 0;
    }
    // Otherwise, add the number to the current group total
    else {
      current_group_total += number;
    }
  }

  // Update the maximum group total if necessary one last time
  max_group_total = std::max(max_group_total, current_group_total);

  // Print the maximum group total
  std::cout << "The largest group total is: " << max_group_total << std::endl;

  return 0;
}
