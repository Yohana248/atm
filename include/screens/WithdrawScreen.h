#pragma once

#include "model/Card.h"

enum class WithdrawScreenOption
{
  $20 = 1,
  $50 = 2,
  $100 = 3,
  $200 = 4,
  $500 = 5,
  OTHER_AMOUNT = 6,
  CANCEL = 0
};

class WithdrawScreen
{
private:
  Card card;

public:
  explicit WithdrawScreen(Card card);
  void handleOption(WithdrawScreenOption option);
  void print();
};