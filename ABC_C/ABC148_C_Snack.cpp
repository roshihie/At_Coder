#include <bits/stdc++.h>
using namespace std;

void fnInput(int& rnNumA, int& rnNumB)
{
  cin >> rnNumA >> rnNumB;
}

int64_t fnLCMGet(int nNumA, int nNumB)
{
  int nDividend = max(nNumA, nNumB);
  int nDivisor  = min(nNumA, nNumB);

  while (nDividend % nDivisor != 0)
  {
    int nRemain = nDividend % nDivisor;
    nDividend = nDivisor;
    nDivisor  = nRemain;
  }

  int nGCD = nDivisor;
  int nQuotA = nNumA / nGCD;
  int nQuotB = nNumB / nGCD;
  return ((int64_t)nGCD * nQuotA * nQuotB);
}

int main()
{
  int nNumA, nNumB;

  fnInput(nNumA, nNumB);
  cout << fnLCMGet(nNumA, nNumB) << endl;

  return 0;
}
