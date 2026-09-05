#include "screens/EnterCardInfoScreen.h"
#include "utils/utils.h"
#include "utils/stringUtils.h"
#include "model/Card.h"
#include "dao/CardDao.h"
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

string EnterCardInfoScreen::readCardNumberUntilValidInputWithMaxTries(int maxTries)
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

string EnterCardInfoScreen::readPinUntilValidInputWithMaxTries(int maxTries)
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

  string cardNumber = readCardNumberUntilValidInputWithMaxTries(3);
  if (cardNumber.empty())
  {
    printFinishingAvailTriesMsg();
    return;
  }
  cout << '\n';

  CardDao cardDao;
  optional<Card> card = cardDao.getCardByNumber(cardNumber);
  if (!card.has_value())
  {
    cout << "Card not found\n";
    printExitMsg();
    return;
  }

  string pin = readPinUntilValidInputWithMaxTries(3);
  if (pin.empty())
  {
    printFinishingAvailTriesMsg();
    return;
  }
  cout << '\n';

  if (card.value().pin != pin)
  {
    cout << "PIN is wrong. Exit and try again!\n";
    printExitMsg();
    return;
  }

  cout << "You are welcome!\n";
  printBreakLine();
}
