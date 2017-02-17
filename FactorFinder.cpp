#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

bool isFactor(int number);
vector<int> findFactors(int number);
int main() {
  // declare and initinalize variables
  int number = 0;
  string input = "";
  vector<int> vector;
  // infinite loop
  while (true) {
    // get user input
    cout << "Please enter a number" << endl;
    getline(cin, input);
    // safely convert it to a number using a stringstream
    stringstream myStream(input);
    // if it works break the loop
    if (myStream >> number) {
      break;
    }
    // else ask again
    cout << "Invalide number,please enter a valid number" << endl;
  }
  // initinalize the vector with the factors of the number
  vector = findFactors(number);
  // if the only factor is 1 the the number is a prime number
  if (vector.size() <= 1) {
    cout << "The number  " << number << " is a prime number." << endl
         << "As such, it doesn't have any factors other than 1 and itself."
         << endl;
  }
  // else print out the factors
  else {
    cout << "The number " << number << " has " << vector.size()
         << " Factors: " << endl;
    for (int i = 0; i < vector.size(); i++) {
      if (i < vector.size() - 1)
        cout << vector[i] << ", ";
      else
        cout << "and " << vector[i] << ". " << endl;
    }
  }

  return 0;
}
// checks to see if the remainder of the division is 0
bool isFactor(int number) {
  if (number == 0) {
    return true;
  } else {
    return false;
  }
}
vector<int> findFactors(int number) {
  // vector of factors
  vector<int> v;
  // first factor is always 1
  int potentialFactor = 1;
  do {
    // find the remainder of the division between the number and the numbers
    // that preceedes it.
    int result = number % potentialFactor;
    // if the remainder is 0 add it to the vector
    if (isFactor(result) == true) {
      v.push_back(potentialFactor);
    }
    // go to the next number
    potentialFactor++;
    // do this for all preceeding numbers
  } while (potentialFactor < number);
  // return vector
  return v;
}
