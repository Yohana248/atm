#include "screens/EnterCardInfoScreen.h"
#include "utils/utils.h"
#include "utils/stringUtils.h"
#include "model/Card.h"
#include "dao/CardDao.h"
#include "utils/confirm.h"
#include "screens/MainMenu.h"
#include <iostream>
#include <string>

using namespace std;

string EnterCardInfoScreen::readCardNumber()
{
  return readWord("Enter Card Number (16 digits): ");
}

bool EnterCardInfoScreen::isValidCardNumber(const string &cardNunmber)
{
  return cardNunmber.length() == 16 && areAllCharsDigits(cardNunmber);
}

char EnterCardInfoScreen::readTryAgainOrExit()
{
  char answer;
  cout << "Enter (y) to try again or another letter to exit: ";
  cin >> answer;
  return answer;
}

string EnterCardInfoScreen::readCardNumberUntilValidInput()
{
  string cardNumber;
  Confirm confirm = Confirm::YES;

  do
  {
    cardNumber = readCardNumber();

    if (!isValidCardNumber(cardNumber))
    {
      cout << "Card Number must be 16 digits. ";
      char answer = readTryAgainOrExit();
      confirm = handleConfirm(answer);
      cout << '\n';
    }
    else
    {
      break;
    }

  } while (confirm == Confirm::YES);

  return confirm == Confirm::NO ? "" : cardNumber;
}

string EnterCardInfoScreen::readPin()
{
  return readWord("PIN (4 digits): ");
}

bool EnterCardInfoScreen::isValidPin(const string &pin)
{
  return pin.length() == 4 && areAllCharsDigits(pin);
}

string EnterCardInfoScreen::readPinUntilValidInput()
{
  string pin;
  Confirm confirm = Confirm::YES;

  do
  {
    pin = readPin();

    if (!isValidPin(pin))
    {
      cout << "PIN must be 4 digits. ";
      char answer = readTryAgainOrExit();
      confirm = handleConfirm(answer);
      cout << '\n';
    }
    else
    {
      break;
    }

  } while (confirm == Confirm::YES);

  return confirm == Confirm::NO ? "" : pin;
}

void EnterCardInfoScreen::printFinishingAvailTriesMsg()
{
  cout << "You finished all available tries!\n";
  printExitMsg();
  printBreakLine();
}

void EnterCardInfoScreen::handlePinInput(Card &card)
{
  int remainingAttempts = 3;
  Confirm confirm = Confirm::YES;
  do
  {
    string pin = readPinUntilValidInput();
    if (pin.empty())
    {
      printExitMsg();
      return;
    }

    if (card.pin != pin)
    {
      remainingAttempts--;
      cout << "PIN is wrong. ";
      if (remainingAttempts == 0)
      {
        cout << "\nYou consumed all attempts\n";
        printExitMsg();
        return;
      }
      cout << "You have " << remainingAttempts << " remaining attempts.\n";
      char answer = readTryAgainOrExit();
      confirm = handleConfirm(answer);
      cout << '\n';
    }
    else
    {
      break;
    }
  } while (confirm == Confirm::YES);

  cout << '\n';
  if (confirm == Confirm::NO)
  {
    printExitMsg();
  }
  else
  {
    clearScreen();
    MainMenu(card).print();
  }
}

void EnterCardInfoScreen::print()
{
  printScreenHeader("Enter Card Info");

  string cardNumber = readCardNumberUntilValidInput();
  if (cardNumber.empty())
  {
    printExitMsg();
    return;
  }
  cout << '\n';

  CardDao cardDao;
  optional<Card> card = cardDao.getCardByNumber(cardNumber);
  if (!card)
  {
    cout << "Card not found\n";
    printExitMsg();
    printBreakLine();
    return;
  }

  handlePinInput(card.value());
}
