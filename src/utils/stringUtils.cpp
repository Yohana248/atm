#include "utils/stringUtils.h"
#include <iostream>
#include <vector>

using namespace std;

bool isDigit(char c)
{
  return c >= '0' && c <= '9';
}

bool areAllCharsDigits(const std::string &s)
{
  for (size_t i = 0; i < s.length(); i++)
  {
    if (!isDigit(s.at(i)))
    {
      return false;
    }
  }

  return true;
}

vector<string> split(const string &s, char delimiter)
{
  vector<string> result;

  string buffer;

  for (size_t i = 0; i < s.size(); i++)
  {
    if (s[i] == delimiter)
    {
      result.push_back(buffer);
      buffer.clear();
      continue;
    }

    buffer += s[i];
  }

  result.push_back(buffer);

  return result;
}
