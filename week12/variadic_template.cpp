#include <iostream>

template <typename T>
T Sum(T x) {
  return x;
}

template <typename T, typename... Rest>
T Sum(T x, Rest... rest) {
  return x + Sum(rest...);
}

int main()
{
  int int_sum1 = Sum(3, 7);
  std::string string_sum1 = Sum(std::string("Welcom"), std::string(" to"));

  std::cout << "IntSum1 : " << int_sum1 <<std::endl;
  std::cout << "SringSum1 : " << string_sum1 <<std::endl;

  int int_sum2 = Sum(1, 2, 3, 4, 5);
  std::string string_sum2 = 
    Sum(std::string("Welcom"), std::string(" "), std::string("to"),
        std::string(" "), std::string("the"), std::string(" "),
        std::string("ood20"), std::string(" "), std::string("class!"));
  
  std::cout << "IntSum2 : " << int_sum2 <<std::endl;
  std::cout << "SringSum2 : " << string_sum2 <<std::endl;

  return 0;
}
