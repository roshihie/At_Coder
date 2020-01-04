#include <bits/stdc++.h>
using namespace std;

void fnInput(int& rnPriceA, int& rnPriceB, int& rnPriceH, 
             int& rnNumA,   int& rnNumB)
{
  cin >> rnPriceA >> rnPriceB >> rnPriceH;
  cin >> rnNumA   >> rnNumB;
}

int fnMinCheck(int nPriceA, int nPriceB, int nPriceH, int nNumA, int nNumB)
{
  int nPriceMin;
  if      (nNumA < nNumB)
    nPriceMin = min( nPriceA * nNumA + nPriceB * nNumB,
                     min( (2 * nPriceH - nPriceB) * nNumA + nPriceB * nNumB,
                          2 * nPriceH * nNumB));
  else if (nNumA == nNumB)
    nPriceMin = min( (nPriceA + nPriceB) * nNumA, 2 * nPriceH * nNumA);
  else
    nPriceMin = min( nPriceA * nNumA + nPriceB * nNumB,
                     min( nPriceA * nNumA + (2 * nPriceH - nPriceA) * nNumB,
                          2 * nPriceH * nNumA));
  return nPriceMin;
}

int main()
{
  int nPriceA, nPriceB, nPriceH, nNumA, nNumB;
  
  fnInput(nPriceA, nPriceB, nPriceH, nNumA, nNumB);
  cout << fnMinCheck(nPriceA, nPriceB, nPriceH, nNumA, nNumB) << endl;

  return 0;
}
