#include "utils/stringUtils.h"
#include <iostream>

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
