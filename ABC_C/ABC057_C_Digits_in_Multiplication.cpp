#include <bits/stdc++.h>
using namespace std;

void fnInput(int64_t& rnNum)
{
  cin >> rnNum;
}

int fnDigitsCheck(int nDividend)
{
  int nDgtCnt = 1;

  while (nDividend /= 10)
    nDgtCnt++;

  return nDgtCnt;
}

int fnMultiplCheck(int64_t nNum)
{
  int nDivisor = sqrt(nNum);

  while (nNum % nDivisor)
    nDivisor--;

  int nDividend = nNum / nDivisor;
  return fnDigitsCheck(nDividend);  
}

int main()
{
  int64_t nNum;
  
  fnInput(nNum);
  cout << fnMultiplCheck(nNum) << endl;

  return 0;
}
