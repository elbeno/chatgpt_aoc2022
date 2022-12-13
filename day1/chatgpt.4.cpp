// I have an unsorted vector of ints. Write a C++ program to tell me the sum of
// the largest 3.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  // Declare a vector of ints and initialize it with some values
  vector<int> numbers = {10, 5, 20, 15, 30, 25};

  // Sort the vector in descending order
  sort(numbers.rbegin(), numbers.rend());

  // Take the first three elements of the sorted vector and compute their sum
  int sum = numbers[0] + numbers[1] + numbers[2];

  // Print the result
  cout << "The sum of the largest three integers is: " << sum << endl;

  return 0;
}
