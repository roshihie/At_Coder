#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(llong& rnMaxNum, vector<llong>& rvnCapcty)
{
  cin >> rnMaxNum;

  for (llong& rnCapcty : rvnCapcty)
    cin >> rnCapcty;
}

int calcTransptCnt(llong nMaxNum, const vector<llong>& cnrvnCapcty)
{
  int nTime = 0;
  vector<llong> vnNum(cnrvnCapcty.size() + 1);
  vnNum[0] = nMaxNum;

  while (vnNum[ cnrvnCapcty.size() ] != nMaxNum)
  {
    nTime++;

    for (int nx = cnrvnCapcty.size() - 1; nx >= 0; --nx)
      if ( vnNum[nx] )
      {
        llong nTrnsNum = min(vnNum[nx], cnrvnCapcty[nx]);
        vnNum[nx] -= nTrnsNum;
        vnNum[nx + 1] += nTrnsNum;
      }

  }
  return nTime;
}
 
int main()
{
  llong nMaxNum;
  vector<llong> vnCapcty(5);

  input(nMaxNum, vnCapcty);
  cout << calcTransptCnt(nMaxNum, vnCapcty) << endl;

  return 0;
}
