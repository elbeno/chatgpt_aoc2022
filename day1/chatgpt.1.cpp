#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  // Open the file for reading
  ifstream in("file.txt");

  // Initialize the variables
  int number;
  int groupTotal = 0;
  int largestTotal = 0;
  vector<int> group;

  // Read the numbers from the file
  while (in >> number) {
    // If the number is negative, it indicates the end of a group
    if (number < 0) {
      // Check if the current group's total is larger than the largest total
      if (groupTotal > largestTotal) {
        // Update the largest total and the group with the largest total
        largestTotal = groupTotal;
        group = vector<int>(currentGroup);
      }

      // Reset the group total
      groupTotal = 0;
    } else {
      // Add the number to the current group and update the group total
      group.push_back(number);
      groupTotal += number;
    }
  }

  // Print the group with the largest total
  cout << "The group with the largest total is: " << endl;
  for (int n : group) {
    cout << n << endl;
  }
  cout << "The total is: " << largestTotal << endl;

  return 0;
}
