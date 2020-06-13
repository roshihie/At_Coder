#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void fnInput(int& rnMaxNum)
{
  cin >> rnMaxNum;
}

bool fnDgt753_Check(llong nRecNum)
{
  int nDgt3 = 0, nDgt5 = 0, nDgt7 = 0;

  while (nRecNum)
  {
    int n1stDgt = nRecNum % 10;

    if      (n1stDgt == 3) nDgt3++;
    else if (n1stDgt == 5) nDgt5++;
    else if (n1stDgt == 7) nDgt7++;

    nRecNum /= 10;
  }

  if (nDgt3 && nDgt5 && nDgt7)
    return true;
  else
    return false;
}

void fnDfs(int nMaxNum, llong nRecNum)
{
  static int stn753DgtCnt = 0;

  if (nRecNum > nMaxNum) return;
  if (fnDgt753_Check(nRecNum)) stn753DgtCnt++;

  fnDfs(nMaxNum, 10 * nRecNum + 3);
  fnDfs(nMaxNum, 10 * nRecNum + 5);
  fnDfs(nMaxNum, 10 * nRecNum + 7);

  if (!nRecNum) cout << stn753DgtCnt << endl;
}

int main()
{
  int nMaxNum;

  fnInput(nMaxNum);
  fnDfs(nMaxNum, 0);

  return 0;
}
