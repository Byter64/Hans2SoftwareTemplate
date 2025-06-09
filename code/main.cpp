#include "Hall/Video.h"
#include <Hall/Hall.h>
#include <algorithm>
#include <fatfs/ff.h>
#include <memory>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

typedef struct Timo {
  int int1;
  long long2;
  double abcd;
} Timo;

class Timo2 {
public:
  Timo2(int hunger, int energie) : hunger(hunger), energie(energie) {
    noten.push_back(1.0);
    noten.push_back(1.7);
    noten.push_back(2.8);
    noten.push_back(2.19);
  }

  ~Timo2() {}

  double besteNote() {
    return *std::max_element(noten.begin(), noten.end());
    // double current_max = -1;
    // for (auto d : noten) {
    //   if (d < current_max) {
    //     current_max = d;
    //   }
    // }

    // return current_max;
  }

private:
  int hunger;
  int energie;
  std::vector<double> noten;
};

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

  // Timo *t1 = (Timo *)malloc(sizeof(Timo));
  // Timo *t2 = (Timo *)malloc(sizeof(Timo));
  // Timo *t3 = (Timo *)malloc(sizeof(Timo));
  // Timo *t4 = NULL;
  // printf("t1: %p, t2: %p, t3: %p, t4: %p\n", t1, t2, t3, t4);
  // free(t1);
  // t4 = (Timo *)malloc(sizeof(Timo));
  // printf("t1: %p, t2: %p, t3: %p, t4: %p\n", t1, t2, t3, t4);

  // std::unique_ptr<Timo2> abc = std::make_unique<Timo2>(200, 100);
  // printf("Die beste Note ist: %f\n", abc->besteNote());

  Hall::Clear(1);
  while (Hall::GetIsGPUBusy()) {
  }
  Hall::SetCommandSwapBuffers();
  Hall::Clear(1);
  while (Hall::GetIsGPUBusy()) {
  }
  Hall::SetCommandSwapBuffers();

  while (true) {
  };
  return 0;
}
