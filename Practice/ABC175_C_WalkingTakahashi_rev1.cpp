#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(llong& rnCoordx, llong& rnTimes, llong& rnMovmnt)
{
  cin >> rnCoordx >> rnTimes >> rnMovmnt;
}
  
llong calcMinCoordx(llong nCoordx, llong nTimes, llong nMovmnt)
{
  llong nQuantnt = nCoordx / nMovmnt;

  if (nQuantnt >= nTimes)
    return nCoordx - nMovmnt * nTimes;
  else
  {
    nCoordx -= nMovmnt * nQuantnt;
    nTimes -= nQuantnt;

    if ( nTimes % 2 )
      return abs(nCoordx - nMovmnt);
    else
      return nCoordx;
  }
}
  
int main()
{
  llong nCoordx, nTimes, nMovmnt;

  input(nCoordx, nTimes, nMovmnt);
  cout << calcMinCoordx(abs(nCoordx), nTimes, nMovmnt) << endl;

  return 0;
}
