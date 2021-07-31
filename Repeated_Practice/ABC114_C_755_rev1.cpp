#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void fnInput(int& rnMaxNum)
{
  cin >> rnMaxNum;
}

bool fnDgt753_Check(llong nRecNum)
{
  bool bDgt7 = false;
  bool bDgt5 = false;
  bool bDgt3 = false;

  while ( nRecNum )
  {
    int nRem = nRecNum % 10;
    if      (nRem == 3) bDgt3 = true;
    else if (nRem == 5) bDgt5 = true;
    else if (nRem == 7) bDgt7 = true;

    nRecNum /= 10;
  }
  if (bDgt3 && bDgt5 && bDgt7)
    return true;
  else
    return false;
}

void fnDfs(int nMaxNum, llong nRecNum)
{
  static int stnDgt753Cnt = 0;

  if (nMaxNum < nRecNum) return;
  if (fnDgt753_Check(nRecNum) ) stnDgt753Cnt++;

  fnDfs(nMaxNum, nRecNum * 10 + 3);
  fnDfs(nMaxNum, nRecNum * 10 + 5);
  fnDfs(nMaxNum, nRecNum * 10 + 7);

  if ( !nRecNum ) cout << stnDgt753Cnt << endl;
}

int main()
{
  int nMaxNum;

  fnInput(nMaxNum);
  fnDfs(nMaxNum, 0);

  return 0;
}
