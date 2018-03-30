#include <iostream>
using namespace std;

class Prime {
public:
  Prime(int num);
  ~Prime();

  bool isPrime();

  Prime sumBit();
  Prime multiBit();
  Prime sqaureSumBit();
private:
  int mNum;
};

int main() {
  int cnt = 0, sum = 0, max;
  for(int i = 100; i <= 9999; i++)
  {
    Prime pm(i);
    Prime sb = pm.sumBit();
    Prime mb = pm.multiBit();
    Prime ssb = pm.sqaureSumBit();
    if(pm.isPrime() && sb.isPrime() && mb.isPrime() && ssb.isPrime())
    {
      cnt++;
      sum += i;
      max = i;
    }
  }
  cout<<"在[100,9999]之间"<<endl;
  cout<<"超级素数有"<<cnt<<"个"<<endl;
  cout<<"所有超级素数之和为"<<sum<<endl;
  cout<<"其中最大的超级素数是"<<max<<endl;
  return 0;
}

Prime::Prime(int num)
{
  mNum = num;
}

Prime::~Prime()
{
//  cout<<"正在析构"<<mNum<<"数字对象"<<endl;
}

bool Prime::isPrime()
{
  if(mNum<2)
    return false;
  for(int i = 2; i < mNum; i++)
  {
    if(mNum%i==0)
      break;
  }
  if(i==mNum)
    return true;
  else
    return false;
}

Prime Prime::sumBit()
{
  int sb = 0, tem = mNum;
  while(tem != 0)
  {
    sb += tem%10;
    tem /= 10;
  }
  Prime p(sb);
  return p;
}

Prime Prime::multiBit()
{
  int mb = 1, tem = mNum;
  while(tem != 0)
  {
    mb *= tem%10;
    tem /= 10;
  }
  Prime p(mb);
  return p;
}

Prime Prime::sqaureSumBit()
{
  int ssb = 0, tem = mNum;
  while(tem != 0)
  {
    ssb += (tem%10)*(tem%10);
    tem /= 10;
  }
  Prime p(ssb);
  return p;
}
