#pragma once

#include "model/Card.h"

class DepositScreen
{
  Card &card;

public:
  explicit DepositScreen(Card &card);
  void print();
};