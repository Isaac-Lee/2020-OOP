#include <iostream>
#include <vector>

void Print(const std::vector<int>& vec) {
  for (int i = 0; i < vec.size(); ++i) {
    std::cout << " " << vec[i];
  }
  std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
  std::vector<int> vec;

  vec.push_back(1);
  vec.push_back(2);
  Print(vec);

  vec.insert(vec.begin(), 3);
  Print(vec);

  vec.erase(vec.begin()+1);
  Print(vec);

  vec[0] = 4;
  Print(vec);
  return 0;
}
