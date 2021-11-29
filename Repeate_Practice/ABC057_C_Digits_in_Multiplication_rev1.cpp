#include <bits/stdc++.h>
using namespace std;
using llong = long long;

void fnInput(llong& rnNum)
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

int fnMultiplCheck(llong nNum)
{
  int nDivisor = sqrt(nNum);

  while (nNum % nDivisor)
    nDivisor--;

  int nDividend = nNum / nDivisor;
  return fnDigitsCheck(nDividend);  
}

int main()
{
  llong nNum;
  
  fnInput(nNum);
  cout << fnMultiplCheck(nNum) << endl;

  return 0;
}
