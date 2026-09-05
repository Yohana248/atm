#include "screens/WelcomeScreen.h"
#include "screens/EnterCardInfoScreen.h"
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
    printExitMsg();
    return;
  }

  if (option == WelcomeOption::INSERT_CARD)
  {
    clearScreen();
    EnterCardInfoScreen enterCardInfoScreen;
    enterCardInfoScreen.print();
  }
}

void WelcomeScreen::print()
{
  printScreenHeader("Welcome");
  printCenter("Insert your card to continue");
  printBreakLine();

  cout << repeat(" ", 11) << "[1] Insert Card\n";
  cout << repeat(" ", 11) << "[0] Exit\n\n";

  WelcomeOption option = readOption();
  handleOption(option);
}