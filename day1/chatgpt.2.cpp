#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  // Open the input file
  ifstream input_file("input.txt");

  // Read the numbers from the file
  vector<int> numbers;
  int number;
  while (input_file >> number) {
    numbers.push_back(number);
  }

  // Compute the largest group total
  int max_group_total = 0;
  int current_group_total = 0;
  for (int i = 0; i < numbers.size(); i++) {
    if (numbers[i] == 0) {
      // If we encounter a 0, this indicates the end of a group
      max_group_total = max(max_group_total, current_group_total);
      current_group_total = 0;
    } else {
      // Otherwise, add the number to the current group total
      current_group_total += numbers[i];
    }
  }

  // Print the largest group total
  cout << "Largest group total: " << max_group_total << endl;

  return 0;
}
