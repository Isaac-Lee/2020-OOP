#include <iostream>

template <typename T, typename S>
class Pair {
 public:
  Pair(T fst, S snd) : fst_(fst), snd_(snd) {}
  T fst() { return fst_; }
  S snd() { return snd_; }
 private:
  T fst_;
  S snd_;
};

template <typename T, typename S, template <typename, typename> typename P, int kSize>
class PairArray {
 public:
  PairArray() {
    arr_ = (P<T, S>*)malloc(sizeof(P<T, S>) * kSize);
  }
  P<T, S>& At(int i) {
    if (i < kSize) return *(arr_ + i);
    else throw "index out of bound";
  }
  T GetFirstAt(int i) { return At(i).fst(); }
  S GetSecondAt(int i) { return At(i).snd(); }
 private:
  P<T, S>* arr_;
};

int main()
{
  PairArray<int, double, Pair, 3> arr;
  arr.At(0) = Pair(1, 3.5);
  arr.At(1) = Pair(3, 99.7);
  arr.At(2) = Pair(5, 10.1);

  std::cout << arr.GetFirstAt(0) << std::endl;
  std::cout << arr.GetFirstAt(1) << std::endl;
  std::cout << arr.GetFirstAt(2) << std::endl;

  std::cout << arr.GetSecondAt(0) << std::endl;
  std::cout << arr.GetSecondAt(1) << std::endl;
  std::cout << arr.GetSecondAt(2) << std::endl;
  return 0;
}
