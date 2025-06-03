#include <Hall/Hall.h>
#include <string.h>
#include <math.h>

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
  *a = pow(2,20);

  return 0;
}
