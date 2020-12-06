#include <iostream>
#include <vector>

int main() {
  std::vector<int> myvector(10);

  try
  {
    myvector.at(20) = 100;
  }
  catch(const std::exception& e)
  {
    std::cerr << "Caught: " << e.what() << '\n';
    std::cerr << "Type: " << typeid(e).name() << '\n';
  }
}