#include "screens/EnterCardInfoScreen.h"
#include "utils/utils.h"
#include "utils/stringUtils.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

string EnterCardInfoScreen::readCardNumber()
{
  return readWord("Enter Card Number (16 digits): ");
}

bool EnterCardInfoScreen::isValidCardNumber(const string &cardNunmber)
{
  return cardNunmber.length() == 16 && areAllCharsDigits(cardNunmber);
}

string EnterCardInfoScreen::readCardNumberUnti(int maxTries)
{
  string cardNumber = readCardNumber();

  int tries = 1;
  while (!isValidCardNumber(cardNumber) && tries < maxTries)
  {
    cout << "Card Number must be 16 digits. Please try again ( "
         << "you have "
         << calcAvailabePinTries(maxTries, tries)
         << " trie(s) )"
         << '\n';
    cout << '\n';
    cardNumber = readCardNumber();
    tries++;
  }

  return isValidCardNumber(cardNumber) ? cardNumber : "";
}

int EnterCardInfoScreen::calcAvailabePinTries(int max, int tries)
{
  return max - tries;
}

string EnterCardInfoScreen::readPin()
{
  return readWord("PIN (4 digits): ");
}

bool EnterCardInfoScreen::isValidPin(const string &pin)
{
  return pin.length() == 4 && areAllCharsDigits(pin);
}

string EnterCardInfoScreen::readPinUntil(int maxTries)
{
  string pin = readPin();

  int tries = 1;
  while (!isValidPin(pin) && tries < maxTries)
  {
    cout << "PIN must be 4 digits. Please try again ( "
         << "you have "
         << calcAvailabePinTries(maxTries, tries)
         << " trie(s) )"
         << '\n';
    cout << '\n';
    pin = readPin();
    tries++;
  }

  return isValidPin(pin) ? pin : "";
}

void EnterCardInfoScreen::printFinishingAvailTriesMsg()
{
  cout << "You finished all available tries!\n";
  printExitMsg();
  printBreakLine();
}

void EnterCardInfoScreen::print()
{
  printScreenHeader("Enter Card Info");

  string cardNumber = readCardNumberUnti(3);
  if (cardNumber.empty())
  {
    printFinishingAvailTriesMsg();
    return;
  }
  cout << '\n';

  string pin = readPinUntil(3);
  if (pin.empty())
  {
    printFinishingAvailTriesMsg();
    return;
  }
  cout << '\n';

  cout << "Card Number and PIN are valid inputs\n";
  printBreakLine();
}
