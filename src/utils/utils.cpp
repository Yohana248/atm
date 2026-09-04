#include "utils/utils.h"

using namespace std;

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

string center(const std::string &text, int width)
{
  if (static_cast<int>(text.length()) >= width)
  {
    return text;
  }

  int padding = width - text.length();
  int leftPadding = padding / 2;

  return repeat(" ", leftPadding) + text;
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
