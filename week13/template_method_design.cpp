#include <iostream>

class Base {
 public:
  void execute() {
    a();
    ph1();
    c();
    ph2();
    e();
  }
 private:
  void a() { std::cout <<"a"; }
  void c() { std::cout <<"c"; }
  void e() { std::cout <<"e"; }
  virtual void ph1() = 0;
  virtual void ph2() = 0;
};

class One : public Base {
 private:
  void ph1() { std::cout << "b"; }
  void ph2() { std::cout << "d"; }
};

class Two : public Base {
 private:
  void ph1() { std::cout << "2"; }
  void ph2() { std::cout << "4"; }
};

int main() {
  Base *one = new One();
  Base *two = new Two();

  one->execute();
  std::cout << std::endl;
  two->execute();
  std::cout << std::endl;
}