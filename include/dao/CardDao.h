#pragma once

#include "model/Card.h"
#include <filesystem>
#include <string>
#include <optional>

class CardDao
{
private:
  std::filesystem::path cardsDataPath = "data/cards.txt";
  char fileDelimiter = '|';
  Card extractCardFromLine(const std::string &line);
  std::string extractCardNumberFromLine(const std::string &line);
  void updateBalance(const Card &card, double newBalance);

public:
  std::optional<Card> getCardByNumber(const std::string &cardNumber);
  void withdraw(const Card &card, double amount);
};