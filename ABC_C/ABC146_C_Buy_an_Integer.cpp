#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(int& rnPrcA, int& rnPrcB, llong& rnMoney)
{
  cin >> rnPrcA >> rnPrcB >> rnMoney;
}

int calcDigitCnt(int nTrg)
{
  int nDigitCnt = 0;

  while ( nTrg )
  {
    ++nDigitCnt;
    nTrg /= 10;
  }
  return nDigitCnt;
}

int canBuyInt(int nPrcA, int nPrcB, int nTrg, llong nMoney)
{
   llong nTrgPrice = (llong)nPrcA * nTrg + (llong)nPrcB * calcDigitCnt(nTrg);
 
   if (nTrgPrice <= nMoney)
     return 1;
   else
     return 0;
}

int calcMaxBuyInt(int nPrcA, int nPrcB, llong nMoney)
{
  int nHigh = 1e9 + 1;
  int nLow  = 1;
  int nMaxBuyInt = 0;

  while (nLow < nHigh)
  {
    int nMid = (nLow + nHigh) / 2;

    if (canBuyInt(nPrcA, nPrcB, nMid, nMoney))
    {
      nMaxBuyInt = nMid;
      nLow = nMid + 1;
    }
    else
      nHigh = nMid;
  }

  return nMaxBuyInt; 
}

int main()
{
  int nPrcA, nPrcB;
  llong nMoney;

  input(nPrcA, nPrcB, nMoney);
  cout << calcMaxBuyInt(nPrcA, nPrcB, nMoney) << endl;

  return 0;
}
