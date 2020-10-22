#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(int& rnNumA, int& rnNumB)
{
  cin >> rnNumA >> rnNumB;
}

int calcGCD(int nOne, int nOtr)
{
  if ( !nOtr ) return nOne;
  return calcGCD(nOtr, nOne % nOtr);
}

llong calcLCM(int nNumA, int nNumB)
{
  int nGCD = calcGCD(nNumA, nNumB);

  int nQuotA = nNumA / nGCD;
  int nQuotB = nNumB / nGCD;
  return (llong)nGCD * nQuotA * nQuotB;
}

int main()
{
  int nNumA, nNumB;

  input(nNumA, nNumB);
  cout << calcLCM(nNumA, nNumB) << endl;

  return 0;
}
