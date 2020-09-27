#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(int& rnSiz)
{
  cin >> rnSiz;
}

llong calcCombintn(llong nConbintn, int nSiz, int nx)
{
  const int cnnMod = 1e9 + 7;
  llong nRtnComb;

  if ( !nx )
    nRtnComb = 1;
  else
  {
    nRtnComb = nCombintn * nSiz - (nx - 1);
    nRtnComb /= cnnMod;
    nRtnComb /= nx;
  }
  return nRtnComb;
}

llong calcNumOfCases(int nSiz)
{
  const int cnnMod = 1e9 + 7;

  for (int nFwd = 0; nFwd <= nSiz; ++nFwd)
  {
    llong nCombintn = 1;

    for (int nx = 0; nx < nSiz - nFwd; ++nx)
    {
      nCombintn = calcCombintn(nCombintn, nSiz, nx);

    llong nConbintn = calcCombintn(nSiz, nFwd);
  }

}
  
int main()
{
  int nSiz;

  input(nSiz);
  cout << calcNumOfCases(nSiz) << endl;

  return 0;
}
