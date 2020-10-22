#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(int& rnPrcA, int& rnPrcB, llong& rnMoney)
{
  cin >> rnPrcA >> rnPrcB >> rnMoney;
}

int calcDigitCnt(int nMid)
{
  int nDigitCnt = 0;

  while (nMid != 0)
  {
    nDigitCnt++;
    nMid /= 10;
  }

  return nDigitCnt;
}

int canBuyInt(int nPrcA, int nPrcB, int nInt, llong nMoney)
{
   llong nIntPrice = (llong)nPrcA * nInt + (llong)nPrcB * calcDigitCnt(nInt);
 
   if (nIntPrice <= nMoney)
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
