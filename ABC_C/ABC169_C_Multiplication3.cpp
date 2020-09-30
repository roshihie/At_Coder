#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(llong& rnMultplcnd, double& rnMultpler)
{
  cin >> rnMultplcnd >> rnMultpler;
}

llong calcMultiple(llong nMultplcnd, double nMultpler)
{
  int nIntMultpler = nMultpler * 100 + 0.5;
  return nMultplcnd * nIntMultpler / 100;
}
  
int main()
{
  llong nMultplcnd;
  double nMultpler;

  input(nMultplcnd, nMultpler);
  cout << calcMultiple(nMultplcnd, nMultpler) << endl;

  return 0;
}
