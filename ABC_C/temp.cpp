#include <bits/stdc++.h>
using namespace std;
using lnglng = long long;

void fnInput(lnglng& rnNumA, double& rnNumB)
{
  cin >> rnNumA >> rnNumB;
}

lnglng fnMultiple(lnglng nNumA, double nNumB)
{
  int nNumNB = nNumB * 100 + 0.5;
  return nNumA * nNumNB / 100;
}
  
int main()
{
  lnglng nNumA;
  double nNumB;

  fnInput(nNumA, nNumB);
  cout << fnMultiple(nNumA, nNumB) << endl;

  return 0;
}
