#include <iostream>
#include "screens/WelcomeScreen.h"
#include "utils/utils.h"

int main()
{
  clearScreen();
  WelcomeScreen welcomeScreen;
  welcomeScreen.print();

  return 0;
}