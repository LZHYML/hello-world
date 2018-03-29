#include <iostream.h>
#include <stdio.h>
class Date {
public:
  Date(int y, int m, int d);
  ~Date();
  void nextDay();
  void previousDay();
  bool equal(Date other);
  void show();
private:
  int year;
  int month;
  int day;
};
bool IsLeapYear(int y);
int daynum[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int main() {
  Date today(2018,3,20);
  Date day(2018,3,20);
  day.show();
  for(int i=0;i<30;i++)
    day.nextDay();
  day.show();
  for(i=0;i<30;i++)
    day.previousDay();
  day.show();
  if(day.equal(today))
    printf("Very Good!\n");
  else
    printf("Very Bad!\n");
  return 0;
}

Date::Date(int y, int m, int d)
{
  year = y;
  month = m;
  day = d;
}

void Date::nextDay()
{
  day++;
  if(day>daynum[month])
  {
    if(!(IsLeapYear(year) && month==2 && day==29))
    {
      day = 1;
      month++;
    }
  }
  if(month>12)
  {
    month = 1;
    year++;
  }
}

void Date::previousDay()
{
  day--;
  if(day==0)
  {
    month--;
    if(IsLeapYear(year) && month==2)
      day = 29;
    else
      day = daynum[month];
  }
  if(month==0)
  {
    month = 12;
    year--;
  }
}

bool Date::equal(Date other)
{
  if(year==other.year && month==other.month && day==other.day)
    return true;
  else
    return false;
}

void Date::show()
{
  cout.fill('0');
  cout.width(4);
  cout<<year<<"-";
  cout.fill('0');
  cout.width(2);
  cout<<month<<"-";
  cout.fill('0');
  cout.width(2);
  cout<<day<<endl;
}

bool IsLeapYear(int y)
{
  if(y%4==0 && y%100!=0 || y%400==0)
    return true;
  else
    return false;
}

Date::~Date()
{
	cout<<"正在析构"<<year<<"年"<<month<<"月"<<day<<"日日期对象"<<endl;
}
