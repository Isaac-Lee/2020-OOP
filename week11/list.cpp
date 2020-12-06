#include <iostream>
#include <list>

void Print(const std::list<int>& lst) {
  for (int i : lst) {
    std::cout << " " << i;
  }
  std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
  std::list<int> lst;

  lst.push_back(2);
  lst.push_front(1);
  lst.push_back(3);
  lst.push_back(4);
  Print(lst);

  lst.insert(lst.begin(), 5);
  Print(lst);

  lst.erase(++lst.begin());
  Print(lst);

  lst.front() = 6;
  Print(lst);
  return 0;
}
