#include <iostream>
#include <math.h>
#define PI 3.1415926
using namespace std;

class Parallelogram {
  public:
  Parallelogram();
  void show();
  void area();
  void height();
  void length();
  private:
  double side1, side2, radian;
};

int main() {
  Parallelogram pg;
  pg.show();
  pg.area();
  pg.height();
  pg.length();
  return 0;
}

Parallelogram::Parallelogram()
{
  side1 = 8;
  side2 = 6*sqrt(2);
  radian = PI/4;
}

void Parallelogram::show()
{
  cout<<"********"<<endl;
  cout<<"  ********"<<endl;
  cout<<"    ********"<<endl;
  cout<<"      ********"<<endl;
}

void Parallelogram::area()
{
  double area = side1 * side2 * sin(radian);
  cout<<"平行四边形面积是"<<area<<endl;
}

void Parallelogram::height()
{
  double height = side2 * sin(radian);
  cout<<"平行四边形的高为"<<height<<endl;
}

void Parallelogram::length()
{
  double length = (side1 + side2) * 2;
  cout<<"平行四边形的边长为"<<length<<endl;
}
