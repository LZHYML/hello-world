#include <iostream.h>
class Clock {
 public:
  Clock(int h=0, int m=0, int s=0);
  void tick();
  void show();
  void adjust(int,int,int);
 private:
  int hour, min, second;
};

int main() {
  Clock ck;
  ck.tick();
  ck.show();
  ck.adjust(16,45,00);
  ck.show();
  return 0;
}

Clock::Clock(int h, int m, int s)
{
  hour = h;
  min = m;
  second = s;
}

void Clock::tick()
{
  if(second<59)
    second++;
  else if(min<59)
  {
    min++;
    second;
  }
  else if(hour<23)
  {
    hour++;
    min = 0;
    second = 0;
  }
  else
  {
    hour = 0;
    min = 0;
    second = 0;
  }
}

void Clock::show()
{
  cout.fill('0');
  cout.width(2);
  cout<<hour<<":";
  cout.fill('0');
  cout.width(2);
  cout<<min<<":";
  cout.fill('0');
  cout.width(2);
  cout<<second<<endl;
}

void Clock::adjust(int h, int m, int s)
{
  if(!(0<=hour && hour<=24 && 0<=min && min<=59 && 0<=second && second<=59))
    cout<<"输入时间非法！"<<endl;
  else
  {
  hour = h;
  min = m;
  second = s;
  }
}
