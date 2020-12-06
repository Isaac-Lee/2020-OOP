#include <iostream>
#include <array>

void Print(const std::array<int, 3>& arr) {
  for (int i = 0; i < arr.size(); ++i) {
    std::cout << " " << arr[i];
  }
  std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
  std::array<int, 3> arr;

  arr[0] = 1;
  arr[1] = 2;
  arr.at(2) = 3;

  Print(arr);

  arr[1] = 4;

  Print(arr);
  return 0;
}
