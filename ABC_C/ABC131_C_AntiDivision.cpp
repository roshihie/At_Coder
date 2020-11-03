#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(llong& rnLow, llong& rnHigh, int& rnDivsor1, int& rnDivsor2)
{
  cin >> rnLow >> rnHigh >> rnDivsor1 >> rnDivsor2;
}

int calcGcd(int nOne, int nOtr)
{
  if ( !nOtr ) return nOne;
  return calcGcd(nOtr, nOne % nOtr);
}

llong countAntiDiv(llong nNum, int nDivsor1, int nDivsor2)
{
  static llong stnDivLcm = 0;

  if ( !stnDivLcm )
  {
    int nDivGcd = calcGcd(nDivsor1, nDivsor2);
    stnDivLcm = (llong)nDivsor1 * (nDivsor2 / nDivGcd);
  }
  llong nDiv1Cnt = nNum / nDivsor1;
  llong nDiv2Cnt = nNum / nDivsor2;
  llong nDLcmCnt = nNum / stnDivLcm;

  return nNum - (nDiv1Cnt + nDiv2Cnt - nDLcmCnt);
}
  
int main()
{
  llong nLow, nHigh;
  int nDivsor1, nDivsor2;

  input(nLow, nHigh, nDivsor1, nDivsor2);
  cout << countAntiDiv(nHigh, nDivsor1, nDivsor2) - countAntiDiv(nLow - 1, nDivsor1, nDivsor2);
  cout << endl;

  return 0;
}
