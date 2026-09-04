#include "screens/WelcomeScreen.h"
#include "utils/utils.h"
#include <iostream>

using namespace std;

enum WelcomeOptions
{
  INSERT_CARD = 1,
  EXIT = 0
};

void WelcomeScreen::draw()
{
  cout << repeat("=", 50) << '\n';
  cout << center("Welcome", 50) << '\n';
  cout << repeat("=", 50) << "\n\n";

  cout << center("Insert your card to continue", 50) << "\n\n";

  cout << repeat("-", 50) << '\n';
  cout << repeat(" ", 11) << "[1] Insert Card\n";
  cout << repeat(" ", 11) << "[0] Exit\n";
}