#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(int& rnMaxNum)
{
  cin >> rnMaxNum;
}

bool isDgt753(llong nRecrNum)
{
  int nDgt3 = 0, nDgt5 = 0, nDgt7 = 0;

  while (nRecrNum)
  {
    int n1stDgt = nRecrNum % 10;

    if      (n1stDgt == 3) ++nDgt3;
    else if (n1stDgt == 5) ++nDgt5;
    else if (n1stDgt == 7) ++nDgt7;

    nRecrNum /= 10;
  }
  if (nDgt3 && nDgt5 && nDgt7)
    return true;
  else
    return false;
}

void dfs(int nMaxNum, llong nRecrNum)
{
  static int stn753DgtCnt = 0;

  if (nRecrNum > nMaxNum) return;
  if ( isDgt753(nRecrNum) ) ++stn753DgtCnt;

  dfs(nMaxNum, 10 * nRecrNum + 3);
  dfs(nMaxNum, 10 * nRecrNum + 5);
  dfs(nMaxNum, 10 * nRecrNum + 7);

  if ( !nRecrNum ) cout << stn753DgtCnt << endl;
}

int main()
{
  int nMaxNum;

  input(nMaxNum);
  dfs(nMaxNum, 0);

  return 0;
}
