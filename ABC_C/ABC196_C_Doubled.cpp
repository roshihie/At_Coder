#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(llong& rmax)
{
  cin >> rmax;
}

int calcSameHalfNum(llong max)
{
  llong num = max;
  int digtWhole = 0;
  int digtHalf  = 0;

  while ( num )
  {
    ++digtWhole;
    num /= 10;
  }

  digtHalf = digtWhole / 2;
  if ( digtWhole % 2 == 0 )
  {
    int baseSplt = 1;
                       // 10 の digtHalf 乗 を作成
    for (int nx = 0; nx < digtHalf; ++nx)
      baseSplt *= 10;
   
    int numLeft  = max / baseSplt;
    int numRight = max % baseSplt;
    if (numLeft <= numRight)
      return numLeft;
    else
      return numLeft - 1;
  }
  else
  {
    int numHalf = 0;
                       // digtHalf 桁の ALL 9 を作成
    for (int nx = 0; nx < digtHalf; ++nx)
      numHalf = 10 * numHalf + 9;

    return numHalf;
  }
}

int main()
{
  llong max;
  input(max);
  cout << calcSameHalfNum(max) << endl;

  return 0;
}
