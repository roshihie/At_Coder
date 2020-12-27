#include <bits/stdc++.h>
using namespace std;

void input(int& rnNum)
{
  cin >> rnNum;
}

int calcABC_PairCnt(int nNum)
{
  int nABC_PairCnt = 0;

  for (int nC = 1; nC < nNum; ++nC)
  {
    int nATimesB = nNum - nC;

    int nDivCnt = 0;
    int nSqrtAB = sqrt(nATimesB);
    int nUpper;

    if (nATimesB == nSqrtAB * nSqrtAB)
    {
      ++nDivCnt;
      nUpper = nSqrtAB - 1;
    }
    else
      nUpper = nSqrtAB;
     
    for (int nAB = nUpper; nAB > 0; --nAB)
      if (nATimesB % nAB == 0)
        nDivCnt += 2;

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
