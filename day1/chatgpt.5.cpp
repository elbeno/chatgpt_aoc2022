// I have an unsorted vector of ints. Write a C++ program to tell me the sum of
// the largest 3. Do not use the sort function.

#include <iostream>
#include <vector>

using namespace std;

int main() {
  // Declare a vector of ints and initialize it with some values
  vector<int> numbers = {10, 5, 20, 15, 30, 25};

  // Declare three variables to hold the largest three integers
  int largest1 = 0, largest2 = 0, largest3 = 0;

  // Loop through the vector and find the largest three integers
  for (int i = 0; i < numbers.size(); i++) {
    if (numbers[i] > largest1) {
      largest3 = largest2;
      largest2 = largest1;
      largest1 = numbers[i];
    } else if (numbers[i] > largest2) {
      largest3 = largest2;
      largest2 = numbers[i];
    } else if (numbers[i] > largest3) {
      largest3 = numbers[i];
    }
  }

  // Compute the sum of the largest three integers
  int sum = largest1 + largest2 + largest3;

  // Print the result
  cout << "The sum of the largest three integers is: " << sum << endl;

  return 0;
}
