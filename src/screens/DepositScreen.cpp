#include "screens/DepositScreen.h"
#include "utils/utils.h"
#include "dao/CardDao.h"
#include <iostream>

using namespace std;

namespace
{
  double readAmount()
  {
    double amount;
    cout << "Enter amouont: ";
    cin >> amount;
    return amount;
  }

  char confirmDeposit(double amount)
  {
    char answer;
    cout << "Are you sure that you want to deposit $" << amount << ": ";
    cin >> answer;
    return answer;
  }

  double readConfirmedAmount()
  {
    double amount;
    char answer;
    do
    {
      amount = readAmount();
      answer = confirmDeposit(amount);
    } while (answer != 'y' && answer != 'Y');
    return amount;
  }

  void confirmSuccessfulDeposit(const Card &card, double amount)
  {
    cout << "You deposited $" << amount << " Successfully\n";
  }
}

DepositScreen::DepositScreen(Card &card) : card(card)
{
}

void DepositScreen::print()
{
  printScreenHeader("Deposit");
  double amount = readConfirmedAmount();
  CardDao().deposit(card, amount);
  confirmSuccessfulDeposit(card, amount);
  printExitMsg();
}