#include "screens/MainMenu.h"
#include "screens/BalanceScreen.h"
#include "screens/WithdrawScreen.h"
#include "screens/DepositeScreen.h"
#include "utils/utils.h"
#include <string>
#include <iostream>

using namespace std;

namespace
{
  string optionToString(MainMenuOption option)
  {
    switch (option)
    {
    case MainMenuOption::CHECK_BALANCE:
      return "Check Balance";

    case MainMenuOption::WITHDRAW:
      return "Withdraw";

    case MainMenuOption::DEPOSIT:
      return "Deposit";

    case MainMenuOption::TRANSFER:
      return "Transfer";

    case MainMenuOption::TRANSACTION_HISTORY:
      return "Transaction History";

    case MainMenuOption::CHANGE_PIN:
      return "Change PIN";

    case MainMenuOption::EXIT:
      return "Exit";
    }

    throw std::invalid_argument("Invalid MainMenuOption");
  }

  void printMainMenuOptions()
  {
    const int NUMBER_OF_OPTIONS = 7;
    MainMenuOption options[] =
        {
            MainMenuOption::CHECK_BALANCE, MainMenuOption::WITHDRAW,
            MainMenuOption::DEPOSIT, MainMenuOption::TRANSFER,
            MainMenuOption::TRANSACTION_HISTORY, MainMenuOption::CHANGE_PIN,
            MainMenuOption::EXIT};

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
    return option >= 0 && option <= 6;
  }

  MainMenuOption readOptionUntilValidInput()
  {
    int option;
    while (true)
    {
      option = readOption();
      if (isValidOption(option))
      {
        return static_cast<MainMenuOption>(option);
      }

      cout << "Option must be between 1 and 6. Try again!\n";
    }
  }
}

MainMenu::MainMenu(Card &card) : card(card)
{
}

void MainMenu::handleOption(MainMenuOption option)
{
  switch (option)
  {
  case MainMenuOption::CHECK_BALANCE:
    clearScreen();
    BalanceScreen(card).print();
    return;

  case MainMenuOption::WITHDRAW:
    clearScreen();
    WithdrawScreen(card).print();
    return;

  case MainMenuOption::DEPOSIT:
    clearScreen();
    DepositeScreen(card).print();
    return;

  case MainMenuOption::TRANSFER:
    cout << "Transfer\n";
    return;

  case MainMenuOption::TRANSACTION_HISTORY:
    cout << "Transaction History\n";
    return;

  case MainMenuOption::CHANGE_PIN:
    cout << "Change PIN\n";
    return;

  case MainMenuOption::EXIT:
    printExitMsg();
    return;
  }

  throw std::invalid_argument("Invalid MainMenuOption");
}

void MainMenu::print()
{
  printScreenHeader("Main Menu");
  printMainMenuOptions();
  printBreakLine();
  MainMenuOption option = readOptionUntilValidInput();
  handleOption(option);
}
