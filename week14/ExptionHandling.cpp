#include <iostream>

int main(int argc, char const *argv[])
{
  int a = atoi(argv[1]);
  int b = atoi(argv[2]);
  try {
    if (b<=0)
      throw b;
    std::cout << "Executed successfully!" << std::endl;
    std::cout << "a : " << a << ", b : " << b << std::endl;
  } catch (int expn) {
    std::cout << "Error occured ! " << std::endl;
    std::cout << "b must be greater than 0, b : " << expn << std::endl;
  }
  return 0;
}
