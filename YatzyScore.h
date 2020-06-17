#pragma once
#include <algorithm>
#include <array>

using Score = int;
using EyeCount = int;
using Dices = std::array<EyeCount, 5>;
using Count = int;

using Histogram = std::array<Count, 6>;

auto buildHistogram(Dices dices) -> Histogram {
  auto h = Histogram{};
  for (auto eyeCount : dices) {
    h[eyeCount - 1] += 1;
  }
  return h;
}

struct YatzyScore {
  static auto byEyeCount(EyeCount eyeCount, Dices dices) -> Score {
    // auto score = Score{};
    // for (auto diceEyeCount : dices) {
    //   if (diceEyeCount == eyeCount)
    //     score += eyeCount;
    // }
    // return score;

    return eyeCount * std::count(begin(dices), end(dices), eyeCount);
  }

  static auto onlyOnes(Dices dices) -> Score { return byEyeCount(1, dices); }
  static auto onlyTwos(Dices dices) -> Score { return byEyeCount(2, dices); }
  static auto onlyThrees(Dices dices) -> Score { return byEyeCount(3, dices); }
  static auto onlyFours(Dices dices) -> Score { return byEyeCount(4, dices); }
  static auto onlyFives(Dices dices) -> Score { return byEyeCount(5, dices); }
  static auto onlySixes(Dices dices) -> Score { return byEyeCount(6, dices); }

  static auto bestPair(Dices dices) -> Score {
    auto h = buildHistogram(dices);
    for (auto i = 0; i < h.size(); i++) {
      if (h[h.size() - i - 1] >= 2) {
        return (h.size() - i) * 2;
      }
    }
    return Score{};

    //     0 1 2 3 4 5
    //     ^begin      ^end
    //   ^rend       ^rbegin
    // auto it = std::find_if(h.rbegin(), h.rend(), [](Count count) {
    //   return count >= 2; //
    // });
    // return (h.rend() - it) * 2;
  }
};
