#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(llong& rmax)
{
  cin >> rmax;
}
  
llong calcWholeNum(int numHalf)
{
  string strHalf = to_string(numHalf);
  return stoll(strHalf + strHalf);
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
  string strHalf = "1";

  for (int nx = 1; nx < digitMin; ++nx)
    strHalf += "0";

  int numHalf = stoi(strHalf);

  while ( calcWholeNum(numHalf) <= max )
    ++numHalf;

  return numHalf - 1;
}

int main()
{
  llong max;
  input(max);
  cout << calcSameHalfNum(max) << endl;

  return 0;
}
