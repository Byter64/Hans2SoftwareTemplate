#include <Hall/Hall.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

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
  *a = pow(10, 2);

  My_cool_class test{1, 2L};
  *a = test.a;

  printf("hallo %d, Welt!\n", test.a);
  printf("hallo %f, Welt!\n", pow(test.b, test.a));

  return 0;
}
