#pragma once

#include <string>

using namespace std;

class EnterCardInfoScreen
{
private:
  string readCardNumber();
  bool isValidCardNumber(const string &cardNunmber);
  string readCardNumberUntilValidInputWithMaxTries(int maxTries);
  int calcAvailabePinTries(int tries, int max);
  string readPin();
  bool isValidPin(const string &pin);
  string readPinUntilValidInputWithMaxTries(int maxTries);
  void printFinishingAvailTriesMsg();

public:
  void print();
};