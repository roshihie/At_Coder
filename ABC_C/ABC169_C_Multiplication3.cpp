#include <bits/stdc++.h>
using namespace std;
using lnglng = long long;
using lngdbl = long double;

void fnInput(lnglng& rnNumA, lngdbl& rnNumB)
{
  cin >> rnNumA >> rnNumB;
}

lnglng fnMultiple(lnglng nNumA, lngdbl nNumB)
{
  int nIntB = nNumB * 100 + 0.5;
  return (lnglng)(nNumA * nIntB / 100);
}
  
int main()
{
  lnglng nNumA;
  lngdbl nNumB;

  fnInput(nNumA, nNumB);
  cout << fnMultiple(nNumA, nNumB) << endl;

  return 0;
}
