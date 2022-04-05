#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(llong& rmax)
{
  cin >> rmax;
}
  
llong calcPowerNumCnt(llong max)
{
  unordered_set<llong> usePowNum;

  for (llong base = 2; base * base <= max; ++base)
    for (llong num = base * base; num <= max; num *= base)
      usePowNum.insert( num );

  return  max - usePowNum.size();
}

int main()
{
  llong max;
  input(max);
  cout << calcPowerNumCnt(max) << endl;

  return 0;
}
