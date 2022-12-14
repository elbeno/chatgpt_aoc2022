// I have a file that contains 2 closed intervals per line, separated by a
// comma. An interval is two numbers (low and high) separated by a hyphen. Of
// the lines, how many have one interval contained within the other? Write a C++
// program to figure this out.

#include <iostream>
#include <string>

using namespace std;

// This function checks if one interval is contained within the other.
// It takes in two strings representing the intervals and returns true
// if one interval is contained within the other, and false otherwise.
bool is_contained(const string& interval1, const string& interval2) {
  // Parse the low and high values of each interval
  int low1, high1, low2, high2;
  sscanf(interval1.c_str(), "%d-%d", &low1, &high1);
  sscanf(interval2.c_str(), "%d-%d", &low2, &high2);

  // Check if one interval is contained within the other
  return (low1 >= low2 && high1 <= high2) || (low2 >= low1 && high2 <= high1);
}

int main() {
  // Read each line from the input file
  string line;
  while (getline(cin, line)) {
    // Split the line on the comma to get the two intervals
    int comma_pos = line.find(',');
    string interval1 = line.substr(0, comma_pos);
    string interval2 = line.substr(comma_pos + 1);

    // Check if one interval is contained within the other and increment
    // the count if it is
    int count = 0;
    if (is_contained(interval1, interval2)) {
      count++;
    }

    cout << "Line " << count << ": " << line << endl;
  }

  return 0;
}
