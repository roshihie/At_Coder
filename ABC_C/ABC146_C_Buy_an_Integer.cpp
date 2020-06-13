#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void fnInput(int& rnPriceA, int& rnPriceB, llong& rnMoney)
{
  cin >> rnPriceA >> rnPriceB >> rnMoney;
}

int fnDigitCnt(int nMid)
{
  int nDigitCnt = 0;

  while (nMid != 0)
  {
    nDigitCnt++;
    nMid /= 10;
  }

  return nDigitCnt;
}

int fnCanBuyInt(int nPriceA, int nPriceB, int nMid, llong nMoney)
{
   llong nIntPrice = (llong)nPriceA * nMid + (llong)nPriceB * fnDigitCnt(nMid);
 
   if (nIntPrice <= nMoney)
     return 1;
   else
     return 0;
}

int fnMaxBuyIntGet(int nPriceA, int nPriceB, llong nMoney)
{
  int nHigh = 1000000001;
  int nLow  = 1;
  int nMaxBuyInt = 0;

  while (nLow < nHigh)
  {
    int nMid = (nLow + nHigh) / 2;

    if (fnCanBuyInt(nPriceA, nPriceB, nMid, nMoney))
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
  int nPriceA, nPriceB;
  llong nMoney;

  fnInput(nPriceA, nPriceB, nMoney);
  cout << fnMaxBuyIntGet(nPriceA, nPriceB, nMoney) << endl;

  return 0;
}
