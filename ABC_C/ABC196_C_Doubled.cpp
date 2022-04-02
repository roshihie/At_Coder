#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(llong& rmax)
{
  cin >> rmax;
}
  
llong calcWholeNum(int numHalf2)
{
  llong numHalf1 = numHalf2;
  int num = numHalf2;
  int digit = 0;

  while ( num )
  {
    ++digit;
    num /= 10;
  }

  for (int nx = 0; nx < digit; ++nx)
    numHalf1 *= 10;

  return numHalf1 + numHalf2;
}

int calcSameHalfNum(llong max)
{
  int digitMax = 0;
  llong num = max;

  while ( num )
  {
    ++digitMax;
    num /= 10;
  }

  int digitMin = digitMax / 2;
  int numHalf2 = 1;

  for (int nx = 1; nx < digitMin; ++nx)
    numHalf2 *= 10;

  while ( calcWholeNum(numHalf2) <= max )
    ++numHalf2;

  return numHalf2 - 1;
}

int main()
{
  llong max;
  input(max);
  cout << calcSameHalfNum(max) << endl;

  return 0;
}
