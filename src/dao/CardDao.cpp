#include "dao/CardDao.h"
#include "utils/stringUtils.h"
#include <iostream>
#include <fstream>

using namespace std;

optional<Card> CardDao::getCardByNumber(const std::string &cardNumber)
{
  ifstream cardDataFile(cardsDataPath);

  if (!cardDataFile.is_open())
  {
    throw std::runtime_error("Could not open cards data file");
  }

  string line;
  getline(cardDataFile, line);

  while (getline(cardDataFile, line))
  {
    if (line.empty())
      continue;

    if (extractCardNumberFromLine(line) == cardNumber)
    {
      return extractCardFromLine(line);
    }
  }

  return nullopt;
}

string CardDao::extractCardNumberFromLine(const string &line)
{
  string cardNumber = "";
  bool start = false;

  for (size_t i = 1; i < line.size(); i++)
  {
    if (!start && line[i - 1] == fileDelimiter)
    {
      start = true;
    }

    if (start && cardNumber.size() < 16)
    {
      cardNumber += line[i];
    }

    if (start && cardNumber.size() == 16)
    {
      break;
    }
  }

  return cardNumber;
}

Card CardDao::extractCardFromLine(const string &line)
{
  Card card;
  vector<string> fields = split(line, fileDelimiter);
  card.id = stoi(fields[0]);
  card.number = fields[1];
  card.pin = fields[2];
  card.balance = stod(fields[3]);

  return card;
}
