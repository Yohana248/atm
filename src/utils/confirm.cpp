#include "utils/confirm.h"

Confirm handleConfirm(char answer)
{
  if (answer == 'y' || answer == 'Y')
  {
    return Confirm::YES;
  }
  else
  {
    return Confirm::NO;
  }
}