#include <Hall/Hall.h>
#include <fatfs/ff.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Timo {
  int int1;
  long long2;
  double abcd;
} Timo;

int main() {
  // unsigned short data[400*240];
  // Hall::Clear(1);

  // while (!Hall::GetVSync()){};
  // Hall::SetCommandSwapBuffers();
  // Hall::Clear(1);
  // Hall::SetCommandSwapBuffers();

  // FATFS Fatfs;
  // FIL image_file;

  // // f_mount(&Fatfs, "", 0);
  // f_open(&image_file, "bild.bmp", FA_READ);

  // UINT br;
  // f_read(&image_file, data, 400*240, &br);

  Timo *t1 = (Timo *)malloc(sizeof(Timo));
  Timo *t2 = (Timo *)malloc(sizeof(Timo));
  Timo *t3 = (Timo *)malloc(sizeof(Timo));
  Timo *t4 = NULL;
  printf("t1: %p, t2: %p, t3: %p, t4: %p\n", t1, t2, t3, t4);
  free(t1);
  t4 = (Timo *)malloc(sizeof(Timo));
  printf("t1: %p, t2: %p, t3: %p, t4: %p\n", t1, t2, t3, t4);

  while (true) {
  };
  return 0;
}
