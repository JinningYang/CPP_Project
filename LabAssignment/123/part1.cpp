#include <atomic>
#include <iostream>
#include <thread>

std::atomic_bool printed;

template <char f, char t, bool cnd> class Printer {
public:
  Printer() = delete;
  static void print() {
    for (char i = f; i <= t; i++) {
      while (printed != cnd)
        ;
      std::cout << i;
      printed = !cnd;
    }
  }
};

int main() {
  printed = true;
  std::thread th1(Printer<'a', 'z', true>::print),
      th2(Printer<'A', 'Z', false>::print);
  th1.join();
  th2.join();
  std::cout << std::endl;
  return 0;
}