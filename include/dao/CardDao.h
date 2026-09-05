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

public:
  std::optional<Card> getCardByNumber(const std::string &cardNumber);
};