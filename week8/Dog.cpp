// Copyright [2020] <LeeYesung>
#include <iostream>

class Dog {
 public:
  virtual void Run() const = 0;
  virtual void Bark() const = 0;
};

class Siba : public Dog {
 public:
  void Run() const override {
    std::cout << "Siba Running!" << std::endl;
  }
  void Bark() const override {
    std::cout << "Siba!" << std::endl;
  }
};

class Jindo : public Dog {
 public:
  void Run() const override {
    std::cout << "Jindo Running!" << std::endl;
  }
  void Bark() const override {
    std::cout << "Jindo!" << std::endl;
  }
};

class Chiwawa : public Dog {
 public:
  void Run() const override {
    std::cout << "Chiwawa Running!" << std::endl;
  }
  void Bark() const override {
    std::cout << "Chiwawa!" << std::endl;
  }
};

int main() {
  Siba siba = Siba();
  Jindo jindo = Jindo();
  Chiwawa chiwawa = Chiwawa();

  siba.Run();
  jindo.Run();
  chiwawa.Run();

  siba.Bark();
  jindo.Bark();
  chiwawa.Bark();

  return 0;
}
