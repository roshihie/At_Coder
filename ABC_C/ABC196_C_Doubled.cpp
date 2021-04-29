#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void input(llong& rnMax)
{
  cin >> rnMax;
}
  
llong calcWholeNum(int n2ndHalf)
{
  llong n1stHalf = n2ndHalf;
  int nDigitChk = n2ndHalf;
  int nDigit = 0;

  while ( nDigitChk )
  {
    ++nDigit;
    nDigitChk /= 10;
  }

  for (int nx = 0; nx < nDigit; ++nx)
    n1stHalf *= 10;

  return n1stHalf + n2ndHalf;
}

int calcSameHalfCnt(llong nMax)
{
  int nSameHalfCnt = 0;
  llong n2ndHalf = 1;

  while ( calcWholeNum(n2ndHalf) <= nMax )
  {
    ++nSameHalfCnt;
    ++n2ndHalf;
  }
  return nSameHalfCnt;
}

int main()
{
  llong nMax;
  input(nMax);
  cout << calcSameHalfCnt(nMax) << endl;

  return 0;
}
