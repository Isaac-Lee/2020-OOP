#include <iostream>

template <typename T, typename N>
class Pair {
 public:
  Pair(T fst, N snd) : fst_(fst), snd_(snd) {}
  T fst() { return fst_; }
  N snd() { return snd_; }
 private:
  const T fst_;
  const N snd_;
};

int main()
{
  Pair<int, double> ip(1, 3.9);
  Pair<double, bool> dp(1.4, true);

  std::cout << ip.fst() << ", " << ip.snd() << std::endl;
  std::cout << dp.fst() << ", " << dp.snd() << std::endl;
  return 0;
}
