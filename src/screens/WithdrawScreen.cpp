#include "screens/WithdrawScreen.h"
#include "screens/MainMenu.h"
#include "utils/utils.h"
#include "utils/reader.h"
#include "dao/CardDao.h"
#include <string>
#include <iostream>

using namespace std;

namespace
{
  string optionToString(WithdrawScreenOption option)
  {
    switch (option)
    {
    case WithdrawScreenOption::$20:
      return "$20";

    case WithdrawScreenOption::$50:
      return "$50";

    case WithdrawScreenOption::$100:
      return "$100";

    case WithdrawScreenOption::$200:
      return "$200";

    case WithdrawScreenOption::$500:
      return "$500";

    case WithdrawScreenOption::OTHER_AMOUNT:
      return "Other Amount";

    case WithdrawScreenOption::CANCEL:
      return "Cancel";
    }

    throw invalid_argument("Invalid WithdrawScreenOption");
  }

  void printOptions()
  {
    const int NUMBER_OF_OPTIONS = 7;

    WithdrawScreenOption options[] = {
        WithdrawScreenOption::$20, WithdrawScreenOption::$50,
        WithdrawScreenOption::$100, WithdrawScreenOption::$200,
        WithdrawScreenOption::$500, WithdrawScreenOption::OTHER_AMOUNT,
        WithdrawScreenOption::CANCEL};

    for (size_t i = 0; i < NUMBER_OF_OPTIONS; i++)
    {
      cout << '[' << static_cast<int>(options[i]) << ']' << optionToString(options[i]) << '\n';
    }
  }

  bool isValidOption(int option)
  {
    return option >= 0 && option <= 6;
  }

  WithdrawScreenOption readOptionUntilValidInput()
  {
    int option;
    while (true)
    {
      option = readOption();
      if (isValidOption(option))
      {
        return static_cast<WithdrawScreenOption>(option);
      }
      else
      {
        cout << "Option must be between 0 and 6. Try again!\n";
      }
    }
  }

  void confirmWithdraw(int amount)
  {
    cout << '$' << amount << " withdrawn successfully\n";
    printExitMsg();
  }
}

WithdrawScreen::WithdrawScreen(Card card) : card(card)
{
}

void WithdrawScreen::handleOption(WithdrawScreenOption option)
{
  CardDao cardDao;

  switch (option)
  {
  case WithdrawScreenOption::$20:
    cardDao.withdraw(card, 20);
    confirmWithdraw(20);
    return;

  case WithdrawScreenOption::$50:
    cardDao.withdraw(card, 50);
    confirmWithdraw(50);
    return;

  case WithdrawScreenOption::$100:
    cardDao.withdraw(card, 100);
    confirmWithdraw(100);
    return;

  case WithdrawScreenOption::$200:
    cardDao.withdraw(card, 200);
    confirmWithdraw(200);
    return;

  case WithdrawScreenOption::$500:
    cardDao.withdraw(card, 500);
    confirmWithdraw(500);
    return;

  case WithdrawScreenOption::OTHER_AMOUNT:
  {
    double amount = readDouble("Enter amount: ");
    cardDao.withdraw(card, amount);
    confirmWithdraw(amount);
    return;
  }

  case WithdrawScreenOption::CANCEL:
    clearScreen();
    MainMenu(card).print();
    return;
  }

  throw std::invalid_argument("Invalid WithdrawScreenOption");
}

void WithdrawScreen::print()
{
  printScreenHeader("Withdraw");
  printOptions();
  printBreakLine();
  WithdrawScreenOption option = readOptionUntilValidInput();
  handleOption(option);
}