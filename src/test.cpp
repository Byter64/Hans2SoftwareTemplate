#include <string.h>
#include <Hall/Hall.h>

class My_cool_class {
public:
  int a;
  long b;

  My_cool_class(int a, long b) {
    this->a = a;
    this->b = b;
  }
};

int main() {
  volatile int *a = (volatile int *)0x1234;
  *a = 100;

  // Hall::Draw()

  return 0;
}
