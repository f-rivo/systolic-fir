#define TAP 4

typedef int data_t;
typedef int coef_t;
typedef int sum_t;

template <typename T0, typename T1, typename T2>
class systolic
{
  private:
    T0 x;
    T2 y0;
    T2 y1;

  public:
    void exec(T0 &x_in, T1 &h, T2 &y_in, T0 &x_out, T2 &y)
    {
        y = y1;
        x_out = x;
        y1 = y0;
        y0 = x * h + y_in;
        x = x_in;
    }
};