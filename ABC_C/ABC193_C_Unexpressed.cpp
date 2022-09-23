#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(llong& rmax)
{
  cin >> rmax;
}
  
llong calcPowerCnt(llong max)
{
  unordered_set<llong> usePower;

  for (llong base = 2; base * base <= max; ++base)
    for (llong power = base * base; power <= max; power *= base)
      usePower.insert( power );

  return  max - usePower.size();
}

int main()
{
  llong max;
  input(max);
  cout << calcPowerCnt(max) << endl;

  return 0;
}
