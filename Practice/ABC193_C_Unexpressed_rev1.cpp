#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(llong& rmax)
{
  cin >> rmax;
}
  
llong calcPowerNumCnt(llong max)
{
  unordered_set<llong> sePower;
  llong sqrtNum = (llong)sqrt(max);

  for (llong base = 2; base <= sqrtNum; ++base)
    for (llong power = base * base; power <= max; power *= base)
      sePower.insert( power );

  return max - sePower.size();
}

int main()
{
  llong max;
  input(max);
  cout << calcPowerNumCnt(max) << endl;

  return 0;
}
