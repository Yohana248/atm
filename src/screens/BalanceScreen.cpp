#include "screens/BalanceScreen.h"
#include "screens/MainMenu.h"
#include "utils/utils.h"
#include <iostream>
#include <iomanip>

using namespace std;

namespace
{
  string optionToString(BalanceScreenOption option)
  {
    switch (option)
    {
    case BalanceScreenOption::BACK_TO_MAIN_MENU:
      return "Back to Main Menu";

    case BalanceScreenOption::EXIT:
      return "Exit";
    }

    throw std::invalid_argument("Invalid BalanceSreenOption");
  }

  void printBalanceScreenOptions()
  {
    const int NUMBER_OF_OPTIONS = 2;
    BalanceScreenOption options[] = {BalanceScreenOption::BACK_TO_MAIN_MENU, BalanceScreenOption::EXIT};

    for (size_t i = 0; i < NUMBER_OF_OPTIONS; i++)
    {
      cout << '[' << static_cast<int>(options[i]) << ']' << optionToString(options[i]) << '\n';
    }
  }

  int readOption()
  {
    int option;

    cout << "Select an option: ";
    cin >> option;

    return (option);
  }

  bool isValidOption(int option)
  {
    return option >= 0 && option <= 2;
  }

  BalanceScreenOption readOptionUntilValidInput()
  {
    int option;
    while (true)
    {
      option = readOption();
      if (isValidOption(option))
      {
        return static_cast<BalanceScreenOption>(option);
      }

      cout << "Option must be between 0 or 1. Try again!\n";
    }
  }

  void printMoneyCenter(double amount)
  {
    ostringstream oss;
    oss << "$" << fixed << setprecision(2) << amount;

    cout << center(oss.str()) << '\n';
  }
}

BalanceScreen::BalanceScreen(Card &card) : card(card)
{
}

void BalanceScreen::handleOption(BalanceScreenOption option)
{
  switch (option)
  {
  case BalanceScreenOption::BACK_TO_MAIN_MENU:
    clearScreen();
    MainMenu(card).print();
    return;

  case BalanceScreenOption::EXIT:
    printExitMsg();
    return;
  }

  throw std::invalid_argument("Invalid BalanceScreenOption");
}

void BalanceScreen::printAvailableBalance()
{
  cout << "Available Balance:\n";
  printMoneyCenter(card.balance);
}

void BalanceScreen::print()
{
  printScreenHeader("Balance");
  printAvailableBalance();
  printBreakLine();
  printBalanceScreenOptions();
  BalanceScreenOption option = readOptionUntilValidInput();
  handleOption(option);
}
