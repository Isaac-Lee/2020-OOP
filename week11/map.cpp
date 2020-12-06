#include <iostream>
#include <map>
#include <string>


void Print(const std::map<char, std::string>& m) {
  for (auto iter : m) {
    std::cout << iter.first << " "  << iter.second << std::endl;
  }
  std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
  std::map<char, std::string> m;
  m.insert({'a', "Apple"});
  m.insert({'b', "Banana"});
  m.insert({'c', "Cherry"});
  m['d'] = "Durian";
  Print(m);

  m.erase('d');
  m.erase(m.find('c'));
  Print(m);
  return 0;
}
