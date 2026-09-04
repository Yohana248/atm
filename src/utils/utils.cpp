#include "utils/utils.h"
#include <iostream>

using namespace std;

const int WIDTH = 100;

string repeat(const std::string &s, int n)
{
  string result;
  result.reserve(s.size() * n);

  for (size_t i = 0; i < n; i++)
  {
    result += s;
  }

  return result;
}

string center(const std::string &text)
{
  if (static_cast<int>(text.length()) >= WIDTH)
  {
    return text;
  }

  int padding = WIDTH - text.length();
  int leftPadding = padding / 2;

  return repeat(" ", leftPadding) + text;
}

void printDoubleBreakLine()
{
  cout << repeat("=", WIDTH) << '\n';
}

void printCenter(const std::string &s)
{
  cout << center(s) << '\n';
}

void printScreenHeader(const std::string &title)
{
  printDoubleBreakLine();
  printCenter(title);
  printDoubleBreakLine();
  cout << '\n';
}

void printBreakLine()
{
  cout << repeat("-", WIDTH) << '\n';
}

void clearScreen()
{
#ifdef _WIN32
  {
    system("cls");
  }
#else
  {
    system("clear");
  }
#endif
}
