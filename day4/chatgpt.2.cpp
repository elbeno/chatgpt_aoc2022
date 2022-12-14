// I have a file that contains 2 closed intervals per line, separated by a
// comma. An interval is two numbers (low and high) separated by a hyphen. Of
// the lines, how many have overlapping intervals? Write a C++ program to figure
// this out.

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Returns true if the two intervals [a1, b1] and [a2, b2] overlap.
bool intervalsOverlap(int a1, int b1, int a2, int b2) {
  return (a1 <= b2 && b1 >= a2);
}

int main() {
  string line;
  int numOverlapping = 0;

  // Read the input.
  while (getline(cin, line)) {
    stringstream ss(line);
    string interval1, interval2;

    // Parse the two intervals on the current line.
    if (getline(ss, interval1, ',') && getline(ss, interval2)) {
      int a1, b1, a2, b2;

      // Parse the two numbers in the first interval.
      stringstream ss1(interval1);
      if (getline(ss1, interval1, '-') && getline(ss1, interval2)) {
        a1 = stoi(interval1);
        b1 = stoi(interval2);
      }

      // Parse the two numbers in the second interval.
      stringstream ss2(interval2);
      if (getline(ss2, interval1, '-') && getline(ss2, interval2)) {
        a2 = stoi(interval1);
        b2 = stoi(interval2);
      }

      // Check if the intervals overlap.
      if (intervalsOverlap(a1, b1, a2, b2)) {
        ++numOverlapping;
      }
    }
  }

  // Print the result.
  cout << "Number of overlapping intervals: " << numOverlapping << endl;

  return 0;
}
