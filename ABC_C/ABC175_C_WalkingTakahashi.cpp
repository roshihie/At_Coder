#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(llong& rnCoordx, llong& rnTimes, llong& rnMovmnt)
{
  cin >> rnCoordx >> rnTimes >> rnMovmnt;
}
  
llong calcMinCoordx(llong nCoordx, llong nTimes, llong nMovmnt)
{
  llong nQuotnt = abs(nCoordx) / nMovmnt;
  llong nRemain = abs(nCoordx) % nMovmnt;

  if (nQuotnt <= nTimes)
    if (nQuotnt % 2 == nTimes % 2)
      return nRemain;
    else
      return abs(nRemain - nMovmnt);
  else
    return abs(nCoordx) - nTimes * nMovmnt;
}
  
int main()
{
  llong nCoordx, nTimes, nMovmnt;

  input(nCoordx, nTimes, nMovmnt);
  cout << calcMinCoordx(nCoordx, nTimes, nMovmnt) << endl;

  return 0;
}
