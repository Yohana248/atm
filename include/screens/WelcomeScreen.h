#pragma once

enum class WelcomeOption
{
  INSERT_CARD = 1,
  EXIT = 0
};

class WelcomeScreen
{
private:
  WelcomeOption readOption();
  void handleOption(WelcomeOption option);

public:
  void draw();
};