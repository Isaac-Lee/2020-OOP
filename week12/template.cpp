#include <iostream>

template <typename T>
class Pair {
 public:
  Pair(T fst, T snd) : fst_(fst), snd_(snd) {}
  T fst() { return fst_; }
  T snd() { return snd_; }
 private:
  const T fst_;
  const T snd_;
};

int main()
{
  Pair<int> ip(1, 3);
  Pair<double> dp(1.4, 9.7);

  std::cout << ip.fst() << ", " << ip.snd() << std::endl;
  std::cout << dp.fst() << ", " << dp.snd() << std::endl;
  return 0;
}
