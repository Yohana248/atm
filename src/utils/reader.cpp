#include <iostream>

using namespace std;

int readOption()
{
  int option;

  cout << "Select an option: ";
  cin >> option;

  return option;
}

double readDouble(const char *msg)
{
  double n;
  cout << msg;
  cin >> n;
  return n;
}