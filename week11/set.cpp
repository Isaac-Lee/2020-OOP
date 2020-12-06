#include <iostream>
#include <set>

void Print(const std::set<int>& s) {
  for (int i : s) {
    std::cout << " " << i;
  }
  std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
  std::set<int> s;

  s.insert(10);
  s.insert(20);
  s.insert(30);
  s.insert(10);
  Print(s);

  s.erase(20);
  Print(s);

  auto iter = s.find(20);
  if (iter != s.end()) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }
  return 0;
}
