#include <iostream>

int main(int argc, char const *argv[])
{
  int a = atoi(argv[1]);
  int b = atoi(argv[2]);
  try {
    if (a<=0) {
      if (b<=0) {
        throw "Wrong inputs!";
      } else {
        throw 'a';
      }
    }
    if (b<=0) {
      throw b;
    }
  } catch (int i) {
    std::cout << "Error occured ! " << std::endl;
    std::cout << "b must be greater than 0, b : " << i << std::endl;
  } catch (char s) {
    std::cout << "Error occured ! " << std::endl;
    std::cout << "a must be greater than 0, b : " << s << std::endl;
  } catch (...) {
    std::cout << "Default Catch ! " << std::endl;
  }
  return 0;
}
