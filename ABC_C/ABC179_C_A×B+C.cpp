#include <bits/stdc++.h>
using namespace std;

void input(int& rnNum)
{
  cin >> rnNum;
}

int calcABC_PairCnt(int nNum)
{
  int nABC_PairCnt = 0;

  for (int nx = 1; nx < nNum; ++nx)
  {
    int nDivCnt = 0;
    nDivCnt += (nNum - 1) / nx;
    nABC_PairCnt += nDivCnt;
  }
  return nABC_PairCnt;
}

int main()
{
  int nNum;
  input(nNum);
  cout << calcABC_PairCnt(nNum) << endl;

  return 0;
}
