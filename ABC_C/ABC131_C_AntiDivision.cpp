#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void fnInput(llong& rnLow, llong& rnHigh, int& rnDivsor1, int& rnDivsor2)
{
  cin >> rnLow >> rnHigh >> rnDivsor1 >> rnDivsor2;
}
  
llong fnAntiDivCnt(llong nLow, llong nHigh, int nDivsor1, int nDivsor2)
{
  int nDividend = max(nDivsor1, nDivsor2);
  int nDivisor  = min(nDivsor1, nDivsor2);

  while (nDividend % nDivisor)
  {
    int nRemndr = nDividend % nDivisor;
    nDividend = nDivisor;
    nDivisor  = nRemndr;
  }
  llong nDivLcm = (llong)nDivsor1 * (nDivsor2 / nDivisor);
  llong nLowLessDiv1Cnt = (nLow - 1) / nDivsor1;
  llong nLowLessDiv2Cnt = (nLow - 1) / nDivsor2;
  llong nLowLessDLcmCnt = (nLow - 1) / nDivLcm;

  llong nHighDev1Cnt = nHigh / nDivsor1;
  llong nHighDev2Cnt = nHigh / nDivsor2;
  llong nHighDLcmCnt = nHigh / nDivLcm;
  
  llong nDivsible = (nHighDev1Cnt + nHighDev2Cnt - nHighDLcmCnt) -
                    (nLowLessDiv1Cnt + nLowLessDiv2Cnt - nLowLessDLcmCnt);
  return (nHigh - nLow + 1) - nDivsible;
}
  
int main()
{
  llong nLow, nHigh;
  int nDivsor1, nDivsor2;

  fnInput(nLow, nHigh, nDivsor1, nDivsor2);
  cout << fnAntiDivCnt(nLow, nHigh, nDivsor1, nDivsor2) << endl;

  return 0;
}
