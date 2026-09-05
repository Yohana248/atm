#pragma once

#include <string>

using namespace std;

class EnterCardInfoScreen
{
private:
  string readCardNumber();
  bool isValidCardNumber(const string &cardNunmber);
  string readCardNumberUnti(int maxTries);
  int calcAvailabePinTries(int tries, int max);
  string readPin();
  bool isValidPin(const string &pin);
  string readPinUntil(int maxTries);
  void printFinishingAvailTriesMsg();

public:
  void print();
};