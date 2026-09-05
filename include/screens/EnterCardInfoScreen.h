#pragma once

#include <string>
#include "model/Card.h"

using namespace std;

class EnterCardInfoScreen
{
private:
  string readCardNumber();
  bool isValidCardNumber(const string &cardNunmber);
  char readTryAgainOrExit();
  string readCardNumberUntilValidInput();
  string readPin();
  bool isValidPin(const string &pin);
  string readPinUntilValidInput();
  void printFinishingAvailTriesMsg();
  void handlePinInput(const Card &card);

public:
  void print();
};