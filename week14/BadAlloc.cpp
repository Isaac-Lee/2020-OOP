#include <iostream>
#include <new>

int main() {
  try
  {
    while (true) {
      new int [100000000000ul];
    }
  }
  catch(const std::bad_alloc& e)
  {
    std::cerr << "Allocation falid: " << e.what() << '\n';
  }
}