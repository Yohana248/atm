#include "screens/EnterPinScreen.h"
#include "utils/utils.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

string EnterPinScreen::readPin()
{
  string pin;

  cout << "PIN: ";
  cin >> setw(5) >> pin;

  return pin;
}

void EnterPinScreen::print()
{
  printScreenHeader("Enter PIN");

  string pin = readPin();
  cout << '\n'
       << pin << '\n';
  printBreakLine();
}