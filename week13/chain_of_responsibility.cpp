#include <ctime>
#include <iostream>

class Base {
 public:
  Base() { next = 0; }
  void setNext(Base* n) { next = n; }
  void add(Base * n) {
    if (next)
      next->add(n);
    else
      next = n;
  }
  virtual void handle(int i) { next->handle(i); }

 private:
  Base* next;
};

class Handler1 : public Base {
 public:
  void handle(int i) {
    if (rand() % 3) {
      std::cout << "H1 passed " << i << " ";
      Base::handle(i);
    } else {
      std::cout << "H1 handled " << i << " ";
    }
  }
};

class Handler2 : public Base {
 public:
  void handle(int i) {
    if (rand() % 3) {
      std::cout << "H2 passed " << i << " ";
      Base::handle(i);
    } else {
      std::cout << "H2 handled " << i << " ";
    }
  }
};

class Handler3 : public Base {
 public:
  void handle(int i) {
    if (rand() % 3) {
      std::cout << "H3 passed " << i << " ";
      Base::handle(i);
    } else {
      std::cout << "H3 handled " << i << " ";
    }
  }
};

int main() {
  srand((unsigned int)time(0));
  Handler1 root;
  Handler2 two;
  Handler3 thr;
  root.add(&two);
  root.add(&thr);
  thr.setNext(&root);
  for (int i = 1; i < 10; i++) {
    root.handle(i);
    std::cout << std::endl;
  }
}