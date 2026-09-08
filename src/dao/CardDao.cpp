#include "dao/CardDao.h"
#include "utils/stringUtils.h"
#include <iostream>
#include <fstream>
#include <sstream>

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

void CardDao::updateBalance(const Card &card, double newBalance)
{
  ifstream cardsDataFile(cardsDataPath);

  filesystem::path tempFilePath = "data/temp.txt";
  ofstream tempFile(tempFilePath);

  if (!cardsDataFile.is_open())
  {
    throw runtime_error("Cannot open cards.txt file");
  }

  if (!tempFile.is_open())
  {
    throw runtime_error("Cannot create temp.txt file");
  }

  string line;
  bool found = false;

  getline(cardsDataFile, line);
  tempFile << line << '\n';

  while (getline(cardsDataFile, line))
  {
    stringstream ss(line);
    string cardIdStr;
    getline(ss, cardIdStr, '|');
    int cardId = stoi(cardIdStr);

    if (cardId == card.id)
    {
      found = true;
      tempFile << card.id << '|' << card.number << '|' << card.pin << '|' << newBalance << '\n';
    }
    else
    {
      tempFile << line << '\n';
    }
  }

  cardsDataFile.close();
  tempFile.close();

  if (found)
  {
    remove(cardsDataPath);
    rename(tempFilePath, cardsDataPath);
  }
  else
  {
    remove(tempFilePath);
    throw runtime_error("Card not found");
  }
}

void CardDao::withdraw(const Card &card, double amount)
{
  double newBalance = card.balance - amount;
  updateBalance(card, newBalance);
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
