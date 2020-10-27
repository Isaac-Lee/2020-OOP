// Copyright [2020] <박형기>
#include <iostream>

class Fish {
 public:
    virtual void swim() const = 0;
    virtual void eat() const = 0;
};
class Shark : public Fish {
 public:
    void swim() const override {
        std::cout << "뚜루루뚜루" << std::endl;
    }
    void eat() const override {
        std::cout << "냠냠냠" << std::endl;
    }
};

class FlyingFish : public Fish {
 public:
    void swim() const override {
        std::cout << "I believe i can fly" << std::endl;
    }
    void eat() const override {
        std::cout << "냠" << std::endl;
    }
};

class Hairtail : public Fish {
 public:
    void swim() const override {
        std::cout << "HairHair" << std::endl;
    }
    void eat() const override {
        std::cout << "냠냠" << std::endl;
    }
};
int main() {
    Shark shark = Shark();
    FlyingFish flyingfish = FlyingFish();
    Hairtail hairtail = Hairtail();

    shark.swim();
    shark.eat();
    flyingfish.swim();
    flyingfish.eat();
    hairtail.swim();
    hairtail.eat();
    return 0;
}
