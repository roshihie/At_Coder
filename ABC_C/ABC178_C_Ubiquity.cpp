#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(int& rnSiz)
{
  cin >> rnSiz;
}

llong powmod(int nBase, int nSiz)
{
  const int cnnMod = 1e9 + 7;
  llong nPowMod = 1;

  for (int nx = 0; nx < nSiz; ++nx)
  {
    nPowMod *= nBase;
    nPowMod %= cnnMod;
  }
  return nPowMod;
}

llong calcNumOfCases(int nSiz)
{
  const int cnnMod = 1e9 + 7;

  llong nNumOfCases = powmod(10, nSiz);
  nNumOfCases -= powmod(9, nSiz) * 2 % cnnMod;
  nNumOfCases += powmod(8, nSiz);

  if (nNumOfCases >= 0)
    nNumOfCases %= cnnMod;
  else
    nNumOfCases = (nNumOfCases + cnnMod) % cnnMod;

  return nNumOfCases;
}
  
int main()
{
  int nSiz;

  input(nSiz);
  cout << calcNumOfCases(nSiz) << endl;

  return 0;
}
