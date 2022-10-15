#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(llong& rmax)
{
  cin >> rmax;
}
  
llong calcComma(llong max)
{
  llong cntComma = 0;

  for (llong base = 999; base <= max; base *= 1000, base += 999)
    cntComma += max - base;

  return cntComma;
}

int main()
{
  llong max;
  input(max);
  cout << calcComma(max) << endl;

  return 0;
}
