#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;
void getResult(int playerchoice);
string choiceparser(int number);

int main() {

  srand(time(0));
  while (true) {
    /* code */

    // declare and initinalize variables
    int number = 0;
    string input = "";
    // infinite loop
    while (true) {
      // get user input
      cout << "Please enter 1 for Rock" << endl
           << "2 for Papper" << endl
           << "3 for scissors" << endl;
      getline(cin, input);
      // safely convert it to a number using a stringstream
      stringstream myStream(input);
      // if it works break the loop
      if (myStream >> number) {
        if (number > 0 && number < 4)
          break;
      }
      // else ask again
      cout << "Invalid option,please enter a valid number" << endl;
    }
    getResult(number);
  }
}

string choiceparser(int number) {
  switch (number) {
  case 1:
    return "rock";
  case 2:
    return "papper";
  case 3:
    return "sscissors";
  }
}

void getResult(int playerchoice) {
  // scores
  int cmp = 0;
  int player = 0;
  int computersChoice = rand() % 4 + 0;
  cout << "you chose:" << choiceparser(playerchoice) << endl
       << "the computer chose:" << choiceparser(computersChoice) << endl;
  int rock = 1;
  int papper = 2;
  int scissors = 3;

  if (playerchoice == rock && computersChoice == papper) {
    cout << "you loss" << endl;
    cmp++;
  }

  else if (playerchoice == rock && computersChoice == scissors) {
    cout << "you won" << endl;
    player++;
  }

  else if (playerchoice == papper && computersChoice == rock) {
    cout << "you won" << endl;
  }

  else if (playerchoice == papper && computersChoice == scissors) {
    cout << "you loss" << endl;
    cmp++;

  }

  else if (playerchoice == scissors && computersChoice == papper) {
    cout << "you won" << endl;
    player++;
  }

  else if (playerchoice == scissors && computersChoice == rock) {
    cout << "you loss" << endl;
    cmp++;

  }

  else {
    cout << "draw" << endl;
    cmp++;
    player++;
  }

  cout << "computer: " << cmp << " player: " << player << endl << endl;
}
