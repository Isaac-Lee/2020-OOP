// Copyright [2020] <김민규>
#include <iostream>

class Bird {
 public:
  virtual void fly() const = 0;
  virtual void poop() const = 0;
};

class Pigeon : public Bird{
 public:
  void fly() const override {
    std::cout << "비둘기가 날 때 구구구구" << std::endl;
  }
  void poop() const override {
    std::cout << "비둘기가 덩 쌀때 구구" << std::endl;
  }
};

class Parrot : public Bird {
 public:
  void fly() const override {
    std::cout << "앵무새가 날 때 앵앵" << std::endl;
  }

  void poop() const override {
    std::cout << "앵무새가 덩쌀때 푹" << std::endl;
  }
};

class Crow : public Bird {
 public:
  void fly() const override {
    std::cout << "까마귀가 날 때 까악" << std::endl;
    }
  void poop() const override {
    std::cout << "까마귀가 덩쌀 때 꺅" << std::endl;
    }
};

int main() {
  Pigeon pigeon = Pigeon();
  Parrot parrot = Parrot();
  Crow crow = Crow();

  pigeon.fly();
  pigeon.poop();

  parrot.fly();
  parrot.poop();

  crow.fly();
  crow.poop();
}
