#pragma once

#include "model/Card.h"

enum class MainMenuOption
{
  CHECK_BALANCE = 1,
  WITHDRAW = 2,
  DEPOSIT = 3,
  TRANSFER = 4,
  TRANSACTION_HISTORY = 5,
  CHANGE_PIN = 6,
  EXIT = 0
};

class MainMenu
{
private:
  Card &card;
  void handleOption(MainMenuOption option);

public:
  explicit MainMenu(Card &card);
  void print();
};