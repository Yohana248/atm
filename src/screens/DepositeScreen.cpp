#include "screens/DepositeScreen.h"
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
    cout << "Are you sure that you want to deposite $" << amount << ": ";
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

DepositeScreen::DepositeScreen(Card &card) : card(card)
{
}

void DepositeScreen::print()
{
  printScreenHeader("Deposit");
  double amount = readConfirmedAmount();
  CardDao().deposite(card, amount);
  confirmSuccessfulDeposit(card, amount);
  printExitMsg();
}