#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void fnInput(llong& rnNumA, double& rnNumB)
{
  cin >> rnNumA >> rnNumB;
}

llong fnMultiple(llong nNumA, double nNumB)
{
  int nNumIB = nNumB * 100 + 0.5;
  return nNumA * nNumIB / 100;
}
  
int main()
{
  llong nNumA;
  double nNumB;

  fnInput(nNumA, nNumB);
  cout << fnMultiple(nNumA, nNumB) << endl;

  return 0;
}
