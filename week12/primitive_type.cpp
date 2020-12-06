#include <iostream>

template <typename T, int kSize>
class Array {
 public:
  Array() { arr_ = (T*)malloc(sizeof(T) * kSize); }
  T& at(int i) {
    if (i < kSize) return *(arr_ + i);
    else throw "index out of bound";
  }
 private:
  T* arr_;
};

int main()
{
  Array<double, 3> arr;
  arr.at(0) = 1.3;
  arr.at(1) = 7.99;
  arr.at(2) = 99.1;

  std::cout << "index0: " << arr.at(0) << std::endl;
  std::cout << "index1: " << arr.at(1) << std::endl;
  std::cout << "index2: " << arr.at(2) << std::endl;
  return 0;
}
