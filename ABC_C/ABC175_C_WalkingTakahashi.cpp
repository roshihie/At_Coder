#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(llong& rnCoordx, llong& rnTimes, llong& rnMovmnt)
{
  cin >> rnCoordx >> rnTimes >> rnMovmnt;
}
  
llong calcMinCoordx(llong nCoordx, llong nTimes, llong nMovmnt)
{
  llong nQuotnt = nCoordx / nMovmnt;
  llong nRemain = nCoordx % nMovmnt;

  if (nQuotnt < nTimes)
    if (nQuotnt % 2 == nTimes % 2)
      return nRemain;
    else
      return abs(nRemain - nMovmnt);
  else
    return nCoordx - nMovmnt * nTimes;
}
  
int main()
{
  llong nCoordx, nTimes, nMovmnt;

  input(nCoordx, nTimes, nMovmnt);
  cout << calcMinCoordx(abs(nCoordx), nTimes, nMovmnt) << endl;

  return 0;
}
