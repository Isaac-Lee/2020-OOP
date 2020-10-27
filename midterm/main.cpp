#include <iostream>
#include "value.h"

int main(int argc, char const *argv[])
{
  String str1 = String("A");
  String str2 = String("a");
  Integer int1 = Integer(1);
  Integer int2 = Integer(2);
  Float flt1 = Float(1.5);
  Float flt2 = Float(2.5);

  std::string s1 = "A";
  std::string s2 = "a";

  std::cout << s1.compare(s2) << std::endl;

  std::cout << (str1 < str2) << std::endl;
  std::cout << (str1 < int1) << std::endl;
  std::cout << (str2 < flt1) << std::endl;
  std::cout << (int1 < int2) << std::endl;
  std::cout << (int1 < flt1) << std::endl;
  std::cout << (flt1 < flt2) << std::endl;
  
  std::cout << str1.ToString() << std::endl;
  std::cout << str2.ToString() << std::endl;
  std::cout << int1.ToString() << std::endl;
  std::cout << int2.ToString() << std::endl;
  std::cout << flt1.ToString() << std::endl;
  std::cout << flt2.ToString() << std::endl;
  return 0;
}