#include "screens/WelcomeScreen.h"
#include "screens/EnterPinScreen.h"
#include "utils/utils.h"
#include <iostream>

using namespace std;

WelcomeOption WelcomeScreen::readOption()
{
  int option;

  cout << "Select an option: ";
  cin >> option;

  return static_cast<WelcomeOption>(option);
}

void WelcomeScreen::handleOption(WelcomeOption option)
{
  if (option == WelcomeOption::EXIT)
  {
    cout << "Thanks for using our ATM\n";
    return;
  }

  if (option == WelcomeOption::INSERT_CARD)
  {
    cout << '\n';
    EnterPinScreen enterPinScreen;
    enterPinScreen.draw();
  }
}

void WelcomeScreen::draw()
{
  cout << repeat("=", 50) << '\n';
  cout << center("Welcome", 50) << '\n';
  cout << repeat("=", 50) << "\n\n";

  cout << center("Insert your card to continue", 50) << "\n\n";

  cout << repeat("-", 50) << '\n';
  cout << repeat(" ", 11) << "[1] Insert Card\n";
  cout << repeat(" ", 11) << "[0] Exit\n\n";

  WelcomeOption option = readOption();
  handleOption(option);
}