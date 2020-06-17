#pragma once
#include <algorithm>
#include <array>
#include <numeric>

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

    return eyeCount * std::count(dices.begin(), dices.end(), eyeCount);
  }

  static auto onlyOnes(Dices dices) -> Score { return byEyeCount(1, dices); }
  static auto onlyTwos(Dices dices) -> Score { return byEyeCount(2, dices); }
  static auto onlyThrees(Dices dices) -> Score { return byEyeCount(3, dices); }
  static auto onlyFours(Dices dices) -> Score { return byEyeCount(4, dices); }
  static auto onlyFives(Dices dices) -> Score { return byEyeCount(5, dices); }
  static auto onlySixes(Dices dices) -> Score { return byEyeCount(6, dices); }

  static auto bestPair(Dices dices) -> Score {
    // std::sort(dices.begin(), dices.end(), [](EyeCount l, EyeCount r) { //
    //   return l > r;
    // });
    // auto it = std::adjacent_find(dices.begin(), dices.end(), [](EyeCount l, EyeCount r) { //
    //   return l == r;
    // });
    // if (it == dices.end())
    //   return 0;
    // return *it * 2;

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

  // 1,2,3,4,5
  // 2,3,4,5,6
  static auto smallStraight(Dices dices) -> Score {
    auto h = buildHistogram(dices);
    return std::count(h.begin(), h.end() - 1, 1) == 5 ? 15 : 0;
  }

  static auto chance(Dices dices) -> Score {
    return std::accumulate(dices.begin(), dices.end(), Score{}); //
  }
};
