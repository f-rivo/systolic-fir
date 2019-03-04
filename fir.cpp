#include <iostream>
#include "fir.h"
using namespace std;

void filter(data_t *x, coef_t h[4], sum_t *y)
{

  static systolic<data_t, coef_t, sum_t> s[4];

  data_t x_int[4];
  sum_t y_int[4];
  sum_t tmp = 0;

connect:
  for (int i = 0; i < TAP; i++)
  {
    if (i == 0)
      s[0].exec(*x, h[i], tmp, x_int[i], y_int[i]);
    else
      s[i].exec(x_int[i - 1], h[i], y_int[i - 1], x_int[i], y_int[i]);
    *y = y_int[3];
  }
}

int main()
{

  data_t X[14] = {10, 4, 1, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  coef_t H[TAP] = {1, 2, 2, 1};
  sum_t Y = 0;

  for (int i = 0; i < 14; i++)
  {
    filter(&X[i], H, &Y);
    cout << "LOOP: " << i << " with x " << X[i] << endl;
    cout << "Y: "
         << " " << Y << endl;
  }

  cout << "Result: " << Y << endl;
}