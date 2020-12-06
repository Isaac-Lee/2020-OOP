#include <iostream>
#include <string>

class Element {
 public:
  virtual void accept(class Visitor &v) = 0;
};

class This : public Element {
 public:
  void accept(Visitor &v);
  std::string thiss() { return "This"; }
};

class That : public Element {
 public:
  void accept(Visitor &v);
  std::string that() { return "That"; }
};

class TheOther : public Element {
 public:
  void accept(Visitor &v);
  std::string theOther() { return "TheOther"; }
};

class Visitor {
 public:
  virtual void visit(This *e) = 0;
  virtual void visit(That *e) = 0;
  virtual void visit(TheOther *e) = 0;
};

void This::accept(Visitor &v) { v.visit(this); }
void That::accept(Visitor &v) { v.visit(this); }
void TheOther::accept(Visitor &v) { v.visit(this); }

class UpVisitor : public Visitor {
  void visit(This *e) { std::cout << "do Up on " + e->thiss() << std::endl; }
  void visit(That *e) { std::cout << "do Up on " + e->that() << std::endl; }
  void visit(TheOther *e) { std::cout << "do Up on " + e->theOther() << std::endl; }
};

class DownVisitor : public Visitor {
  void visit(This *e) { std::cout << "do Down on " + e->thiss() << std::endl; }
  void visit(That *e) { std::cout << "do Down on " + e->that() << std::endl; }
  void visit(TheOther *e) { std::cout << "do Down on " + e->theOther() << std::endl; }
};

int main()
{
  Element *list[] = {new This(), new That(), new TheOther()};
  UpVisitor up;
  DownVisitor down;
  for (int i=0; i < 3; i++) list[i]->accept(up);
  for (int i=0; i < 3; i++) list[i]->accept(down);
}
