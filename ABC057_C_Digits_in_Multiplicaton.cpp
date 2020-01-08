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
                                           // int型 n では n * n が int型の範囲を
  for (int64_t n = 2; n * n <= nNum; n++)  // 超えて桁落ちが発生し TLE となる
  {                                        
    if (nNum % n != 0)  continue;          // nNum の平方根を超えない整数～nNum
    int64_t nOtr = nNum / n;               // で左記検査を行うと TLE となる
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
