#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(llong& rnNum)
{
  cin >> rnNum;
}

int calcDigits(llong nDividend)
{
  int nDigits = 0;

  while ( nDividend )
  {
    ++nDigits;
    nDividend /= 10;
  }
  return nDigits;
}

int calcMultMinDigt(llong nNum)
{
  int nDivisor = sqrt(nNum);

  while (nNum % nDivisor)
    --nDivisor;

  return calcDigits(nNum / nDivisor);
}

int main()
{
  llong nNum;
  
  input(nNum);
  cout << calcMultMinDigt(nNum) << endl;

  return 0;
}
