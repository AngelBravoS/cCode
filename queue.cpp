#include <iostream>
#include <queue>

using std::cout;
using std::endl;
using std::queue;
using std::string;

template <typename Queue>
void printQueue(Queue q) {
  while (!q.empty()) {
    cout << q.front() << ", ";
    q.pop();
  }
  cout << endl;
}

int main() {
  std::queue<string> q1;
  std::deque<string> deq1 = {"uno", "ocho", "seis", "siete", "once", "diez"};

  for (const auto& n : deq1) q1.push(n);

  std::queue<string> q2(deq1);
  q2.push(deq1.front());
  q2.push("cero");

  cout << "cola 1: ";
  printQueue(q1);
  cout << "cola 2: ";
  printQueue(q2);

  q1.swap(q2);

  cout << "cola 1: ";
  printQueue(q1);
  cout << "cola 2: ";
  printQueue(q2);

  return EXIT_SUCCESS;
}
