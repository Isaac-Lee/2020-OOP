#include <iostream>
#include <deque>

void Print(const std::deque<int>& deq) {
  for (int i = 0; i < deq.size(); ++i) {
    std::cout << " " << deq[i];
  }
  std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
  std::deque<int> deq;

  deq.push_back(2);
  deq.push_front(1);
  deq.push_back(3);
  deq.push_back(4);
  Print(deq);

  deq.insert(deq.begin()+1, 5);
  Print(deq);

  deq.erase(deq.begin()+1);
  Print(deq);

  deq[4] = 4;
  Print(deq);
  return 0;
}
