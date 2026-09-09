#pragma once

#include "model/Card.h"

class DepositeScreen
{
  Card &card;

public:
  explicit DepositeScreen(Card &card);
  void print();
};