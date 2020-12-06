#include <iostream>
#include <typeinfo>

class Base { virtual void member(){}};
class Derived : Base{};

int main () {
  try
  {
    Base b;
    Derived& rd = dynamic_cast<Derived&>(b);
  }
  catch(const std::exception& e)
  {
    std::cerr << "Caught: " << e.what() << '\n';
    std::cerr << "Type: " << typeid(e).name() << '\n';
  }
  
}