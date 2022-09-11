#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(llong& rmax)
{
  cin >> rmax;
}
  
llong calcWholeNum(int numHalfLow)
{
  llong numHalfHigh = (llong)numHalfLow;
  int num = numHalfLow;
  int digit = 0;

  while ( num )
  {
    ++digit;
    num /= 10;
  }

  for (int nx = 0; nx < digit; ++nx)
    numHalfHigh *= 10;

  return numHalfHigh + numHalfLow;
}

int calcSameHalfNum(llong max)
{
  int digtWhole = 0;
  llong num = max;

  while ( num )
  {
    ++digtWhole;
    num /= 10;
  }

  int digtHalf = digtWhole / 2;
  int numHalfLow = 1;

  for (int nx = 1; nx < digtHalf; ++nx)
    numHalfLow *= 10;

  while ( calcWholeNum(numHalfLow) <= max )
    ++numHalfLow;

  return numHalfLow - 1;
}

int main()
{
  llong max;
  input(max);
  cout << calcSameHalfNum(max) << endl;

  return 0;
}
