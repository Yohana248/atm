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

void EnterPinScreen::draw()
{
  cout << repeat("=", 50) << '\n';
  cout << center("Enter PIN", 50) << '\n';
  cout << repeat("=", 50) << "\n\n";

  string pin = readPin();
  cout << '\n'
       << pin << '\n';
  cout << repeat("-", 50) << '\n';
}