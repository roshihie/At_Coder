#include <bits/stdc++.h>
using namespace std;

void fnInput(int64_t& rnNum)
{
  cin >> rnNum;
}

int fnDigitsCheck(int64_t nDivisor)
{
  int nDigitCnt = 0;
  while (nDivisor)
  {
    nDigitCnt++;
    nDivisor /= 10;
  }

  return nDigitCnt;
}

int fnMultiplCheck(int64_t nNum)
{
  int nMinDigit = fnDigitsCheck(nNum);

  for (int64_t n = 2; n * n <= nNum; n++)          // int型 n だとうまく行かない
  {
    if (nNum % n != 0)  continue;
    int64_t nOtr = nNum / n;
    nMinDigit = min(nMinDigit, fnDigitsCheck(nOtr));
  }
  return nMinDigit;
}

int main()
{
  int64_t nNum;
  
  fnInput(nNum);
  cout << fnMultiplCheck(nNum) << endl;

  return 0;
}
