/*满足下列条件的自然数称为超级素数:该数本身,所有数字之和,所有数字之积以及所有数字的平方和都是素数.例如113就是一个超级素数.求[100,9999]之内:(1)超级素数的个数.(2)所有超级素数之和.(3)最大的超级素数.*/
#include <stdio.h>
int sum_bit(int num) {
  int sum = 0;
  while(num != 0)
  {
    sum += num%10;
    num /= 10;
  }
  return sum;
}

int multi_bit(int num) {
  int mul = 1;
  while(num != 0)
  {
    mul *= num%10;
    num /= 10;
  }
  return mul;
}

int square_sum_bit(int num) {
  int sum = 0;
  while(num != 0)
  {
    sum += (num%10)*(num%10);
    num /= 10;
  }
  return sum;
}

bool isprime(int num) {
  int i;
  if(num < 2)
    return false;
  for(i = 2; i < num; i++)
    if(num%i==0)
      break;
  if(i==num)
    return true;
  else
    return false;
}

int main() {
  int cnt = 0, sum = 0, max, i;
  for(i = 100; i <= 9999; i++)
  {
    if(isprime(i)&&isprime(sum_bit(i))&&isprime(multi_bit(i))&&isprime(square_sum_bit(i)))
    {
      cnt++;
      sum += i;
      max = i;
    }
  }
  printf("超级素数有%d个\n其和为%d\n最大的是%d\n", cnt, sum, max);
  return 0;
}
