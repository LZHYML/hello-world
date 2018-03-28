#include <stdio.h>
struct Date {
  int year;
  int month;
  int day;
};
int daynum[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
bool IsLeapYear(int y)
{
	if(y%4==0 && y%100!=0 || y%400==0)
		return true;
	else
		return false;
}
void next_day(struct Date *day)
{
	if(day->day < daynum[day->month])
	{
		day->day++;
		return;
	}
	if(day->month==2 && IsLeapYear(day->year))
	{
		day->day++;
		return;
	}
	if(day->month==12)
	{
		day->year++;
		day->month = 1;
		day->day = 1;
		return;
	}
	day->month++;
	day->day = 1;
}
void previous_day(struct Date *day)
{
  if(day->day!=1)
  {
    day->day--;
    return;
  }
  if(day->month==3 && IsLeapYear(day->year))
  {
    day->month--;
    day->day = 29;
    return;
  }
  if(day->month==1)
  {
    day->year--;
    day->month = 12;
    day->day = 31;
    return;
  }
  day->month--;
  day->day = daynum[day->month];
}
int equal(struct Date *one, struct Date *day)
{
  if(one->year==day->year && one->month==day->month && one->day==day->day)
    return 1;
  else
    return 0;
}
void show(struct Date *day) {
  printf("%d-%d-%d\n", day->year, day->month, day->day);
}
int main() {
  struct Date today = {2018,3,20};
  struct Date day = {2018,3,20};
  show(&day);
  for(int i=0;i<30;i++)
    next_day(&day);
  show(&day);
  for(i=0;i<30;i++)
    previous_day(&day);
  show(&day);
  if(equal(&today, &day))
    printf("Very Good!\n");
  else
    printf("Very Bad!\n");
  return 0;
}
