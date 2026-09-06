#pragma once

#include "model/Card.h"

enum class BalanceScreenOption
{
  BACK_TO_MAIN_MENU = 1,
  EXIT = 0
};

class BalanceScreen
{
private:
  Card &card;
  void printAvailableBalance();
  void handleOption(BalanceScreenOption option);

public:
  explicit BalanceScreen(Card &card);
  void print();
};