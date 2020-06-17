#pragma once
#include <algorithm>
#include <array>

using Score = int;
using EyeCount = int;
using Dices = std::array<EyeCount, 5>;

struct YatzyScore {
  static auto singles(EyeCount eyeCount, Dices dices) -> Score {
    // auto score = Score{};
    // for (auto diceEyeCount : dices) {
    //   if (diceEyeCount == eyeCount)
    //     score += eyeCount;
    // }
    // return score;

    return eyeCount * std::count(begin(dices), end(dices), eyeCount);
  }

  static auto ones(Dices dices) -> Score { return singles(1, dices); }
  static auto twos(Dices dices) -> Score { return singles(2, dices); }
  static auto threes(Dices dices) -> Score { return singles(3, dices); }
  static auto fours(Dices dices) -> Score { return singles(4, dices); }
  static auto fives(Dices dices) -> Score { return singles(5, dices); }
  static auto sixes(Dices dices) -> Score { return singles(6, dices); }
};
